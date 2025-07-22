#include "storagemanager.h"

#include <QDir>
#include <QFileInfoList>
#include <QSettings>
#include <QStandardPaths>
#include <QStorageInfo>

QObject* StorageManager::create(QQmlEngine* engine, QJSEngine* scriptEngine) {
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);
    return new StorageManager();
}

StorageManager::StorageManager(QObject *parent) : QObject(parent) {
    recordings_path_ = QStandardPaths::writableLocation(QStandardPaths::MusicLocation) + "/E1Recorder";
    config_path_ = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation) + "/E1Recorder.ini";

    QDir().mkpath(recordings_path_);
    loadConfig();
}

QString StorageManager::recordingsPath() const { 
    return recordings_path_;
}

int StorageManager::availableSpace() const {
    QStorageInfo storage(recordings_path_);
    return storage.bytesAvailable() / (1024 * 1024);
}

int StorageManager::usedSpace() const {
    QStorageInfo storage(recordings_path_);
    return (storage.bytesTotal() - storage.bytesAvailable()) / (1024 * 1024);
}

int StorageManager::getStorageUsagePercentage() const {
    QStorageInfo storage(recordings_path_);
    if (storage.bytesTotal() == 0) {
        return 0;
    }
    return 100 * (storage.bytesTotal() - storage.bytesAvailable()) / storage.bytesTotal();
}

int StorageManager::recordingQuality() const {
    QSettings settings(config_path_, QSettings::IniFormat);
    return settings.value("quality", 0).toInt();
}

void StorageManager::setRecordingQuality(int quality) {
    QSettings settings(config_path_, QSettings::IniFormat);
    settings.setValue("quality", quality);
    emit configChanged();
}

QString StorageManager::recordingFormat() const {
    QSettings settings(config_path_, QSettings::IniFormat);
    return settings.value("format", "WAV").toString();
}

void StorageManager::setRecordingFormat(const QString& format) {
    QSettings settings(config_path_, QSettings::IniFormat);
    settings.setValue("format", format);
    emit configChanged();
}

bool StorageManager::autoSave() const {
    QSettings settings(config_path_, QSettings::IniFormat);
    return settings.value("autoSave", true).toBool();
}

void StorageManager::setAutoSave(bool autoSave) {
    QSettings settings(config_path_, QSettings::IniFormat);
    settings.setValue("autoSave", autoSave);
    emit configChanged();
}

int StorageManager::maxRecordingDuration() const {
    QSettings settings(config_path_, QSettings::IniFormat);
    return settings.value("maxDuration", 3600).toInt();
}

void StorageManager::setMaxRecordingDuration(int duration) {
    QSettings settings(config_path_, QSettings::IniFormat);
    settings.setValue("maxDuration", duration);
    emit configChanged();
}

QStringList StorageManager::getRecordingsList() const {
    QDir dir(recordings_path_);
    QStringList files = dir.entryList(QStringList() << "*.wav", QDir::Files, QDir::Time);
    return files;
}

void StorageManager::deleteRecording(const QString& fileName) {
    QFile file(recordings_path_ + "/" + fileName);
    if (file.remove()) {
        emit recordingDeleted(fileName);
        emit storageChanged();
    }
}

void StorageManager::exportRecording(const QString& fileName) {
    // This is where you would implement the logic to export the recording to a USB drive, etc.
    emit recordingSaved(fileName);
}

void StorageManager::saveConfig() {
    // QSettings are saved automatically.
    emit configChanged();
}

void StorageManager::loadConfig() {
    emit configChanged();
}