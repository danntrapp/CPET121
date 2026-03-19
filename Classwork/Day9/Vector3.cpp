#include <iostream>
#include <vector>
#include <cstdlib>

#define TESTING true

using namespace std;

int main(void) {
    int input, min, max;
    cin >> input;

    vector<int> vec;
    srand(time(NULL));
    if(TESTING) {
        min = rand() % 100;
        max = rand() % 100;
        if(min > max) swap(min, max);
        for(int i = 0; i < input; i++) {
        vec.push_back(rand() % 100);
        }
    } else {
        for(int i = 0; i < vec.size(); i++) {
            cin >> input;
            vec.push_back(input);
        }
        cin >> min >> max;
    }
    printf("Min: %i\r\n", min);
    printf("Max: %i\r\n", max);
    cout << "Starting vec: \r\n";
    for(int i : vec) {
        cout << i << ", ";
    }
    cout << "\r\n\n";
    cout << "Vals in range: \r\n";
    for(int i : vec) {
        if(i >= min && i <= max)
            cout << i << ", ";
    }

    return 0;
}