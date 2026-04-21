//
// Created by danie on 4/9/2026.
//
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

struct food {
    std::string name;
    int serving, calories, protein;
};

int main() {
    std::vector<food> v;
    std::string filename = "food.txt";
    std::ifstream istream;
    istream.open(filename);
    if (!istream.is_open()) return 0;
    food f;
    while (!istream.eof()) {
        istream >> f.name >> f.serving >> f.calories >> f.protein;
        v.push_back(f);
    }
    for (const food& food1 : v) {
        std::cout << food1.name << " <- food" << std::endl;
        std::cout << food1.serving << " serving"<< std::endl;
        std::cout << food1.calories << " cals"<< std::endl;
        std::cout << food1.protein << " protein" << std::endl << std::endl;
    }
}