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

    startX: source.x + 0.5 * source.width
    startY: source.y + 0.5 * source.height
    PathLine{
    x: destination.x + 0.5 * destination.width
    y: destination.y + 0.5 * destination.height
    }
}
}
