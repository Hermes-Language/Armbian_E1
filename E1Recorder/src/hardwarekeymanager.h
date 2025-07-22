#pragma once

#include <QObject>
#include <QQmlEngine>

class HardwareKeyManager : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool enabled READ enabled WRITE setEnabled NOTIFY enabledChanged)

public:
    static QObject* create(QQmlEngine* engine, QJSEngine* scriptEngine);

    explicit HardwareKeyManager(QObject *parent = nullptr);

    bool enabled() const;
    void setEnabled(bool enabled);

    Q_INVOKABLE void installEventFilter();
    Q_INVOKABLE void removeEventFilter();

signals:
    void sigAIKeyPress();
    void sigStartRecord();
    void sigStopRecord();
    void sigVolumeUp();
    void sigVolumeDown();
    void sigPowerOff();
    void enabledChanged();

private:
    bool enabled_ = true;
};