#include <iostream>
#include <cmath>
#include "calc.h"

int main(void) {
    auto func = [](double x) -> double {
        return std::pow(x, 2);
    };

    double areaUnder = Calc::estimateArea(func, {0, 1}, 4, Calc::LEFT);

    printf("Area: %f", areaUnder);
}