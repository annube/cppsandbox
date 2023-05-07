#include "netlink_suppl.h"


#include <boost/fusion/adapted/struct.hpp>
#include <boost/fusion/sequence/comparison.hpp>

struct NL_FAMILY;
struct NL_GROUPS;
struct NL_PID;

BOOST_FUSION_ADAPT_ASSOC_STRUCT(
    sockaddr_nl
    ,
    (nl_family, NL_FAMILY)
    (nl_groups, NL_GROUPS)
    (nl_pid, NL_PID)
);

bool operator == (sockaddr_nl const& sockaddr1, sockaddr_nl const& sockaddr2)
{
  return boost::fusion::operator==(sockaddr1, sockaddr2);
}

bool operator < (sockaddr_nl const& sockaddr1, sockaddr_nl const& sockaddr2){
  return boost::fusion::operator<(sockaddr1, sockaddr2);
}
