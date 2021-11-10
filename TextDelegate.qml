import QtQuick 2.0

Rectangle{
    id: control
    color: "red"
    property string newText : ""

    Text {
        anchors.fill: parent
        text: newText
    }
    MouseArea{
        anchors.fill: parent
        onPressed: {
            control.color = "blue"
        }
        onReleased: {
            control.color = "red"
        }

        onClicked: {
            clipBoardHelper.copyText("  ")
        }
    }
}
