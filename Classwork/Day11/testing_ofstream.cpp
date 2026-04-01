#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#define SIZE 10

int main(void) {
    std::string fileName = "s_a.dat";
    std::ofstream outFile = std::ofstream();

    std::vector<float> data = std::vector<float>(SIZE);
    data = {5.8, 10.2, 8.8, 22.2, 17.5};
    // std::cout << "Input 5 floats: ";
    // for(int i = 0; i < SIZE; i++) {
    //     std::cin >> data.at(i);
    // }

    outFile.open(fileName.c_str());

    for(float f : data) {
        outFile << f << "\n";
    }


    


}