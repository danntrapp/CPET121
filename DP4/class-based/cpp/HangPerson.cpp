#include "HangPerson.h"
#include <iostream>
#include <fstream>
#include <filesystem>

//
// Created by danie on 4/20/2026.
//
HangPerson::HangPerson() {
    initDict();

    m_ofs.open(RESULTS_FILE);
    if (!m_ofs.is_open()) { throw std::runtime_error("Words file not found"); }
}

HangPerson::HangPerson(const HangPerson &): HangPerson() {
    initDict();
}

void HangPerson::initDict() {
    std::string word;
    std::ifstream ifs;

    try {
        ifs.open(WORDS_FILE);
        if (!ifs.is_open()) { throw std::runtime_error("Words file not found"); }
    } catch (std::runtime_error &e) {
        printf("Exception Occurred: %s\r\n", e.what());
    }

    auto validateInput = [](const std::string &input) -> bool {
        if (input.length() <= 4 || input.length() >= 8) return false;
        bool seen[256] = {false};

        for (const unsigned char c : input) {
            if (seen[c]) {
                return false;
            }
            seen[c] = true;
        }
        return true;
    };

    while (std::getline(ifs, word)) {
        if (validateInput(word))
            this->m_dict.emplace(word);
    }
}

void HangPerson::printAns() const {
    std::cout << std::endl << "The Word was: " << this->m_word << std::endl;
    this->m_ofs.close();
}

void HangPerson::logGame(const std::ostringstream& oss) const {
    this->m_ofs << oss.str() << std::endl;
}

bool HangPerson::gameWon() const{
    return m_result == m_word;
}

bool HangPerson::gameOver() const {
    bool lost = getNumWrongGuesses() > MAX_WRONG;
    bool won = gameWon();

    return lost || won;
}

