#include "SecurityController.hpp"

void SecurityController::arm() {
    armed = true;
}

void SecurityController::check(DoorSensor& door, MotionSensor& motion, HeatSensor& heat, NotificationService& notifier) {
    if (armed && door.isOpen())
        alarm.trigger("HIGH", notifier);

    if (armed && motion.detected())
        alarm.trigger("MEDIUM", notifier);

    if (heat.getTemp() > 50)
        alarm.trigger("CRITICAL", notifier);
}