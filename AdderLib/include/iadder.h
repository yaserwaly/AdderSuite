// AdderSuite/src/interfaces/iadder.h
#pragma once

class IAdder {
public:
    virtual int add(int a, int b) = 0;
    virtual ~IAdder() = default;
};
#pragma once
