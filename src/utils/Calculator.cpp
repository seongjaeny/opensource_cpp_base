#include "Calculator.h"
#include <iostream>
#include <memory>
#include <functional>

// **default Calculator**
class DefaultCalculator : public Calculator {
public:
    double add(double a, double b) const override { return a + b; }
    double subtract(double a, double b) const override { return a - b; }
    double multiply(double a, double b) const override { return a * b; }
};

// **calculator2 **
class Calculator2 : public Calculator {
    int seed_;
public:
    explicit Calculator2(int seed) : seed_(seed) {}

    double add(double a, double b) const override { return a + b + seed_; }
    double subtract(double a, double b) const override { return a - b + seed_; }
    double multiply(double a, double b) const override { return a * b + seed_; }
};

// **calculator3 **
class Calculator3 : public Calculator {
    int seed_;
public:
    explicit Calculator3(int seed) : seed_(seed) {}

    double add(double a, double b) const override { return static_cast<int>(a) + static_cast<int>(b) + seed_; }
    double subtract(double a, double b) const override { return static_cast<int>(a) - static_cast<int>(b); }
    double multiply(double a, double b) const override { return static_cast<int>(a) * static_cast<int>(b); }
};

// **calculator4 **
class Calculator4 : public Calculator {
public:
    double add(double a, double b) const override { return static_cast<int>(a) + static_cast<int>(b); }
    double subtract(double a, double b) const override { return a - b; }
    double multiply(double a, double b) const override { return a * b; }
};

// **calculator5（支持动态替换 add ）**
class Calculator5 : public Calculator {
    std::function<double(double, double)> add_override_;

public:
    double add(double a, double b) const override {
        if (add_override_) {
            return add_override_(a, b);  //  add
        }
        return a + b;  // default
    }

    double subtract(double a, double b) const override { return a - b; }
    double multiply(double a, double b) const override { return a * b; }

    void set_add_override(std::function<double(double, double)> func) override {
        add_override_ = std::move(func);  //  add
    }
};

std::unique_ptr<Calculator> Calculator::create(CalculatorType type, int seed) {
    switch (type) {
        case CALCULATOR2: return std::make_unique<Calculator2>(seed);
        case CALCULATOR3: return std::make_unique<Calculator3>(seed);
        case CALCULATOR4: return std::make_unique<Calculator4>();
        case CALCULATOR5: return std::make_unique<Calculator5>();
        default: return std::make_unique<DefaultCalculator>();
    }
}
