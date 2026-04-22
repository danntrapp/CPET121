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
        if (!std::isalpha(static_cast<unsigned char>(c))) continue;

        input.push_back(c);

        // Once a full 5-char Baconian symbol is collected, store and reset
        if (input.size() == 5) {
            vec.push_back(input);
            input.clear();
        }
    }
}

// Flips bit at position pos in bin
void flipBit(int &b, int pos) {
    b ^= (1 << pos);
}

// Converts a 5-char string to a 5-bit value; lowercase = 1 (B), uppercase = 0 (A)
int stringToBin(const std::string &s) {
    if (s.size() != 5) return 0;

    int bin = 0;

    // Index 0 -> bit 4 (MSB), index 4 -> bit 0 (LSB)
    for (int i = 0; i < 5; i++) {
        if (std::islower(static_cast<unsigned char>(s[i]))) {
            flipBit(bin, 4 - i);
        }
    }
    return bin;
}

// Decodes binary values to plaintext using charMap as a lookup table
std::string decipherBin(const std::vector<int> &input, const std::vector<char> &charMap) {
    std::string ret;
    for (int i : input) {
        try {
            ret.push_back(charMap.at(i));
        } catch (std::out_of_range& err) {
            std::cout << "Runtime Error: " << err.what() << "\n";
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
        std::cout << "Runtime Error: " << err.what() << "\n";
        return "";
    }

    while (std::getline(file, line)) {
        full.append(line);
    }
    return full;
}

int main() {
    std::string fileName, full, message;
    std::ifstream file;
    std::vector<int> bins;
    std::vector<std::string> parsedStrings;
    // Index = Baconian value (0-25 = A-Z), extended with punctuation and space
    const std::vector<char> charMap = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        '.', ';', '!', '?', '0', ' '};

    std::cout << "Enter File Name: ";
    std::getline(std::cin, fileName);
    fileName.append(".txt");

    full = readInFile(fileName, file);
    if (full.empty()) return 1;

    parseString(full, parsedStrings);                    // Step 1: tokenize
    for (const std::string& s : parsedStrings) {
        bins.push_back(stringToBin(s));
    }
    // Step 2: encode
    message = decipherBin(bins, charMap);                // Step 3: decode

    // Build output filename: strip ".txt", append "_result.txt"
    std::string outName = fileName.substr(0, fileName.size() - 4) + "_result.txt";

    std::ofstream outFile(outName);
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not create output file: " << outName << std::endl;
        return 1;
    }

    outFile << full << std::endl;
    outFile << message << std::endl;
    outFile.close();

    std::cout << "Result written to " << outName << std::endl;
    return 0;
}