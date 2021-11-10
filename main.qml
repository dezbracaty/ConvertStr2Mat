import QtQuick 2.14
import QtQuick.Window 2.14

Window {
    visible: true
    width: 640 * 1.9
    height: 480 *1.5
    title: qsTr("Convert String To Matrix")
    property int lineHeight: 40
    TextinputBox{
        id : textinputboxM
        onTextinput: {
            customrichtextbox.show()
            customrichtextboxright.show()
        }
    }
    MyCvtTool{
        id: cvtTool
        onCppGetQQuanResult : {
            customrichtextbox.showText(result)
            customrichtextbox.linetextColor  = "pink"
        }
        onCppGetPossResult: {
            customrichtextboxright.showText(result)
            customrichtextboxright.linetextColor = "blue"
        }
    }

    CustomRichTextBox{
        id:customrichtextbox
        defaultText:  "Mat will show here"
    }
    CustomRichTextBox{
        id:customrichtextboxright
        anchors.left: customrichtextbox.right
        defaultText:  "Position will show here"
    }
}
