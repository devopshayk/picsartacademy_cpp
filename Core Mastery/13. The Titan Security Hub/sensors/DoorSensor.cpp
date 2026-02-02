#include "DoorSensor.hpp"
#include <iostream>

void DoorSensor::setState(bool value) {
    open = value;
}

bool DoorSensor::isOpen() const {
    return open;
}

void DoorSensor::poll() {
    std::cout << "[DoorSensor] " << (open ? "OPEN" : "CLOSED") << std::endl;
}