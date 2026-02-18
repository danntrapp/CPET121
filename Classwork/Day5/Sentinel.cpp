#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
int main(void) {
    int x;
    int max;
    cin >> x;
    max = x;
    while(x > 0) {
        max = x < max ? max : x;
        cin >> x;
    }
    cout << "max: " << max << endl;
}