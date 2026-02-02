#include "Logger.hpp"
#include <fstream>
#include <ctime>

void Logger::log(const std::string& msg) {
    std::ofstream f("system_log.txt", std::ios::app);
    time_t now = time(nullptr);
    f << ctime(&now) << " - " << msg << "\n";
}