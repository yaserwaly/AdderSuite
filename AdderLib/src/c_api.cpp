// AdderSuite/src/c_api/c_api.cpp
#include "adder_factory.h"
#include "logger.h"
#include "error.h"

extern "C" int add_numbers(int a, int b) {
    try {
        auto adder = AdderFactory::create(AdderType::Real);
        int result = adder->add(a, b);
        Logger::info("C-API add_numbers succeeded");
        return result;
    }
    catch (const ArithmeticError& e) {
        Logger::error(std::string("C-API error: ") + e.what());
        return 0;
    }
}
