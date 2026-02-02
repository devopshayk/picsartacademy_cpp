#include "AlarmService.hpp"

void AlarmService::trigger(const std::string& severity, NotificationService& notifier) {
    sound.playSiren();
    notifier.notify("Severity: " + severity);
    logger.log("Alarm triggered: " + severity);
}