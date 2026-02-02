#pragma once
#include "Sensor.hpp"

class HeatSensor : public Sensor {
    private:
        int temperature = 25;

    public:
        void setTemp(int t);
        int getTemp() const;
        void poll() override;
};
