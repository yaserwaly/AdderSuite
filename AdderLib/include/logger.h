// AdderSuite/src/logging/logger.h
#pragma once

#include "export.h"
#include <string>

enum class LogLevel { Debug, Info, Error };

class ADDER_API Logger {
public:
    static void set_level(LogLevel level);
    static void debug(const std::string& msg);
    static void info(const std::string& msg);
    static void error(const std::string& msg);
};
