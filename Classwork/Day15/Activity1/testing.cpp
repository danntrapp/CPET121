#include <iostream>
#include <iomanip>

#include "parts.h"

int main(void) {
    float num, part;
    int whole;

    printf("Enter float: ");
    scanf("%f", &num);

    whole = static_cast<int>(WholePart(num));
    part = FracPart(num);

    printf("Int part: %d\r\nDecimals: %f", whole, part);



}
