
find_package( Boost 1.66 REQUIRED system filesystem)

add_executable(nlmoncpp nl_endpoint.h nl_protocol.h nlmoncpp.cpp netlink_suppl.h netlink_suppl.cpp)
