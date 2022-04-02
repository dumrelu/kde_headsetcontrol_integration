import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        anchors.fill: parent
        color: "red"
        
        Text {
            anchors.centerIn: parent
            text: "Hello World!"
        }
    }
}
