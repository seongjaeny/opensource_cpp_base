#include "Logger.h"

void Logger::log(const std::string &message) {
    logs.push_back(message);
}

const std::vector<std::string>& Logger::getLogs() const {
    return logs;
}
