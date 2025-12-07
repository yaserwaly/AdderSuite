// AdderSuite/src/factory/adder_factory.cpp
#include "adder_factory.h"
#include "adder.h"

class StubAdder : public IAdder {
public:
    int add(int, int) override { return 42; }
};

std::unique_ptr<IAdder> AdderFactory::create(AdderType type) {
    if (type == AdderType::Stub) {
        return std::make_unique<StubAdder>();
    }
    return std::make_unique<Adder>();
}
