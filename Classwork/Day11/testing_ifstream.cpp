#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#define SIZE 10

int main(void) {
    std::string s = "test_data.dat";
    std::ifstream inFile;

    std::vector<float> data = std::vector<float>(SIZE);
    float largest = 0.0;
    float smallest = LONG_MAX;

    inFile.open(s.c_str());
    if(!inFile.is_open()) exit(1);
    std::cout << "Data: \r\n";
    for(int i = 0; i < SIZE; i++) {
        inFile >> data.at(i);
        std::cout << data.at(i) << ", ";
        largest = largest > data.at(i) ? largest : data.at(i);
        smallest = smallest < data.at(i) ? smallest : data.at(i);
    }

    std::cout << "\r\nLargest: " << largest;
    std::cout << "\r\nSmallest: " << smallest;
    
    inFile.close();

}