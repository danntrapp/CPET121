#pragma once

#include <iostream>
#include <string>
#include "parts.h"

int main() {
    float number, whole, frac;

    printf("Enter a number: ");
    scanf("%f", &number);
    whole = WholePart(number);
    frac = FracPart(number);
    printf("WholePart: %f\n", whole);
    printf("FracPart: %f\n", frac);
    return 0;
}