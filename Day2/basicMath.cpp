#include <iostream>
#include <iomanip>

using namespace std;
int main() {
    double num1, num2;
    cout << "Num one: ";
    cin >> num1;
    cout << "Num two: ";
    cin >> num2;
    cout << fixed << setprecision(2);

    cout << endl << endl;
    double sum = (num1 + num2);
    cout << "Sum: " << (num1 + num2) << endl;
    cout << "Diff: " << (num1 - num2) << endl;
    cout << "Product: " << (num1 * num2) << endl;
    cout << "Average: " << (sum/2);

    return 0;
}