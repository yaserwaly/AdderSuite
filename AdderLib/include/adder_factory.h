// AdderSuite/src/factory/adder_factory.h
#pragma once
#include "iadder.h"
#include <memory>

enum class AdderType {
    Real,
    Stub
};

class AdderFactory {
public:
    static std::unique_ptr<IAdder> create(AdderType type = AdderType::Real);
};
#pragma once
