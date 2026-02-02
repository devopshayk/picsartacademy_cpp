#pragma once
#include "../sensors/DoorSensor.hpp"
#include "../sensors/MotionSensor.hpp"
#include "../sensors/HeatSensor.hpp"
#include "../services/NotificationService.hpp"
#include "../alarm/AlarmService.hpp"

class SecurityController {
    private:
        bool armed = false;
        AlarmService alarm;

    public:
        void arm();
        void check(DoorSensor& door, MotionSensor& motion, HeatSensor& heat, NotificationService& notifier);
};
