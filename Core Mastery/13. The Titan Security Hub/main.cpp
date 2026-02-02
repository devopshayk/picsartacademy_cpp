#include "core/SecurityController.hpp"
#include "services/PoliceNotification.hpp"

int main() {
    DoorSensor door;
    MotionSensor motion;
    HeatSensor heat;

    PoliceNotification police;

    SecurityController controller;
    controller.arm();

    door.setState(true);
    heat.setTemp(60);

    controller.check(door, motion, heat, police);
}


// Kisat, piti popoxvi !!!!!!!!!