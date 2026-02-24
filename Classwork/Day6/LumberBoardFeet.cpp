#include <iostream>
#include <iomanip>
#include <cmath>

float boardFeet(float w, float h, float l) {
    return((w * l * h)/144.0);
}
double boardFeet(float stuff[3]) {
    return boardFeet(stuff[0], stuff[1], stuff[2]);
}
using namespace std;
int main(void) {
    float d[3];
    cin >> d[0] >> d[1] >> d[2];

    cout << setprecision(2) << fixed << boardFeet(d) << endl;
    return 0;
}