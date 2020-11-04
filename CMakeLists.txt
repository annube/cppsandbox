cmake_minimum_required(VERSION 3.1.0)

project(cppsandox)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Qml Quick QuickTest REQUIRED)
find_package(Boost 1.66 REQUIRED COMPONENTS system)

add_executable(qmltest1
    qmltest1.cpp
    resources.qrc
)

foreach(TEST_QML_FILE Test1.qml)
configure_file(${TEST_QML_FILE} ${CMAKE_CURRENT_BINARY_DIR}/tst_${TEST_QML_FILE} COPYONLY)
endforeach()
target_link_libraries(qmltest1 Qt5::Qml Qt5::Quick Qt5::QuickTest)
add_subdirectory(./calculator)
add_subdirectory(./graph)
add_subdirectory(./graph_parse)
