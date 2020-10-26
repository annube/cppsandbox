import QtQuick 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.6

Item {
    width: 400
    height: 400
    property alias stackLayout: stackLayout

    GridLayout {
        id: gridLayout
        columns: 4
        anchors.fill: parent

        TextField {
            id: textField
            Layout.fillHeight: true
            Layout.columnSpan: 4
            Layout.fillWidth: true
            placeholderText: qsTr("Text Field")
        }

        Button {
            id: button
            text: qsTr("%")
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Button {
            id: button1
            text: qsTr("CE")
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Button {
            id: button2
            text: qsTr("C")
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Button {
            id: button3
            text: qsTr("⌫")
            Layout.rowSpan: 1
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Button {
            id: button4
            text: qsTr("1/x")
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Button {
            id: button5
            text: qsTr("x²")
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Button {
            id: button6
            text: qsTr("√")
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Button {
            id: button7
            text: qsTr("÷")
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Button {
            id: button8
            text: qsTr("7")
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Button {
            id: button9
            text: qsTr("8")
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Button {
            id: button10
            text: qsTr("9")
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Button {
            id: button11
            text: qsTr("×")
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Button {
            id: button12
            text: qsTr("4")
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Button {
            id: button13
            text: qsTr("5")
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Button {
            id: button14
            text: qsTr("6")
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Button {
            id: button15
            text: qsTr("-")
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Button {
            id: button16
            text: qsTr("1")
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Button {
            id: button17
            text: qsTr("2")
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Button {
            id: button18
            text: qsTr("3")
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Button {
            id: button19
            text: qsTr("+")
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Button {
            id: button20
            text: qsTr("±")
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Button {
            id: button21
            text: qsTr("0")
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Button {
            id: button22
            text: qsTr(",")
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Button {
            id: button23
            text: qsTr("=")
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        SpinBox {
            id: spinBox
        }

        StackLayout {
            id: stackLayout
            width: 100
            height: 100
        }
    }
}
