#pragma once
#include <QObject>

class Recorder : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool recording READ isRecording NOTIFY recordingChanged)
public:
    explicit Recorder(QObject *parent = nullptr);
    Q_INVOKABLE void start(const QString &filename);
    Q_INVOKABLE void stop();
    bool isRecording() const;

signals:
    void recordingChanged();

private:
    bool m_recording = false;
    pid_t m_pid = -1;
}; 