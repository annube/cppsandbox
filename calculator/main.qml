import QtQuick 2.0
import QtQuick.Window 2.11

Window {
    width: 200
    height: 400
    visible: true
    title: "Calculator"

    Calculator{
        anchors.fill: parent
    }
}
