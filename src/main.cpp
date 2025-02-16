#include <iostream>
#include "Calculator.h"

int main() {
    Calculator calc(10); // seed = 10

    std::cout << "6 + 5 = " << calc.add(6, 5) << std::endl; // 6 + 5 + 10 = 21
    std::cout << "6 - 5 = " << calc.subtract(6, 5) << std::endl; // 6 - 5 + 10 = 11
    std::cout << "6 * 5 = " << Calculator::multiply(6, 5) << std::endl; // 6 * 5 = 30

    return 0;
}
