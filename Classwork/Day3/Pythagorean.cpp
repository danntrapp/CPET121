#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    //declaring vars
    double l, w, c;
    //taking in user vals
    cout << "Length: ";
    cin >> l;
    cout << "Width: ";
    cin >> w;
    //area
    c = (l * w);

    cout << setprecision(3);
    cout << setw(10);
    cout << "Area: " << c << endl;
    //perimeter
    c = (l * 2.0) + (w * 2.0);

    cout << "Perimeter: " << c << endl;
    //pythag
    c = sqrt(pow(l, 2.0) + pow(w, 2.0));

    cout << "Diagonal: " << c << endl;
    return 0;
}