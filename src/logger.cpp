
#include "core/logger.hpp"

#include <iostream>
#include <chrono>
#include <ctime>

namespace {
    std::string now() {
        auto current = std::chrono::system_clock::now();
        auto t = std::chrono::system_clock::to_time_t(current);
        return std::ctime(&t);
    }
}

void Logger::info(const std::string& message) {
    std::cout
        << "{\"level\":\"INFO\",\"message\":\""
        << message
        << "\",\"timestamp\":\""
        << now()
        << "\"}"
        << std::endl;
}

void Logger::error(const std::string& message) {
    std::cerr
        << "{\"level\":\"ERROR\",\"message\":\""
        << message
        << "\",\"timestamp\":\""
        << now()
        << "\"}"
        << std::endl;
}
