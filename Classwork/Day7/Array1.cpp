#include <iostream>

using namespace std;
int main(void) {
    int arr[5];

    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
    cout << endl;
    for(int i : arr) {
        cout << i << endl;
    }
}