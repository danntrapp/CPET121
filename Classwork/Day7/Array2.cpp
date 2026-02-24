#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(void) {
    int arr[5];
    int avg = 0;
    int sum = 0;
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
    for(int i : arr) {
        sum += i;
    }
    avg = sum / 5.0;
    cout << left << setw(21) << setfill('.') << "The Sum is"
         << " :" << right << setw(8) << setfill(' ') << sum << endl;
    cout << left << setw(21) << setfill('.') << "The Average is"
         << " :" << right << setw(8) << setfill(' ') << avg << endl;
    cout << left << setw(21) << setfill('.') << "The elements are"
         << " :" << right << setw(8) << setfill(' ');
    for(int i : arr) {
        cout << i << ", ";
    }
    cout << endl;
}