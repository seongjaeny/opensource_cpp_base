#include "Calculator.h"
#include <iostream>

struct Calculator::Impl {
    int seed;

    Impl(int s) : seed(s) {}

    int add(int x, int y) const {
        return x + y + seed;
    }

    int subtract(int x, int y) const {
        return x - y + seed;
    }
};

Calculator::Calculator(int seed) : pimpl_(std::make_unique<Impl>(seed)) {}

Calculator::~Calculator() = default;

int Calculator::add(int x, int y) const {
    return pimpl_->add(x, y);
}

int Calculator::subtract(int x, int y) const {
    return pimpl_->subtract(x, y);
}

int Calculator::multiply(int x, int y) {
    return x * y;
}
