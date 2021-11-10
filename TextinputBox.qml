import QtQuick 2.14
import QtQuick.Window 2.14


Rectangle{
    id : textinputbox
    width : parent.width
    height: lineHeight  * 2
    state : "NotInput"
    Rectangle{
        id: tip
        width: parent.width
        Item {
            id: tipstr
            Text {
                id : text1
                text: qsTr("Input Matrix with @@ spilit")
                font.pointSize: 20
                color: textinputbox.state === "NotInput" ? "grey" : "black"
            }
        }
        x : parent.width / 10 * 2
        y : lineHeight
        visible:  true

    }
    Rectangle{
        id : spacebar
        width : parent.width
        height: 2
        anchors.bottom: parent.bottom
        color: "grey"
        visible: true
    }

    TextInput{
        id : textEdit
        width: parent.width
        font.pointSize: 20
        anchors.left: parent.left
        selectByMouse:  true
        mouseSelectionMode: TextInput.SelectCharacters
        selectionColor: "yellow"
        visible: false
        anchors.bottom: parent.bottom
        onEditingFinished: {
            var recv = cvtTool.cvtStrToMats(text);
            console.log("textEdit onEditingFinished: ",recv)

        }
        onTextEdited: {
        }
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            changeState()
        }
    }

    function changeState(  ) {
        if (state === "NotInput"){
            console.log("Not input State to Input State ")
            textinputbox.state = "InputState"
            animation.to  = -lineHeight
            animation.running = true
            textinput();

        }else{
            textEdit.focus = true
        }
    }

    PropertyAnimation{
                    id:animation
                    target:tipstr
                    properties: "y"
                    duration: 200
                }
    states: [
        State {
            name: "NotInput"
            PropertyChanges {
                target: tipstr
                visible : true ;
            }
        },
        State {
            name: "InputState"
            PropertyChanges {
                target: textEdit
                visible : true
                focus: true
            }


        }
    ]
//    onStateChanged: {
//        if( state === "InputState" )
//        {
//            spacebar.color = "red"
//        }

//    }
    signal textinput;
}

