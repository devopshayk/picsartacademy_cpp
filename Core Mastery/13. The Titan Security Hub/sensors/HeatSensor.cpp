#include "HeatSensor.hpp"
#include <iostream>

void HeatSensor::setTemp(int t) {
    temperature = t;
}

int HeatSensor::getTemp() const {
    return temperature;
}

void HeatSensor::poll() {
    std::cout << "[HeatSensor] Temp: " << temperature << "C" << std::endl;
}
