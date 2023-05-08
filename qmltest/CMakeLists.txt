project(qmltest1)
add_executable(qmltest1
    qmltest1.cpp
    resources.qrc
)

foreach(TEST_QML_FILE Test1.qml)
configure_file(${TEST_QML_FILE} ${CMAKE_CURRENT_BINARY_DIR}/tst_${TEST_QML_FILE} COPYONLY)
endforeach()
target_link_libraries(qmltest1 Qt5::Qml Qt5::Quick Qt5::QuickTest)
