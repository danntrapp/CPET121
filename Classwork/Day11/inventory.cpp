#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cctype>
#include <limits>

struct models {
    std::string model;
    int num;
    float totPrice;
    void print() { 
        printf("Model: %s\n", model.c_str());
        printf("Num: %d\n", num);
        printf("Total Price: %.2f\n", totPrice);
    }
};

std::istream& operator>>(std::istream& is, models& m) {
    is >> m.model >> m.num >> m.totPrice;
    return is;
}
int main(void) {
    std::string inFileName = "inventory_in.txt";
    std::string outFileName = "inventory_out.txt";
    std::ifstream inFile;
    std::ofstream outFile;
    
    std::vector<models> data;
    std::string input;
    inFile.open(inFileName.c_str());
    if(!inFile.is_open()) exit(1);
    models c;
    while(inFile >> c) {
        data.push_back(c);
    }
    inFile.close();
    outFile.open(outFileName.c_str());
    for(models m : data) {
        outFile << (m.totPrice / m.num) << "\n";
    }
    printf("all done");
    outFile.close();
}