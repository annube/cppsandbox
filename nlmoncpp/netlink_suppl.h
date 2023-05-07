#ifndef NETLINK_SUPPL_H
#define NETLINK_SUPPL_H

#include <linux/netlink.h>

bool operator == (sockaddr_nl const& sockaddr1, sockaddr_nl const& sockaddr2);

bool operator < (sockaddr_nl const& sockaddr1, sockaddr_nl const& sockaddr2);

#endif // NETLINK_SUPPL_H
