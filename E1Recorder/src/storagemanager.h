#pragma once

#include <QObject>
#include <QStringList>
#include <QQmlEngine>

class StorageManager : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString recordingsPath READ recordingsPath CONSTANT)
    Q_PROPERTY(int availableSpace READ availableSpace NOTIFY storageChanged)
    Q_PROPERTY(int usedSpace READ usedSpace NOTIFY storageChanged)
    Q_PROPERTY(int recordingQuality READ recordingQuality WRITE setRecordingQuality NOTIFY configChanged)
    Q_PROPERTY(QString recordingFormat READ recordingFormat WRITE setRecordingFormat NOTIFY configChanged)
    Q_PROPERTY(bool autoSave READ autoSave WRITE setAutoSave NOTIFY configChanged)
    Q_PROPERTY(int maxRecordingDuration READ maxRecordingDuration WRITE setMaxRecordingDuration NOTIFY configChanged)

public:
    static QObject* create(QQmlEngine* engine, QJSEngine* scriptEngine);

    explicit StorageManager(QObject *parent = nullptr);

    QString recordingsPath() const;
    int availableSpace() const;
    int usedSpace() const;
    int getStorageUsagePercentage() const;

    int recordingQuality() const;
    void setRecordingQuality(int quality);

    QString recordingFormat() const;
    void setRecordingFormat(const QString& format);

    bool autoSave() const;
    void setAutoSave(bool autoSave);

    int maxRecordingDuration() const;
    void setMaxRecordingDuration(int duration);

    Q_INVOKABLE QStringList getRecordingsList() const;
    Q_INVOKABLE void deleteRecording(const QString& fileName);
    Q_INVOKABLE void exportRecording(const QString& fileName);
    Q_INVOKABLE void saveConfig();
    Q_INVOKABLE void loadConfig();

signals:
    void storageChanged();
    void configChanged();
    void recordingSaved(const QString& fileName);
    void recordingDeleted(const QString& fileName);
    void storageSpaceLow();

private:
    QString recordings_path_;
    QString config_path_;
};