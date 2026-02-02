#pragma once
#include <string>

class NotificationService {
    public:
        virtual ~NotificationService() = default;
        virtual void notify(const std::string& msg) = 0;
};