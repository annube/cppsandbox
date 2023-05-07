#ifndef NL_PROTOCOL
#define NL_PROTOCOL

#include <sys/socket.h>
#include "nl_endpoint.h"
#include <boost/asio/basic_raw_socket.hpp>

class nl_protocol
{
private:
    int proto;
public:
    nl_protocol() {
        proto = 0;
    }
    nl_protocol(int proto) {
        this->proto = proto;
    }
    /// Obtain an identifier for the type of the protocol.
    int type() const
    {
        return SOCK_RAW;
    }
    /// Obtain an identifier for the protocol.
    int protocol() const
    {
        return proto;
    }
    /// Obtain an identifier for the protocol family.
    int family() const
    {
        return PF_NETLINK;
    }

    typedef nl_endpoint<nl_protocol> endpoint;
    typedef boost::asio::basic_raw_socket<nl_protocol> socket;
};

#endif // def NL_PROTOCOL
