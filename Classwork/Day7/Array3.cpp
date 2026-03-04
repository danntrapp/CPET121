#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(void) {
    int arr[5][5];
    int sum[] = {0, 0, 0, 0, 0};
    int minVal = 0;
    int maxVal = 98;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j ++) {
            arr[i][j] = (rand() % (maxVal - minVal + 1)) + minVal; //googled how to get random num within interval
            cout << arr[i][j] << " ";
            sum[i] += arr[i][j];
        }
        cout << endl;
    }

    for(int i = 0; i < 5; i++) {
             cout << "The Sum of ROW["
         << i << "] :" << right << setw(8) << setfill(' ') << sum[i] << endl;
        cout << endl;
    }
}