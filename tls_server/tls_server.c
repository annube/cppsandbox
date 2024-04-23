#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define max(a,b) \
({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })


#define min(a,b) \
({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

int create_socket(int port)
{
    int s;
    struct sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0) {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    if (bind(s, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("Unable to bind");
        exit(EXIT_FAILURE);
    }

    if (listen(s, 1) < 0) {
        perror("Unable to listen");
        exit(EXIT_FAILURE);
    }

    return s;
}

SSL_CTX *create_ssl_server_context()
{
    const SSL_METHOD *method;
    SSL_CTX *ctx;

    method = TLS_server_method();

    ctx = SSL_CTX_new(method);
    if (!ctx) {
        perror("Unable to create SSL context");
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    return ctx;
}

typedef struct _ssl_server_config
{
    char server_certificate[1024];
    char server_key[1024];
} ssl_server_config;

typedef struct _ssl_server_context
{
    SSL_CTX* ssl_ctx;
    ssl_server_config* cfg;
    int socketFD;
} ssl_server_context;

typedef struct _tls_context
{

    SSL *ssl;
    int clientFD;
    struct sockaddr_in addr;
    ssl_server_context* server_ctx;

} ssl_client_connection;


void init_context(ssl_server_context* ssl_server_ctx, ssl_server_config* sslConfig)
{

    ssl_server_ctx->ssl_ctx = create_ssl_server_context();

    ssl_server_ctx->cfg=sslConfig;

    /* Set the key and cert */
    if (SSL_CTX_use_certificate_file(ssl_server_ctx->ssl_ctx, sslConfig->server_certificate, SSL_FILETYPE_PEM) <= 0) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    if (SSL_CTX_use_PrivateKey_file(ssl_server_ctx->ssl_ctx,  sslConfig->server_key, SSL_FILETYPE_PEM) <= 0 ) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
}

int parse_ssl_config(int argc, char* argv[], ssl_server_config* sslConfig)
{
   if(argc < 3){
       return -1;
   }
    memset(sslConfig, '\0', sizeof(sslConfig));
    strcpy(sslConfig->server_key, argv[1]);
    strcpy(sslConfig->server_certificate, argv[2]);
    return 0;
}


int nextClientRequest(ssl_server_context* ssl_server_ctx, ssl_client_connection* client_conn)
{
    unsigned int len = sizeof(struct sockaddr_in);
    client_conn->clientFD = accept(ssl_server_ctx->socketFD, (struct sockaddr*)&client_conn->addr, &len);
    if (client_conn->clientFD < 0) {
        perror("Unable to accept");
        exit(EXIT_FAILURE);
    }

    client_conn->ssl = SSL_new(ssl_server_ctx->ssl_ctx);

    SSL_set_accept_state(client_conn->ssl); // Server
    SSL_set_fd(client_conn->ssl, client_conn->clientFD);
    client_conn->server_ctx = ssl_server_ctx;
    return 0;
}

int finishClientRequest(ssl_client_connection* client_conn)
{

    SSL_shutdown(client_conn->ssl);
    SSL_free(client_conn->ssl);
    close(client_conn->clientFD);
}

int main(int argc, char **argv)
{

    if(argc < 3)
    {
        fprintf(stderr, "%s <server_cert> <server_key>\n", argv[0]);
        return -1;
    }

    ssl_server_config sslConfig;

    parse_ssl_config(argc, argv, &sslConfig);

    int sock;
    ssl_server_context ssl_server_ctx;

    /* Ignore broken pipe signals */
    signal(SIGPIPE, SIG_IGN);

    init_context(&ssl_server_ctx, &sslConfig);

    ssl_server_ctx.socketFD = create_socket(4433);

    /* Handle connections */
    while(1) {

        ssl_client_connection client_conn;

        nextClientRequest(&ssl_server_ctx, &client_conn);

        if (SSL_do_handshake(client_conn.ssl) <= 0) {
            ERR_print_errors_fp(stderr);
        } else {
            printf("SSL Handshake accepted\n");
            char buf[1024];
            int numBytesRead = SSL_read(client_conn.ssl, buf, 1024);
            printf("bytes read %d\n", numBytesRead);
            SSL_write(client_conn.ssl, buf, min(strlen(buf),numBytesRead));
        }

        finishClientRequest(&client_conn);

    }

    close(sock);
    SSL_CTX_free(ssl_server_ctx.ssl_ctx);
}
