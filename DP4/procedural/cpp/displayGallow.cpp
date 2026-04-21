#include <iostream>
#include <ostream>

#include "HangPerson.h"
#include <vector>
const std::vector<std::string> gallows = {
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

       // 9 - game over (same as 7, main will print loss message)
       "+-------\n"
       "|      |\n"
       "|      O\n"
       "|     /|\\\n"
       "|     / \\\n"
       "+-------\n",
        };
void displayGallow(int wrongGuesses) {
    const std::string& output = gallows.at(wrongGuesses);
    std::cout << output << std::endl;
}

