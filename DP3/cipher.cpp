#include <cctype>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Parses raw input into 5-character alphabetic groups, ignoring non-alpha chars
void parseString(const std::string &fullLine, std::vector<std::string> &vec) {
    std::string input;
    for (char c : fullLine) {
        if (!std::isalpha(static_cast<unsigned char>(c)))
            continue;

        input.push_back(c);

        // Once a full 5-char Baconian symbol is collected, store and reset
        if (input.size() == 5) {
            vec.push_back(input);
            input.clear();
        }
    }
}

// Converts a 5-char string to a 5-bit value; lowercase = 1 (B), uppercase = 0 (A)
uint8_t stringToBin(const std::string &s) {
    if (s.size() != 5) return 0;

    uint8_t bin = 0;

    // Flips bit at position pos in bin
    auto flipBit = [](uint8_t &bin, int pos) {
        bin ^= (1 << pos);
    };

    // Index 0 -> bit 4 (MSB), index 4 -> bit 0 (LSB)
    for (int i = 0; i < 5; i++) {
        if (std::islower(static_cast<unsigned char>(s[i]))) {
            flipBit(bin, 4 - i);
        }
    }
    return bin;
}

// Decodes binary values to plaintext using charMap as a lookup table
std::string decipherBin(const std::vector<uint8_t> &input, const std::vector<char> &charMap) {
    std::string ret;
    for (uint8_t i : input) {
        try {
            ret.push_back(charMap.at(i));
        } catch (std::out_of_range& err) {
            printf("Runtime Error: %s\n", err.what());
        }
    }
    return ret;
}

// Reads entire file contents into a single concatenated string
std::string readInFile(const std::string& fileName, std::ifstream &file) {
    std::string full, line;
    try {
        file.open(fileName.c_str());
        if (!file.is_open()) throw std::runtime_error("File could not be opened");
    } catch (std::runtime_error &err) {
        printf("Runtime Error: %s\n", err.what());
        return nullptr;
    }

    while (std::getline(file, line)) {
        full.append(line);
    }
    return full;
}

int main() {
    std::string fileName, full, message;
    std::ifstream file;
    std::vector<uint8_t> bins;
    std::vector<std::string> parsedStrings;
    // Index = Baconian value (0-25 = A-Z), extended with punctuation and space
    const std::vector<char> charMap = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G',
    'H', 'I', 'J', 'K', 'L', 'M', 'N',
    'O', 'P', 'Q', 'R', 'S', 'T', 'U', 
    'V', 'W', 'X', 'Y', 'Z', '.', ';', 
    '!', '?', '0', ' '};
    std::cout << "Enter File Name: ";
    std::getline(std::cin, fileName);
    fileName.append(".txt");

    full = readInFile(fileName, file);
    std::cout << full << std::endl;

    parseString(full, parsedStrings);                        // Step 1: tokenize
    for (std::string s : parsedStrings) bins.push_back(stringToBin(s)); // Step 2: encode
    message = decipherBin(bins, charMap);                    // Step 3: decode

    std::cout << message << std::endl;
    return 0;
}