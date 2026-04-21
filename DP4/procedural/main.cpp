// ============================================================
// main.cpp
// HangPerson - CPET-121 Project #4
//
// Controls the overall game flow:
//   1. Selects a secret word
//   2. Loops: display gallows, display word, get input
//   3. Updates masked word and wrong-guess counter
//   4. Logs every turn result to results_1.txt
//   5. Ends when word is guessed or 8 wrong guesses reached
// ============================================================

#include "HangPerson.h"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // --------------------------------------------------------
    // Game initialization
    // --------------------------------------------------------
    std::string secretWord   = selectWord();  // The word to guess
    std::string maskedWord   = std::string(secretWord.length(), '*'); // All asterisks
    std::string guessedLetters = "";          // Letters guessed so far
    int         wrongCount   = 0;             // Number of incorrect guesses

    // Open the results log file
    std::ofstream logFile(RESULTS_FILE);
    if (!logFile.is_open())
    {
        std::cerr << "ERROR: Could not open " << RESULTS_FILE << std::endl;
        return 1;
    }

    // Log the chosen word
    logFile << "The chosen word is " << secretWord << "." << std::endl << std::endl;

    std::cout << std::endl;
    std::cout << "  =============================" << std::endl;
    std::cout << "       Welcome to HangPerson!  " << std::endl;
    std::cout << "  =============================" << std::endl << std::endl;
    while (wrongCount < MAX_WRONG && maskedWord != secretWord)
    {
        // Display current gallows state
        displayGallow(wrongCount);

        // Display current word state
        displayWord(maskedWord);

        // Show wrong guess count
        std::cout << "  Wrong guesses: " << wrongCount << " / " << MAX_WRONG << std::endl;

        // Get a valid new letter from the user
        char guess = gameInput(guessedLetters);

        // Check if the guess is in the secret word
        bool found = false;
        for (int i = 0; i < static_cast<int>(secretWord.length()); i++)
        {
            if (secretWord[i] == guess)
            {
                maskedWord[i] = guess;   // Reveal letter in masked word
                found = true;
            }
        }

        std::cout << std::endl;

        // Update wrong count and log the result
        if (found)
        {
            logFile << "The character " << guess << " was found!" << std::endl;
        }
        else
        {
            wrongCount++;
            logFile << "The character " << guess
                    << " was not found! The error count is " << wrongCount << "." << std::endl;
        }
    }
    displayGallow(wrongCount);
    displayWord(maskedWord);
    if (maskedWord == secretWord)
    {
        std::cout << "  Congratulations!!! You Won!!!" << std::endl;
        logFile << std::endl << "The user successfully found the word." << std::endl;
    }
    else
    {
        std::cout << "  Sorry, you've lost. :(" << std::endl;
        std::cout << "  The secret word was: " << secretWord << std::endl;
        logFile << std::endl << "The user failed to find the word." << std::endl;
    }

    logFile.close();
    std::cout << std::endl;
    std::cout << "  Results saved to " << RESULTS_FILE << std::endl;
    std::cout << "  Press Enter to continue...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}