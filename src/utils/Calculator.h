#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <memory>
#include <functional>

class Calculator {
public:
    enum CalculatorType { DEFAULT, CALCULATOR2, CALCULATOR3, CALCULATOR4, CALCULATOR5 };

    static std::unique_ptr<Calculator> create(CalculatorType type, int seed = 0);

    virtual ~Calculator() = default;
    virtual double add(double a, double b) const = 0;
    virtual double subtract(double a, double b) const = 0;
    virtual double multiply(double a, double b) const = 0;

    //
    virtual void set_add_override(std::function<double(double, double)> func) {}
};

#endif
