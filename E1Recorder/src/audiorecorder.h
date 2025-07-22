#pragma once

#include <QObject>
#include <QMediaCaptureSession>
#include <QAudioInput>
#include <QMediaRecorder>
#include <QUrl>

class AudioRecorder : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool recording READ isRecording NOTIFY recordingChanged)

public:
    explicit AudioRecorder(QObject *parent = nullptr);
    ~AudioRecorder();

    Q_INVOKABLE void start(const QString &fileName);
    Q_INVOKABLE void stop();

    bool isRecording() const;

signals:
    void recordingChanged();

private:
    QMediaCaptureSession m_captureSession;
    QAudioInput m_audioInput;
    QMediaRecorder m_mediaRecorder;
    bool m_recording = false;
};