import QtQuick.Shapes 1.10
import QtQuick 2.10

Shape{
    property var source
    property var destination
ShapePath {
    strokeColor: "black"
    strokeWidth: 2
    fillColor: "transparent"
    capStyle: ShapePath.RoundCap

    startX: r1.x + 0.5 * r1.width
    startY: r1.y + 0.5 * r1.height
    PathLine{
    x: r2.x + 0.5 * r2.width
    y: r2.y + 0.5 * r2.height
    }
}
}
