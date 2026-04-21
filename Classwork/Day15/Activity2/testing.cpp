//
// Created by danie on 4/14/2026.
//
#include "converter.h"
#include <filesystem>

int main() {
    std::string inName = "C:/Users/danie/Documents/GitHub/CPET121/Classwork/Day15/Activity2/input.txt";
    std::string outName = "C:/Users/danie/Documents/GitHub/CPET121/Classwork/Day15/Activity2/output.txt";
    std::ifstream inFile;
    std::ofstream outFile;
    Converter UpperThing(inFile, outFile, inName, outName);
    UpperThing.readIn();
    UpperThing.convert();
    UpperThing.writeOut();
}