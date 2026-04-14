#include "parts.h"

float FracPart(float num) {
    int temp = static_cast<int>(num);
    return (num - static_cast<float>(temp));
}