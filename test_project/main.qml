import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
import kde_headsetcontrol_integration 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    HeadsetControl {
        id: headsetControl
    }

    BatteryDebug {
        anchors.centerIn: parent
        batteryInfo: headsetControl.batteryInfo
    }

    BusyIndicator {
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.rightMargin: 5
    }
}
