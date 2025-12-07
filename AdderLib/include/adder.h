// AdderSuite/src/domain/adder.h
#pragma once
#include "iadder.h"

class Adder : public IAdder {
public:
    int add(int a, int b) override;
};
#pragma once
