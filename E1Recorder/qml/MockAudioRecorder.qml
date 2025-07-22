import QtQuick

QtObject {
    id: mockAudioRecorder
    
    // Properties
    property bool recording: false
    
    // Mock methods
    function start(fileName) {
        console.log("开始录音:", fileName)
        recording = true
    }
    
    function stop() {
        console.log("停止录音")
        recording = false
    }
    
    function isRecording() {
        return recording
    }
} 