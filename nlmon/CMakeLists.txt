find_library(NF_LIB nfnetlink)
find_path(NF_INCLUDE libnfnetlink.h PATH_SUFFIXES libnfnetlink)

if (NF_LIB AND NF_INCLUDE)
    message ("found libnfnetlink " ${NF_LIB} " " ${NF_INCLUDE} )
    add_executable(nlmon nlmon.cpp)
    target_link_libraries(nlmon ${NF_LIB})
    target_include_directories(nlmon PRIVATE ${NF_INCLUDE})
endif()
