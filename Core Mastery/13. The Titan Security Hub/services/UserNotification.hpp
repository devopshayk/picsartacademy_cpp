#pragma once
#include "NotificationService.hpp"
#include <iostream>

class UserNotification : public NotificationService {
public:
    void notify(const std::string& msg) override {
        std::cout << "Sending push notification: " << msg << std::endl;
    }
};