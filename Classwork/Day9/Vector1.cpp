#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(void) {
    vector<int> data = {25, 36, 47, 58};
    printf("Vector is of size %i\r\n", data.size());
    printf("Elements of vector: \r\n");
    for(int i : data) {
        printf("%i, ", i);
    }
    printf("\r\n\n");

    data.resize(6);
    
    printf("Input int 1: ");
    cin >> data[4];
    printf("Input int 2: ");
    cin >> data[5];
    printf("New size of vector: %i\r\n", data.size());
    
    printf("Elements of vector: \r\n");
    for(int i : data) {
        printf("%i, ", i);
    }

    return 0;
    
}