#include "MotionSensor.hpp"
#include <iostream>

void MotionSensor::setMotion(bool value) {
    motion = value;
}

bool MotionSensor::detected() const {
    return motion;
}

void MotionSensor::poll() {
    std::cout << "[MotionSensor] Motion: " << (motion ? "YES" : "NO") << std::endl;
}