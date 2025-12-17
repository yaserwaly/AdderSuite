// AdderSuite/src/factory/adder_factory.h
#pragma once

#include "export.h"
#include "iadder.h"
#include <memory>

enum class AdderType {
    Real,
    Stub
};

class ADDER_API AdderFactory {
public:
    static std::unique_ptr<IAdder> create(AdderType type = AdderType::Real);
};
