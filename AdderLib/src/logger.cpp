// AdderSuite/src/logging/logger.cpp
#include "logger.h"
#include <iostream>
#include <mutex>

namespace {
    LogLevel current = LogLevel::Info;
    std::mutex mtx;
    const char* level_str(LogLevel l) {
        switch (l) {
        case LogLevel::Debug: return "DEBUG";
        case LogLevel::Info:  return "INFO";
        case LogLevel::Error: return "ERROR";
        }
        return "UNKNOWN";
    }
}

void Logger::set_level(LogLevel level) { std::lock_guard<std::mutex> lock(mtx); current = level; }

void Logger::debug(const std::string& msg) {
    std::lock_guard<std::mutex> lock(mtx);
    if (current == LogLevel::Debug)
        std::cerr << "[" << level_str(LogLevel::Debug) << "] " << msg << "\n";
}

void Logger::info(const std::string& msg) {
    std::lock_guard<std::mutex> lock(mtx);
    if (current == LogLevel::Debug || current == LogLevel::Info)
        std::cerr << "[" << level_str(LogLevel::Info) << "] " << msg << "\n";
}

void Logger::error(const std::string& msg) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cerr << "[" << level_str(LogLevel::Error) << "] " << msg << "\n";
}
