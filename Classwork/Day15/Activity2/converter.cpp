#include "converter.h"

#include <utility>
#include <string>

Converter::Converter(std::ifstream &input, std::ofstream &output,
                     std::string inputName, std::string outputName) :
                     m_fileReader(std::move(input)), m_fileWriter(std::move(output)),
                     m_inputName(std::move(inputName)), m_outputName(std::move(outputName)){}
void Converter::readIn() {
    try {
        std::string input;
        m_fileReader.open(m_inputName.c_str());
        if (!m_fileReader.is_open()) {
            throw std::runtime_error("Could not open file " + m_inputName);
        }
        while (std::getline(m_fileReader, input)) {
            for (char c : input) {
                m_input.push_back(c);
            }
        }
        m_fileReader.close();
    }   catch (std::runtime_error &e) {
        printf("%s", e.what());
    }
}

void Converter::convert() {
    for (int i = 0; i < m_input.size(); i++) {
        if (std::isalpha(m_input.at(i))) {
            m_input.at(i) = std::toupper(m_input.at(i));
        }
    }
}


void Converter::writeOut() {
    try {
        m_fileWriter.open(m_outputName.c_str());
        if (!m_fileWriter.is_open()) {
            throw std::runtime_error("Could not open file " + m_outputName);
        }
    }   catch (std::exception &e) {
        printf(e.what());
    }
    for (char c : m_input) {
        m_fileWriter << c;
    }
    m_fileWriter.close();
}


