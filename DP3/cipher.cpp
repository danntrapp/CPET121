#include <cctype>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>


//intakes full line to parse and the vector to place the parsed strings into
void parseString(const std::string &fullLine, std::vector<std::string> &vec) {
    std::string input;
    //for each char in the string fullLine check if alpha
    for (char c : fullLine) {   
        if (!std::isalpha(static_cast<unsigned char>(c)))
            continue;
        //if the char is alpha append it to input string
        input.push_back(c);      
        //if the string is of size 5 append the string to the vec and clear input
        if (input.size() == 5) {   
            vec.push_back(input);   
            input.clear();
        }
    }
}

uint8_t stringToBin(const std::string &s) {
    //check if size is valid
    if (s.size() != 5) {
        return 0;
    }
    //inital binary num
    uint8_t bin = 0;

    //helper function to flip bit, passes the num to change and index of bit
    auto flipBit = [](uint8_t &bin, int pos) {
        bin ^= (1 << pos);
    };
    //for each char in the string if it is lower flip the bit at its corresponding location
    for (int i = 0; i < 5; i++) {
        if (std::islower(static_cast<unsigned char>(s[i]))) {
            flipBit(bin, 4 - i);
        }
    }
    return bin;
}
std::string decipherBin(const std::vector<uint8_t> &input, const std::vector<char> &charMap) {
    //defining return var
    std::string ret;
    //defining the cipherMap
    //for each bin input to cipher map as key then return val
    for(uint8_t i : input) {
        try {
            auto c = charMap.at(i);
            ret.push_back(c);
        } catch(std::out_of_range& err) {
            printf("Runtime Error: %s\n", err.what());
        }
    }
    return ret;
}

std::string readInFile(const std::string& fileName, std::ifstream &file) {
    std::string full, line;
    try {
        file.open(fileName.c_str());
        if(!file.is_open()) throw std::runtime_error("File could not be opened");
    } catch(std::runtime_error &err) {
        printf("Runtime Error: %s\n", err.what());
        return nullptr;
    }

    while(std::getline(file, line)) {
        full.append(line);
    }
    return full;
}

int main() {
    std::string fileName, full, message;
    std::ifstream file;
    std::vector<uint8_t> bins;
    std::vector<std::string> parsedStrings;
    
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
    parseString(full, parsedStrings);
    for(std::string s : parsedStrings) {
        bins.push_back(stringToBin(s));
    }
    message = decipherBin(bins, charMap);

    std::cout << message << std::endl;
    return 0;
}
