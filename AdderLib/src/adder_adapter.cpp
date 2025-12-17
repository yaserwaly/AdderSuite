// AdderSuite/src/adapters/adder_adapter.cpp
#include "adder_adapter.h"
#include "logger.h"

#include "adder.h"       // لو بدك استخدام Adder مباشرة

//int AdderAdapter::add(int a, int b) {
//    Logger::debug("Adapter add called");
//    return a + b;
//}

AdderAdapter::AdderAdapter(
    std::unique_ptr<IAdder> adder
) : m_Adder(adder ? std::move(adder) : std::make_unique<Adder>()) {
}

int AdderAdapter::add(int a, int b) {
    Logger::debug("Adapter add called");
    return m_Adder->add(a, b);
}
