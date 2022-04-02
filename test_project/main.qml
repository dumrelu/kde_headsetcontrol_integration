import QtQuick 2.12
import QtQuick.Window 2.12
import kde_headsetcontrol_integration 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    TestType {

    }

    HeadsetControl {
        id: headsetControl
    }

    Text {
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        text: headsetControl.testMessage
    }
}
