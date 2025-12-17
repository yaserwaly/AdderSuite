// AdderSuite/src/domain/adder.h
#pragma once

#include "export.h"
#include "iadder.h"

class ADDER_API Adder : public IAdder {
public:
    int add(int a, int b) override;
};
