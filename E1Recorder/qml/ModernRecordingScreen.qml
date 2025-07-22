import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {
    title: "录音"
    
    MockStorageManager {
        id: mockStorageManager
    }
    
    MockAudioRecorder {
        id: mockRecorder
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 16
        spacing: 24

        Label {
            text: "录音"
            font.pixelSize: 28
            font.weight: Font.Bold
            Layout.alignment: Qt.AlignHCenter
        }

        CircularProgress {
            value: mockStorageManager.getStorageUsagePercentage() / 100
            Layout.alignment: Qt.AlignHCenter
        }

        Label {
            text: "可用空间: " + mockStorageManager.availableSpace + " MB"
            Layout.alignment: Qt.AlignHCenter
        }

        Label {
            text: mockRecorder.recording ? "正在录音..." : "未录音"
            color: mockRecorder.recording ? "#4caf50" : "#757575"
            Layout.alignment: Qt.AlignHCenter
        }

        Button {
            text: mockRecorder.recording ? "停止录音" : "开始录音"
            onClicked: {
                if (mockRecorder.recording) {
                    mockRecorder.stop()
                } else {
                    mockRecorder.start(mockStorageManager.recordingsPath + "/" + Qt.formatDateTime(new Date(), "yyyyMMdd_hhmmss") + ".wav")
                }
            }
            Layout.alignment: Qt.AlignHCenter
        }
    }
}