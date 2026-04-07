#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cctype>
#define SIZE 10


std::string readInFile(std::string fileName, std::ifstream &file) {
    std::string full, line;
    try {
        file.open(fileName.c_str());
        if(!file.is_open()) throw std::runtime_error("File could not be opened");
    } catch(std::runtime_error &err) {
        printf("Runtime Error: %s\n", err.what());
        return NULL;
    }

    while(std::getline(file, line)) {
        full.append(line);
    }
    file.close();
    return full;
}

int main(void) {
    std::string fileName = "out.txt";
    std::string full;
    std::ifstream ifFile;
    std::ofstream ofFile;
    full = readInFile(fileName, ifFile);
    ofFile.open(fileName);
    ofFile << full;
    ofFile.close();
}