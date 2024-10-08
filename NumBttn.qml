import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item  {
        id: bttn
        width: 60
        height: 60
        property alias buttonText : t.text
        property alias buttonIcon : img.source
        signal clicked(string text)

        Rectangle
            {
                    id: base
                    anchors.fill: parent
                    radius: parent.height / 2
                    Text {
                        id: t
                        text: qsTr("T")
                        anchors.centerIn: parent
                        font.pixelSize: 24
                        font.family: "Open Sans Semibold"
                    }
                    Image {
                        id: img
                        anchors.centerIn: parent
                    }
                    color: if (t.text == "1" ||
                                t.text == "2" || t.text == "3" || t.text == "4" ||
                                t.text == "5" || t.text == "6" || t.text == "7" || t.text == "8" ||
                                t.text == "9" || t.text == "0"|| t.text == ".")
                            {
                               t.color = "#024873";
                               return mouseArea.containsPress ? "#04BFAD" : "#B0D1D8"
                            }
                            else if (t.text == "C")
                            {
                               t.color = "white";
                               return mouseArea.containsPress ? "#F25E5E" : "#F8AEAE";
                            }
                            else
                            {
                               t.color = "transparent";
                               return mouseArea.containsPress ? "#F7E425" : "#0889A6";
                            }
    
                    MouseArea
                    {
                        id: mouseArea
                        anchors.fill: parent
                        pressAndHoldInterval: 4000
                        onClicked:
                        {
                            processCalculating.receiveFromQml(t.text);
                        }
                        onPressAndHold:
                        {
                            processCalculating.itIsSecret(t.text);
                        }
                    }
            }


    
        
}
