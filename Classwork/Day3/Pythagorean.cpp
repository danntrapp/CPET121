#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
void truncate(float &val, int places) {
    int temp;
    float deci = pow(10, places);
    temp = val * deci;
    val = temp / deci;
}

int main() {
    int places = 3;
    //declaring vars
    float l, w, c;
    //taking in user vals
    cin >> l;
    cin >> w;
    //area
    c = l * w;
    truncate(c, places);
    cout << "Area: " << c << endl;
    //perimeter
    c = (l * 2) + (w * 2);
    truncate(c, places);
    cout << "Perimeter: " << c << endl;
    //pythag
    c = sqrt(pow(l, 2) + pow(w, 2));
    truncate(c, places);
    cout << "Diagonal: " << c << endl;
    return 0;
}