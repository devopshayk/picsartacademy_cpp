#pragma once
#include "NotificationService.hpp"
#include <iostream>

class PoliceNotification : public NotificationService {
    public:
        void notify(const std::string& msg) override {
            std::cout << "Calling police: " << msg << std::endl;
        }
};