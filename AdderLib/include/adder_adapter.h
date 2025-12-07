// AdderSuite/src/adapters/adder_adapter.h
#pragma once
#include "iadder.h"

class AdderAdapter : public IAdder {
public:
    int add(int a, int b) override;
};
#pragma once
