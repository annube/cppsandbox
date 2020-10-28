add_executable(graph graph.cpp graph.qrc)
target_link_libraries(graph Qt5::Qml Qt5::Quick Qt5::QuickTest)
target_compile_definitions(graph PRIVATE QT_DECLARATIVE_DEBUG QT_QML_DEBUG)
