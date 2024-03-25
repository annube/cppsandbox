add_executable(tls_server tls_server.c)

find_package(OpenSSL)

target_link_libraries(tls_server PRIVATE OpenSSL::SSL OpenSSL::Crypto) 
