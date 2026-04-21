//
// Created by danie on 4/16/2026.
//
#include "../include/HangPerson.h"
#include <iostream>

char HangPerson::gameInput() {
    char input;

    while (true) {
        std::cout << "  Guess a letter: ";
        std::cin >> input;
        input = static_cast<char>(tolower(input));

        if (!isalpha(input)) {
            std::cout << "  Invalid input. Please enter a letter." << std::endl;
            continue;
        }

        if (!this->m_prevGuesses.emplace(input).second) {
            std::cout << "  Already guessed. Try again." << std::endl;
            continue;
        }

        break;
    }
    std::ostringstream output;
    output << "The letter " << input;
    if (this->m_word.find(input) != std::string::npos) {
        this->m_result[this->m_word.find(input)] = input;
        output << " has been found!";

    } else {
        output << " was not found. The error count is " << this->m_wrongCount << ".";
        this->m_wrongCount++;
    }
    logGame(output);

    return input;
}
