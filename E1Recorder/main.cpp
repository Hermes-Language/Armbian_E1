#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "storagemanager.h"
#include "audiorecorder.h"
#include "hardwarekeymanager.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    qmlRegisterSingletonType<StorageManager>("RecorderApp", 1, 0, "StorageManager", &StorageManager::create);
    qmlRegisterType<AudioRecorder>("RecorderApp", 1, 0, "AudioRecorder");
    qmlRegisterSingletonType<HardwareKeyManager>("HardwareKey", 1, 0, "HardwareKeyManager", &HardwareKeyManager::create);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/qml/Main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}