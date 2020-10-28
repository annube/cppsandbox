import QtQuick 2.10
import QtQuick.Window 2.11
import QtQuick.Shapes 1.10

Window {
    width: 400
    height: 300
    visible: true
    title: "Graph"

    Shortcut {
        onActivated: parent.close()
        sequence: StandardKey.Quit
    }

    function randomColor()
    {
        return Qt.rgba(Math.random(), Math.random(), Math.random(), 1.)
    }

    function randomPosition(item) {
        item.x = Math.random()* (1.*item.parent.width);
        item.y = Math.random()* (1.*item.parent.height);
    }

    DragRect {
        id: r1
        x: Math.random() * parent.width
        y: Math.random() * parent.height
        width: 20 + Math.random() * 50
        height: 20 + Math.random() * 50
        orinalColor: randomColor()
    }

    DragRect {
        id: r2
        x: Math.random() * parent.width
        y: Math.random() * parent.height
        width: 20 + Math.random() * 50
        height: 20 + Math.random() * 50
        orinalColor: randomColor()
        onParentChanged: randomPosition(this)
    }


    Connection {
        source: r1
        destination: r2
    }

}
