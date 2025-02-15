#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <vector>

class Logger {
   public:
    void log(const std::string& message);
    const std::vector<std::string>& getLogs() const;

   private:
    std::vector<std::string> logs;
};

#endif  // LOGGER_H
