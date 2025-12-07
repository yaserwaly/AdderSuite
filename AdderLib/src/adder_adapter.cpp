// AdderSuite/src/adapters/adder_adapter.cpp
#include "adder_adapter.h"
#include "logger.h"

int AdderAdapter::add(int a, int b) {
    Logger::debug("Adapter add called");
    return a + b;
}
