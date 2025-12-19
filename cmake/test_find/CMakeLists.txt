cmake_minimum_required(VERSION 3.30)
project(test_find)

find_package(nlohmann_json QUIET)

if(NLOHMANN_JSON_FOUND)
 message("Found nl_json")
endif()
