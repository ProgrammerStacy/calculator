import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
GridLayout{
                id: grid
                columns: 4
                columnSpacing: 18
                rowSpacing: 18
                Layout.leftMargin: 30
                Layout.topMargin: 30
                NumBttn
                {
                    buttonText: qsTr("()")
                    buttonIcon: "img/bkt.png"
                }
                NumBttn
                {
                    buttonText: qsTr("+/-")
                    buttonIcon: "img/plus_minus.png"
                }
                NumBttn
                {
                    buttonText: qsTr("%")
                    buttonIcon: "img/percent.png"
                }
                NumBttn
                {
                    buttonText: qsTr("/")
                    buttonIcon: "img/division.png"
                }
    
                NumBttn {
                    buttonText: qsTr("7")
                }
                NumBttn {
                    buttonText: qsTr("8")
                }
                NumBttn {
                    buttonText: qsTr("9")
                }
                NumBttn
                {
                    buttonText: qsTr("x")
                    buttonIcon: "img/multiplication.png"
                }
    
                NumBttn {
                    buttonText: qsTr("4")
                }
                NumBttn {
                    buttonText: qsTr("5")
                }
                NumBttn {
                    buttonText: qsTr("6")
                }
                NumBttn
                {
                    buttonText: qsTr("-")
                    buttonIcon: "img/minus.png"
                }
    
                NumBttn {
                    buttonText: qsTr("1")
                }
                NumBttn {
                    buttonText: qsTr("2")
                }
                NumBttn {
                    buttonText: qsTr("3")
                }
                NumBttn
                {
                    buttonText: qsTr("+")
                    buttonIcon: "img/plus.png"
                }
    
                NumBttn
                {
                    buttonText: qsTr("C")
                }
                NumBttn
                {
                    buttonText: qsTr("0")
                }
                NumBttn
                {
                    buttonText: qsTr(".")
                }
                NumBttn
                {
                    buttonText: qsTr("=")
                    buttonIcon: "img/equal.png"
                }
            }
