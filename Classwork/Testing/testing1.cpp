#include <fstream>
#include <string>
#include <set>
#include <cstdint>
#include <iostream>

int main() {

    constexpr uint8_t MIN_WORD_LENGTH = 4;
    constexpr uint8_t MAX_WORD_LENGTH = 8;

    std::ifstream fileIn("dict.txt");
    std::ofstream fileOut("out.txt");

    if (!fileIn.is_open()) {
        std::cerr << "Could not open dict.txt\n";
        return -1;
    }
    if (!fileOut.is_open()) {
        std::cerr << "Could not open out.txt\n";
        return -1;
    }

    std::string line;
    while (std::getline(fileIn, line)) {
        if (line.length() < MIN_WORD_LENGTH || line.length() > MAX_WORD_LENGTH)
            continue;

        // Check for duplicate letters
        std::set<char> seen(line.begin(), line.end());
        if (seen.size() != line.size())
            continue;

        fileOut << line << "\n";
        std::cout << line << "\n";
    }

    fileIn.close();
    fileOut.close();
    return 0;
}
