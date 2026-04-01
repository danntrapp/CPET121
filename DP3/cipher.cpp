#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
#include <bitset>

std::vector<std::string> split(std::string fullLine) {
    
    for(int i = 0; i < fullLine.) {
        if(!std::isalpha(static_cast<int>(c))) {

        }
    }
}

void flipBit(int &bin, int pos) {
    bin ^= (1 << pos);
}
void stringToBin(std::string s, int& bin) {
    if(s.size() != 5) {
        std::cout << s << std::endl;
        throw std::runtime_error("Wrong size dummy");
    }
    for(int i = 0; i < 5; i++) {
        if(std::islower(static_cast<int>(s.at(i)))) {
            flipBit(bin, i);
        }
    }
}
std::string decipherBin(const std::vector<int> input) {
    std::string ret;
    for(int i : input) {
        if(i >= 0 && i < 26) {
            ret.push_back(static_cast<char>(i + 65));
        }
    }
    return ret;
}

int main() {
    //     std::string fileName;
    //     const std::map<int, char> decoderMap = {{0b11111, 'A'},  {0b11110, 'B'}, {0b00010, ''}, }
    std::vector<int> bins;

    std::string input = "HUmPT";
    bins.resize(1);
    stringToBin(input, bins.at(0));
    input = decipherBin(bins);
    std::cout << input; 

    return 0;
}
