// AdderSuite/src/interfaces/iadder.h
#pragma once

#include "export.h" // تعريف ADDER_API

class ADDER_API IAdder {
public:
    virtual int add(int a, int b) = 0;
    virtual ~IAdder() = default;
};
