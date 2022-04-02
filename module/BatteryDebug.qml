import QtQuick 2.15

// Simple type to visualize battery info
Item {
    id: root

    implicitWidth: listView.contentWidth
    implicitHeight: listView.contentHeight

    property var batteryInfo

    ListModel {
        id: propertyModel
        ListElement {
            propName: "Pretty Name"
        }
    }

    ListView {
        id: listView

        anchors.fill: parent

        model: Object.keys(batteryInfo)

        delegate: Text {
            text: `${modelData}: ${batteryInfo[modelData]}`

            visible: !modelData.startsWith("_") && !modelData.endsWith("Changed") && !["keys", "objectName"].includes(modelData)
            height: visible ? implicitHeight : 0
        }
    }
}
