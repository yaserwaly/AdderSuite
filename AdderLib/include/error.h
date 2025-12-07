// AdderSuite/src/errors/error.h
#pragma once
#include <stdexcept>
#include <string>

class ArithmeticError : public std::runtime_error {
public:
    explicit ArithmeticError(const std::string& msg) : std::runtime_error(msg) {}
};
#pragma once
