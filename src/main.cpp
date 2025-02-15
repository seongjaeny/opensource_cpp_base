#include "Calculator.h"
#include <iostream>

void test_calculator(Calculator::CalculatorType type, int seed = 0) {
    auto calc = Calculator::create(type, seed);

    std::cout << "\nTesting Calculator Type: " << type << (seed ? " (Seed: " + std::to_string(seed) + ")" : "") << std::endl;
    std::cout << "2 + 3 = " << calc->add(2, 3) << std::endl;
    std::cout << "5 - 3 = " << calc->subtract(5, 3) << std::endl;
    std::cout << "2 * 3 = " << calc->multiply(2, 3) << std::endl;
}

int main() {
    // ** Calculator**
    test_calculator(Calculator::DEFAULT);

    // ** Calculator2（ seed ）**
    test_calculator(Calculator::CALCULATOR2, 10);

    // ** Calculator3（int， seed）**
    test_calculator(Calculator::CALCULATOR3, 5);

    // ** Calculator4**
    test_calculator(Calculator::CALCULATOR4);

    // ** Calculator5（ `add` ）**
    auto calc5 = Calculator::create(Calculator::CALCULATOR5);
    std::cout << "\nTesting Calculator5 (Default add behavior):" << std::endl;
    std::cout << "2 + 3 = " << calc5->add(2, 3) << std::endl;
    std::cout << "5 - 3 = " << calc5->subtract(5, 3) << std::endl;
    std::cout << "2 * 3 = " << calc5->multiply(2, 3) << std::endl;

    // **动态替换 `add` 方法**
    calc5->set_add_override([](double x, double y) { return x + y + 1000; });
    std::cout << "\nCalculator5 (Overridden add function):" << std::endl;
    std::cout << "2 + 3 = " << calc5->add(2, 3) << " (Expected: 1005)" << std::endl;

    return 0;
}
