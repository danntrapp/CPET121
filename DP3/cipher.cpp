#include <cctype>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

void parseString(const std::string &fullLine, std::vector<std::string> &vec) {
    std::string s;
    for (char c : fullLine) {
        if (!std::isalpha(static_cast<unsigned char>(c))) {
            continue;
        }
        s.push_back(c);
        if (s.size() == 5) {
            vec.push_back(s);
            s.clear();
        }
    }
}

uint8_t stringToBin(const std::string &s) {
    if (s.size() != 5) {
        return 0;
    }

    uint8_t bin = 0b11111;
    auto flipBit = [](uint8_t &bin, int pos) {
        bin ^= (1 << pos);
    };

    // Most significant bit comes from first char
    for (int i = 0; i < 5; i++) {
        if (std::islower(static_cast<unsigned char>(s[i]))) {
            flipBit(bin, 4 - i);
        }
    }

    return bin;
}
std::string decipherBin(const std::vector<uint8_t> input) {
    const std::map<uint8_t, char> cipherMap = {
    {0b11111, 'A'},
    {0b11110, 'B'},
    {0b11101, 'C'},
    {0b11100, 'D'},
    {0b11011, 'E'},
    {0b11010, 'F'},
    {0b11001, 'G'},
    {0b11000, 'H'},
    {0b10111, 'I'},
    {0b10110, 'J'},
    {0b10101, 'K'},
    {0b10100, 'L'},
    {0b10011, 'M'},
    {0b10010, 'N'},
    {0b10001, 'O'},
    {0b10000, 'P'},
    {0b01111, 'Q'},
    {0b01110, 'R'},
    {0b01101, 'S'},
    {0b01100, 'T'},
    {0b01011, 'U'},
    {0b01010, 'V'},
    {0b01001, 'W'},
    {0b01000, 'X'},
    {0b00111, 'Y'},
    {0b00110, 'Z'},
    {0b00101, '.'},
    {0b00100, ';'},
    {0b00011, '!'},
    {0b00010, '?'},
    {0b00001, '0'},
    {0b00000, ' '}};

    std::string ret;
    for(uint8_t i : input) {
        try {
            auto c = cipherMap.find(i);
            if(c != cipherMap.end()) {
                ret.push_back(c->second);
            } else {
                throw std::runtime_error("Invalid cipher input");
            }
        } catch(std::runtime_error& err) {
            printf("Runtime Error: %s\n", err.what());
        }
    }
    return ret;
}

int main() {
    std::string fileName, line, full;
    std::ifstream file;
    std::vector<uint8_t> bins;
    std::vector<std::string> parsedStrings;
    fileName = "drew.txt";  // input used for the given test case

    try {
        file.open(fileName.c_str());
        if(!file.is_open()) throw std::runtime_error("File could not be opened");
    }   catch(std::runtime_error &err) {
        printf("Runtime Error: %s\n", err.what());
        return 1;
    }

    while(std::getline(file, line)) {
        full.append(line);
    }
    std::cout << full << std::endl;
    parseString(full, parsedStrings);
    for(std::string s : parsedStrings) {
        bins.push_back(stringToBin(s));
    }
    full.clear();
    full = decipherBin(bins);

    std::cout << full << std::endl;
    return 0;
}
