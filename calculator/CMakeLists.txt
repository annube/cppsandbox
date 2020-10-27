add_executable(calculator calculator.cpp calculator.qrc)
target_link_libraries(calculator Qt5::Qml Qt5::Quick Qt5::QuickTest)
target_compile_definitions(calculator PRIVATE QT_DECLARATIVE_DEBUG QT_QML_DEBUG)
