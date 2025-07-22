import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {
    title: "文件列表"
    
    MockStorageManager {
        id: mockStorageManager
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 16
        spacing: 12

        Label {
            text: "录音文件列表"
            font.pixelSize: 22
            font.weight: Font.Bold
            Layout.alignment: Qt.AlignHCenter
        }

        ListView {
            id: fileList
            Layout.fillWidth: true
            Layout.fillHeight: true
            model: mockStorageManager.getRecordingsList()
            delegate: FileListItem {
                fileName: modelData
                onDeleteClicked: mockStorageManager.deleteRecording(modelData)
                onExportClicked: mockStorageManager.exportRecording(modelData)
            }
        }
    }
}