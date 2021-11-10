import QtQuick 2.0

Rectangle {
    id:sbox
    property string customText: "value"
    property string textColor: ""
    width:  parent.width
    TextEdit{
        anchors.fill :parent
        id : customtextedit
        width: parent.width
        readOnly: true
        font.pointSize: 22
        text: customText
        color: textColor
    }
    MouseArea{
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton ;
        onClicked: {
            if( mouse.button === Qt.RightButton ){
                customtextedit.selectAll()
                console.log("customtextedit.selectedText" , customtextedit.selectedText)
                customtextedit.copy();
                diselectTimer.start()
            }

        }
    }

    Timer {
        id:diselectTimer
        interval: 500;
        running: false
        onTriggered: {
            customtextedit.deselect()
            customtextedit.color = "#b0e0e6"
            sbox.border.color = "#4682b4"
        }
    }


}
