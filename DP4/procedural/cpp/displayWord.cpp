#include "hangPerson.h"
#include <iostream>

void displayWord(std::string maskedWord)
{
    std::cout << "  Word: ";
    for (int i = 0; i < static_cast<int>(maskedWord.length()); i++)
    {
        std::cout << maskedWord[i];
        if (i < static_cast<int>(maskedWord.length()) - 1)
            std::cout << " ";
    }
    std::cout << std::endl << std::endl;
}