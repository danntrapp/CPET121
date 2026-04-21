//
// Created by danie on 4/14/2026.
//

#ifndef ACTIVITY2_CONVERTER_H
#define ACTIVITY2_CONVERTER_H
#include <string>
#include <vector>
#include <fstream>

class Converter {
public:
    Converter(std::ifstream &input, std::ofstream &output, std::string inputName, std::string outputName);

    void readIn();

    void writeOut();
    void convert();

private:

    std::vector<char> m_input;
    std::ifstream m_fileReader;
    std::ofstream m_fileWriter;
    std::string m_inputName;
    std::string m_outputName;
};

#endif //ACTIVITY2_CONVERTER_H