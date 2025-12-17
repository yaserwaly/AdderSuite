// AdderSuite/src/errors/error.h
#pragma once

#include "export.h"
#include <stdexcept>
#include <string>

class ADDER_API ArithmeticError : public std::runtime_error {
public:
    explicit ArithmeticError(const std::string& msg) : std::runtime_error(msg) {}
};
