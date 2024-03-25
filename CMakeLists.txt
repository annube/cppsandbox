cmake_minimum_required(VERSION 3.1.0)

project(cppsandox)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Qml Quick QuickTest REQUIRED)
find_package(Boost 1.66 REQUIRED COMPONENTS system)

include_directories(${Boost_INCLUDE_DIRS})

add_subdirectory(./graph)
add_subdirectory(nlmon)
add_subdirectory(nlmoncpp)
add_subdirectory(qmltest)
add_subdirectory(boost_parser/)
add_subdirectory(sizeof)
add_subdirectory(vfnptr/)
add_subdirectory(tls_server)

