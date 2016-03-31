import QtQuick 2.0
import compositor 1.0

Rectangle {
    width: 1024
    height: 600
    color: "#acefff"

    Rectangle {
        id: button1
        width: 480
        height: 100
        anchors {
            top: parent.top
            topMargin: 20
            leftMargin: 20
            left: parent.left
        }
        Text {
            width: 480
            height: 100
            text: "App1"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                parent.color = "blue"
                SampleCompositor.startApp("gles2-gears")
            }
        }
    }
    Rectangle {
        id: button2
        width: 480
        height: 100
        anchors {
            top: parent.top
            topMargin: 20
            rightMargin: 20
            right: parent.right
        }
        Text {
            width: 480
            height: 100
            text: "App2"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }
}
