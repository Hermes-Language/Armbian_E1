import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Frame {
    width: parent ? parent.width : 300
    padding: 16

    property string fileName
    signal deleteClicked(string fileName)
    signal exportClicked(string fileName)

    RowLayout {
        width: parent.width

        Label {
            text: fileName
            elide: Text.ElideRight
            Layout.fillWidth: true
        }

        Button {
            text: "删除"
            onClicked: deleteClicked(fileName)
            flat: true
        }

        Button {
            text: "导出"
            onClicked: exportClicked(fileName)
            flat: true
        }
    }
}