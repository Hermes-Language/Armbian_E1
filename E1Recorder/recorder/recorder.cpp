#include "recorder.h"
#include <QProcess>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

Recorder::Recorder(QObject *parent) : QObject(parent) {}

void Recorder::start(const QString &filename) {
    if (m_recording) return;
    m_pid = fork();
    if (m_pid == 0) {
        execlp("arecord", "arecord", "-D", "hw:0,0", "-f", "cd", "-t", "wav", filename.toUtf8().constData(), nullptr);
        _exit(1);
    }
    m_recording = true;
    emit recordingChanged();
}

void Recorder::stop() {
    if (!m_recording || m_pid <= 0) return;
    kill(m_pid, SIGINT);
    m_pid = -1;
    m_recording = false;
    emit recordingChanged();
}

bool Recorder::isRecording() const {
    return m_recording;
} 