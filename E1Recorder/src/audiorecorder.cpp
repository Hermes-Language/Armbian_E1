#include "audiorecorder.h"
#include <QAudioDevice>
#include <QMediaDevices>
#include <QStandardPaths>
#include <QDir>

AudioRecorder::AudioRecorder(QObject *parent)
    : QObject(parent)
    , m_audioInput(this)
    , m_mediaRecorder(this)
{
    // 设置音频输入设备
    m_captureSession.setAudioInput(&m_audioInput);
    m_captureSession.setRecorder(&m_mediaRecorder);
}

AudioRecorder::~AudioRecorder()
{
    if (m_recording) {
        stop();
    }
}

void AudioRecorder::start(const QString &fileName)
{
    if (m_recording) {
        return;
    }

    // 检查音频输入设备
    const auto &availableInputs = QMediaDevices::audioInputs();
    if (availableInputs.isEmpty()) {
        // No audio input devices found
        return;
    }

    // 设置音频输入设备
    m_audioInput.setDevice(availableInputs.first());
    
    // 设置输出文件
    m_mediaRecorder.setOutputLocation(QUrl::fromLocalFile(fileName));
    m_mediaRecorder.setQuality(QMediaRecorder::NormalQuality);
    
    // 开始录音
    m_mediaRecorder.record();

    m_recording = true;
    emit recordingChanged();
}

void AudioRecorder::stop()
{
    if (!m_recording) {
        return;
    }

    m_mediaRecorder.stop();
    m_recording = false;
    emit recordingChanged();
}

bool AudioRecorder::isRecording() const
{
    return m_recording;
}