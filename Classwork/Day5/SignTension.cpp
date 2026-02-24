#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {



    const double SIGN_WEIGHT = 100.0;
    const double CABLE_LENGTH = 6.0;
    const double POLE_LENGTH = 6.0;
    const double INC = 0.001;

    double tension, newTension;

    double x = 1;

    auto calcTension = [&](double x, double &ret) -> void {
        ret = ((SIGN_WEIGHT * CABLE_LENGTH * POLE_LENGTH) / (x * sqrt(CABLE_LENGTH * POLE_LENGTH - pow(x, 2.0))));
    };

    while(x <= 5.9) {
        x += INC;
        calcTension(x, newTension);
        cout << newTension << endl;
        if(newTension < tension) {
            tension = newTension;
            continue;
        } else {
            x -= INC;
            cout << fixed << setprecision(3);
            cout << "Min: " << tension << setw(4);
            break;
        }
    }
    
}