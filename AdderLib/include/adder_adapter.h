// AdderSuite/src/adapters/adder_adapter.h
#pragma once

#include "export.h"
#include "iadder.h"

#include <iostream>
#include <memory>         // unique_ptr, make_unique
#include <cstdlib>        // system (اختياري)
#include <utility>        // std::move
#include <limits>         // numeric_limits

//class AdderAdapter : public IAdder {
//public:
//    int add(int a, int b) override;
//};

class ADDER_API AdderAdapter : public IAdder {
public:
    explicit AdderAdapter(
        std::unique_ptr<IAdder> adder = nullptr
    );
    int add(int a, int b) override;
private:
    std::unique_ptr<IAdder> m_Adder;
};
