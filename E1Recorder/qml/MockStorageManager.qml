import QtQuick

QtObject {
    id: mockStorageManager
    
    // Properties
    property string recordingsPath: "/home/user/recordings"
    property int availableSpace: 1024
    property int usedSpace: 256
    property int recordingQuality: 1
    property string recordingFormat: "WAV"
    property bool autoSave: true
    property int maxRecordingDuration: 3600
    
    // Mock methods
    function getStorageUsagePercentage() {
        return 25  // 25% 使用率
    }
    
    function getRecordingsList() {
        return ["录音_20240720_143000.wav", "录音_20240720_143500.wav", "测试录音.wav"]
    }
    
    function deleteRecording(fileName) {
        console.log("删除录音:", fileName)
    }
    
    function exportRecording(fileName) {
        console.log("导出录音:", fileName)
    }
    
    function saveConfig() {
        console.log("保存配置")
    }
    
    function loadConfig() {
        console.log("加载配置")
    }
} 