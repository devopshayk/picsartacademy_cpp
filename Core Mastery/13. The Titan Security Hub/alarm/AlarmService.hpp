#pragma once
#include "../services/SoundService.hpp"
#include "../services/Logger.hpp"
#include "../services/NotificationService.hpp"

class AlarmService {
    private:
        SoundService sound;
        Logger logger;

    public:
        void trigger(const std::string& severity, NotificationService& notifier);
};