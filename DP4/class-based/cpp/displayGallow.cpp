//
// Created by danie on 4/16/2026.
//

#include <iostream>
#include <ostream>

#include "HangPerson.h"
#include <vector>

void HangPerson::displayGallow(int wrongGuesses) {
    const std::string& output = m_gallows.at(wrongGuesses);
    std::cout << output << std::endl;
}
void HangPerson::displayGallow() const {
    const std::string& output = m_gallows.at(getNumWrongGuesses());
    std::cout << output << std::endl;
}
int HangPerson::getNumWrongGuesses() const {return this->m_wrongCount;}


const std::vector<std::string> HangPerson::m_gallows = {
    "+      \n"
       "|      \n"
       "|      \n"
       "|      \n"
       "|      \n"
       "+-------\n",
    "+-------\n"
       "|      \n"
       "|      \n"
       "|      \n"
       "|      \n"
       "+-------\n",

       // 2 - crossbeam
       "+-------\n"
       "|      |\n"
       "|      \n"
       "|      \n"
       "|      \n"
       "+-------\n",

       // 3 - rope
       "+-------\n"
       "|      |\n"
       "|      O\n"
       "|      \n"
       "|      \n"
       "+-------\n",

       // 4 - head + body
       "+-------\n"
       "|      |\n"
       "|      O\n"
       "|      |\n"
       "|      \n"
       "+-------\n",

       // 5 - left arm
       "+-------\n"
       "|      |\n"
       "|      O\n"
       "|     /|\n"
       "|      \n"
       "+-------\n",

       // 6 - both arms
       "+-------\n"
       "|      |\n"
       "|      O\n"
       "|     /|\\\n"
       "|      \n"
       "+-------\n",

       // 7 - left leg
       "+-------\n"
       "|      |\n"
       "|      O\n"
       "|     /|\\\n"
       "|     / \n"
       "+-------\n",

       // 8 - both legs
       "+-------\n"
       "|      |\n"
       "|      O\n"
       "|     /|\\\n"
       "|     / \\\n"
       "+-------\n",
        };
