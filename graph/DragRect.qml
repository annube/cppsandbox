import QtQuick 2.0

Rectangle {
    id: rect
    width: 20; height: 20
    color: "red"
    state: "Normal"
    property color orinalColor

    Component.onCompleted: {
        orinalColor = rect.color
    }

    Drag.active: dragArea.drag.active
    Drag.hotSpot.x: 10
    Drag.hotSpot.y: 10

    MouseArea {
        id: dragArea
        anchors.fill: parent

        drag.target: parent
        onClicked: { rect.state === "Normal" ? rect.state = "Selected" : rect.state = "Normal" }
    }

    states: [
        State{
            name: "Normal"
            PropertyChanges {
                target: rect
                color: orinalColor
            }
        },
        State{
            name: "Selected"
            PropertyChanges {
                target: rect
                color: "red"
            }
        }

    ]
}
