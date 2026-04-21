#include "hangPerson.h"
#include <iostream>
#include <cctype>

char gameInput(std::string& guessedLetters)
{
    char guess;

    while (true)
    {
        // Show previously guessed letters if any exist
        if (!guessedLetters.empty())
        {
            std::cout << "  Guessed: ";
            for (int i = 0; i < static_cast<int>(guessedLetters.length()); i++)
            {
                std::cout << guessedLetters[i];
                if (i < static_cast<int>(guessedLetters.length()) - 1)
                    std::cout << ", ";
            }
            std::cout << std::endl;
        }

        std::cout << "  Guess a letter: ";
        std::cin >> guess;

        // Convert to lowercase for uniform comparison
        guess = static_cast<char>(tolower(guess));

        // Validate it is an alphabetic character
        if (!isalpha(guess))
        {
            std::cout << "  Invalid input. Please enter a letter." << std::endl << std::endl;
            continue;
        }

        // Check if already guessed
        if (guessedLetters.find(guess) != std::string::npos)
        {
            std::cout << "  '" << guess << "' has already been guessed. Try again." << std::endl << std::endl;
            continue;
        }

        // Valid new guess — add to list and return
        guessedLetters += guess;
        break;
    }

    return guess;
}