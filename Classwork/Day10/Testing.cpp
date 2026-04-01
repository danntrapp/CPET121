#include <iostream>
#include <cmath>
#include <iomanip>
#include "MultiSidedDie.hpp"


int main(void) {
    int d;
    // printf("Number of sides for Die 1: ");
    // cin >> d;
    d = 12;
    MultiSidedDie die1(d);
    // printf("Number of sides for Die 2: ");
    // cin >> d;
    d = 22;
    MultiSidedDie die2(d);

    std::cout << "Die 1: " << std::endl;
    die1.print();
    std::cout << "Die 2: " << std::endl;
    die2.print();

}

