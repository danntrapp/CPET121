//
// Created by danie on 4/16/2026.
//
#include "../include/HangPerson.h"
#include <iostream>

void HangPerson::displayWord(const std::string &displayStr) {
    std::cout << "  Word: ";
    for (int i = 0; i < static_cast<int>(displayStr.length()); i++)
    {
        std::cout << displayStr[i];
        if (i < static_cast<int>(displayStr.length()) - 1)
            std::cout << " ";
    }
    std::cout << std::endl << std::endl;
}
void HangPerson::displayWord() const {
    if (!m_prevGuesses.empty()) {
        std::cout << "  Guessed: ";
        int i = 0;
        for (char c : m_prevGuesses) {
            std::cout << c;
            if (i < m_prevGuesses.size() - 1) std::cout << ", ";
            i++;
        }
        std::cout << std::endl;
    }
    std::cout << "  Word: ";
    for (int i = 0; i < static_cast<int>(m_result.length()); i++)
    {
        std::cout << m_result[i];
        if (i < static_cast<int>(m_result.length()) - 1)
            std::cout << " ";
    }
    std::cout << std::endl << std::endl;
    std::cout << "  Wrong guesses: " << getNumWrongGuesses() << " / " << MAX_WRONG << std::endl;
}
