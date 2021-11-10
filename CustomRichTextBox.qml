import QtQuick 2.12

Rectangle {
    id : control
    property string defaultText:  ""
    property string linetextColor : ""
    anchors.top: textinputboxM.bottom
    width:  parent.width / 2
    height:  lineHeight * 2
    color: "grey"

    Rectangle{
        id : tips
        Text {
            text: defaultText
            font.pointSize:  20
        }
        width:parent.width
    }
    visible: false
    Column{
        id : resultBox
        Repeater{
            id : repeater
            CustomTextBox{
                height: lineHeight
                width: parent.width
                customText : modelData
                y: index * lineHeight
                textColor :  linetextColor
            }
        }
        anchors.fill: parent
        visible: false
    }



    function show (){
        control.visible = true
        animation.running = true
    }
    function showText(result){
        control.height = result.length * lineHeight
        tips.visible = false
        resultBox.visible = true
        repeater.model = result
    }

    OpacityAnimator{
        target:  control
        id : animation
        from: 0;
        to : 1;
        duration:  3000
    }
}
