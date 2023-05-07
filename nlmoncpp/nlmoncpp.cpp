#include <linux/netlink.h>
#include <linux/rtnetlink.h>
#include "nl_protocol.h"
#include <boost/asio/io_context.hpp>
#include <boost/asio/io_service.hpp>
#include <sys/socket.h>
#include <iostream>
#include <net/if.h>

void handle_netlink(struct nlmsghdr *nlm);

#define max_length 4096

int main(int argc, char* argv[])
{
    try
    {
        boost::asio::io_service io_service;
        boost::asio::basic_raw_socket<nl_protocol> s(io_service );

        s.open(nl_protocol(NETLINK_ROUTE));
        s.bind(nl_endpoint<nl_protocol>(RTMGRP_LINK));

        char buffer[max_length];
        int bytes;

        while((bytes=s.receive(boost::asio::buffer(buffer, max_length)))) {
             struct nlmsghdr *nlm;

            for (nlm = (struct nlmsghdr *)buffer;
              NLMSG_OK(nlm, (size_t)bytes);
              nlm = NLMSG_NEXT(nlm, bytes))
            {
            handle_netlink(nlm);
            }
        }
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return 0;
}

/* This code just prints out what interface went up or down */
void handle_netlink(struct nlmsghdr *nlm) {
    int len;
    char ifname[IF_NAMESIZE + 1];
    ifinfomsg *ifi;
    rtattr *rta;

    if (nlm->nlmsg_type == RTM_NEWLINK) {
        len = nlm->nlmsg_len - sizeof(*nlm);
        if ((size_t)len < sizeof(*ifi)) {
            errno = EBADMSG;
            return;
        }
        ifi = (ifinfomsg*)NLMSG_DATA(nlm);
        if (ifi->ifi_flags & IFF_LOOPBACK)
            return;

        rta = (rtattr *) ((char *)ifi + NLMSG_ALIGN(sizeof(*ifi)));
        len = NLMSG_PAYLOAD(nlm, sizeof(*ifi));
        ifname[0] = '\0';
        while (RTA_OK(rta, len)) {
            switch (rta->rta_type) {
                case IFLA_IFNAME:
                strncpy(ifname, (char*)RTA_DATA(rta), sizeof(ifname));
                break;
                default:
                    break;
            }
            rta = RTA_NEXT(rta, len);
        }
    }
    if (nlm->nlmsg_type == RTM_NEWLINK)
        len = ifi->ifi_change == ~0U ? 1 : 0;

    std::cout << "Interface " << ifname << " changed status, now: ";
    if(ifi->ifi_flags&IFF_RUNNING)
        std::cout << " Up" << std::endl;
    else
        std::cout << " Down" << std::endl;
}
