import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material

ApplicationWindow {
    id: window
    visible: true
    width: 320
    height: 320
    title: "E1录音笔"

    Material.theme: Material.Dark
    Material.accent: Material.Purple

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: ModernRecordingScreen {}
    }

    footer: TabBar {
        id: tabBar
        currentIndex: 0

        TabButton {
            text: "录音"
        }
        TabButton {
            text: "文件"
        }
        TabButton {
            text: "设置"
        }
    }

    Component.onCompleted: {
        // 预定义页面组件
        stackView.push("ModernRecordingScreen.qml")
    }

    // 处理标签切换
    property var pageComponents: [
        "ModernRecordingScreen.qml",
        "FileListScreen.qml", 
        "DeviceSettingsScenarioPage.qml"
    ]

    Connections {
        target: tabBar
        function onCurrentIndexChanged() {
            if (tabBar.currentIndex >= 0 && tabBar.currentIndex < pageComponents.length) {
                stackView.replace(pageComponents[tabBar.currentIndex])
            }
        }
    }
}