#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

void ExactChange(int cents, int& dol, int& q, int& d, int& n, int& p) {
    if(cents == 0) return;
    auto div = [&cents](int div, int& prod) -> void {
        prod = cents / div;
        cents %= div;
    };
    div(100, dol);
    div(25, q);
    div(10, d);
    div(5, n);
    div(1, p);
}


int main(void) {
    int cents;
    int dol(0), q(0), d(0), n(0), p(0);

    std::cin >> cents;

    ExactChange(cents, dol, q, d, n, p);

    if(dol != 0) printf("Dollars: %i\n", dol);
    if(q != 0) printf("Quarters: %i\n", q);
    if(d != 0) printf("Dimes: %i\n", d);
    if(n != 0) printf("Nickels: %i\n", n);
    if(p != 0)printf("Pennies: %i\n", p);
}