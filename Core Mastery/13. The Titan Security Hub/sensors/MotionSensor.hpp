#pragma once
#include "Sensor.hpp"

class MotionSensor : public Sensor {
    private:
        bool motion = false;

    public:
        void setMotion(bool value);
        bool detected() const;
        void poll() override;
};