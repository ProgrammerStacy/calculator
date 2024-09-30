import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
Rectangle
        {
        id: dspl
        width: 360
        height: 156
        color : "#04BFAD"
        radius: 50
        property alias nowN: nowNum.text
        property alias beforeN: beforeNum.text
        Rectangle
        {
            id: clipper
            width: 360
            height: 100
            color : "#04BFAD"
            clip: true
            Rectangle {
                id: clippedleft
                width: parent.width + radius
                height: parent.height + radius
                radius: dspl.radius
                color : "#04BFAD"
                }
        }
        Text {
            id: nowNum
            color: "white"
            font.pixelSize: 36
            anchors.right : parent.right
            anchors.bottom : parent.bottom
            anchors.margins: 35
            text: qsTr("texttt")
        }
        Text {
            id: beforeNum
            font.pixelSize: 24
            color: "white"
            anchors.right : parent.right
            anchors.bottom: nowNum.top
            anchors.rightMargin: 35
            text: qsTr("texttt")
        }
    
    
    
    }
