#pragma once

class Sensor {
    public:
        virtual ~Sensor() = default;
        virtual void poll() = 0;
};