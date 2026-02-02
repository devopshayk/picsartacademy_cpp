#pragma once
#include "Sensor.hpp"

class DoorSensor : public Sensor {
    private:
        bool open = false;

    public:
        void setState(bool value);
        bool isOpen() const;
        void poll() override;
};