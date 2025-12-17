// AdderSuite/src/c_api/c_api.cpp
#include "c_api.h"
#include "adder_factory.h"
#include "logger.h"
#include "error.h"

//extern "C" int ADDER_API add_numbers(int a, int b) {
//    try {
//        auto adder = AdderFactory::create(AdderType::Real);
//        int result = adder->add(a, b);
//#ifdef _DEBUG
//        // هذا السطر يطبع فقط في وضع Debug
//        Logger::info("C-API add_numbers succeeded");
//#endif
//        return result;
//    }
//    catch (const ArithmeticError& e) {
//        Logger::error(std::string("C-API error: ") + e.what());
//        return 0;
//    }
//}

int add_numbers(int a, int b) {
    try {
        auto adder = AdderFactory::create(AdderType::Real);
        int result = adder->add(a, b);
#ifdef _DEBUG
        Logger::info("C-API add_numbers succeeded");
#endif
        return result;
    }
    catch (const ArithmeticError& e) {
        Logger::error(std::string("C-API error: ") + e.what());
        return 0; // أو رمز خطأ مميز حسب تصميم الواجهة
    }
    catch (...) {
        Logger::error("C-API unknown exception");
        return 0;
    }
}

