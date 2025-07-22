import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {
    title: "设置"
    
    MockStorageManager {
        id: mockStorageManager
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 16
        spacing: 20

        Label {
            text: "设置"
            font.pixelSize: 22
            font.weight: Font.Bold
            Layout.alignment: Qt.AlignHCenter
        }

        GridLayout {
            columns: 2
            columnSpacing: 8
            rowSpacing: 8

            Label { text: "录音质量:" }
            ComboBox {
                model: ["高", "中", "低"]
                currentIndex: mockStorageManager.recordingQuality
                onCurrentIndexChanged: mockStorageManager.recordingQuality = currentIndex
            }

            Label { text: "录音格式:" }
            ComboBox {
                model: ["WAV"]
                currentIndex: 0
                onCurrentIndexChanged: mockStorageManager.recordingFormat = model[currentIndex]
            }

            Label { text: "最大录音时长(秒):" }
            SpinBox {
                value: mockStorageManager.maxRecordingDuration
                from: 60; to: 7200; stepSize: 60
                onValueChanged: mockStorageManager.maxRecordingDuration = value
            }

            Label { text: "自动保存:" }
            Switch {
                checked: mockStorageManager.autoSave
                onCheckedChanged: mockStorageManager.autoSave = checked
            }
        }

        Button {
            text: "保存设置"
            onClicked: mockStorageManager.saveConfig()
            Layout.alignment: Qt.AlignHCenter
        }
    }
}