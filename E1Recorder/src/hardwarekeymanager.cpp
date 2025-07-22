#include "hardwarekeymanager.h"

QObject* HardwareKeyManager::create(QQmlEngine* engine, QJSEngine* scriptEngine) {
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);
    return new HardwareKeyManager();
}

HardwareKeyManager::HardwareKeyManager(QObject *parent) : QObject(parent) {}

bool HardwareKeyManager::enabled() const {
    return enabled_;
}

void HardwareKeyManager::setEnabled(bool enabled) {
    if (enabled_ != enabled) {
        enabled_ = enabled;
        emit enabledChanged();
    }
}

void HardwareKeyManager::installEventFilter() {
    // In a real application, you would install an event filter here to listen for key presses.
}

void HardwareKeyManager::removeEventFilter() {
    // In a real application, you would remove the event filter here.
}
