#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cctype>
#define SIZE 10


bool isVowl(char c) {
    switch(c) {
        case('a'):
        case('e'):
        case('i'):
        case('o'):
        case('u'):
            return true;
    }
    return false;
}
int main(void) {
    std::string fileName = "mary.txt";
    std::fstream file = std::fstream(fileName, std::fstream ::in | std::fstream::out | std::fstream::app);
    
    std::vector<std::string> data;
    std::string input;
    while(file >> input) {
        data.push_back(input);
    }
    for(std::string &s : data) {
        for(char &c : s) {
            if(isVowl(c)) {
                std::replace(s.begin(), s.end(), c, static_cast<char>(std::toupper(c)));
            }
        }
    }
    file.clear();
    file.flush();
    for(int i = 0; i < data.size() - 1; i++) {
        if((bool)isupper(static_cast<unsigned char>(data.at(i + 1).at(0))))  {
            file << data.at(i) << "\n";
        } else {
            file << data.at(i) << " ";
        }
    }

}