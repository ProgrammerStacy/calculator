import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Window {
    id : win
    width: 360
    height: 640
    visible: true
    title: qsTr("Calculator")
    color: "#024873"

    ColumnLayout
    {
        id : layoutFirst
        spacing: 30
        Display {
            id: display
        }
        Keypad {
            id: grid
        }
    }
    Dialog {
        id: dialog
        modal: true
        anchors.centerIn: parent
        title: "Секретное меню!"
        Button
        {
            id: back
            text: "Назад"
            anchors.centerIn: parent
            onClicked:
            {
                dialog.close();
            }
        }
    }
    Connections
    {
        target: processCalculating
        onSecretMenuActive:
        {
            dialog.open();
        }
    }




}

