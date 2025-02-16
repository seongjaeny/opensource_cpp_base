#pragma once

#include <memory>

class Calculator {
public:
    Calculator(int seed);
    ~Calculator();

    int add(int x, int y) const;
    int subtract(int x, int y) const;

    static int multiply(int x, int y);

private:
    struct Impl;
    std::unique_ptr<Impl> pimpl_;
};
