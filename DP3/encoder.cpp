#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <cctype>

void parseString(const std::string &fullLine, std::string &ret) {
    for (char c : fullLine) {   
        if (!std::isalpha(static_cast<unsigned char>(c)))
            continue;
        //if the char is alpha append it to input string
        ret.push_back(c);
    }
}
void createCipher(std::string &text, std::string &mess, const std::vector<char> charMap) {
    std::vector<uint8_t> bins;
    for(char c : mess) {
        char upperC = std::toupper(static_cast<unsigned char>(c));
        uint8_t pos = 0;
        bool found = false;
        for(uint8_t i = 0; i < charMap.size(); i++) {
            if(charMap[i] == upperC) {
                pos = i;
                found = true;
                break;
            }
        }
        if(found) {
            bins.push_back(pos);
        }
    }
    
    std::string parsed;
    parseString(text, parsed);
    int chars = parsed.size() / 5;
    if(chars < mess.size()) {
        printf("Need %i more chars to encode this message\r\n", (mess.size() - chars) * 5);
        return;
    }

    std::vector<int> alphaPos;
    for(int i = 0; i < text.size(); i++) {
        if(std::isalpha(static_cast<unsigned char>(text[i]))) {
            alphaPos.push_back(i);
        }
    }

    int index = 0;
    for(uint8_t binVal : bins) {

        for(int bit = 0; bit < 5; bit++) {
            int textPos = alphaPos[index * 5 + bit];
            if(binVal & (1 << (4 - bit))) {
                text[textPos] = std::tolower(static_cast<unsigned char>(text[textPos]));
            } else {
                text[textPos] = std::toupper(static_cast<unsigned char>(text[textPos]));
            }
        }
        index++;
    }
}

int main(void) {
    std::ofstream ofFile;
    std::string message, full;
    const std::vector<char> charMap = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G',
    'H', 'I', 'J', 'K', 'L', 'M', 'N',
    'O', 'P', 'Q', 'R', 'S', 'T', 'U', 
    'V', 'W', 'X', 'Y', 'Z', '.', ';', 
    '!', '?', '0', ' '};

    std::cout << "Message to encode: ";
    std::getline(std::cin, message);
    std::cout << "Text to encode message into: ";
    std::getline(std::cin, full);
    createCipher(full, message, charMap);
    ofFile.open("lauda.txt");
    ofFile << full;
    ofFile.close();
}