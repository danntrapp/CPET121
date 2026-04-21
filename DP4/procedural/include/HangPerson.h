#ifndef HANGPERSON_H
#define HANGPERSON_H


#include <string>
#include <fstream>

// Global Constants
const int MAX_WRONG = 8; // Maximum number of incorrect guesses
const std::string WORDS_FILE  = "D:/GitHub/CPET121/DP4/procedural/include/words_1.txt";    // Input word list file
const std::string RESULTS_FILE = "D:/GitHub/CPET121/DP4/procedural/include/results_1.txt"; // Output results log file




// Reads words from words_1.txt and returns one at random
std::string selectWord();


// Prints ASCII hangman gallows based on number of wrong guesses (0-8)
void displayGallow(int incorrectGuesses);

// Prints the masked word (asterisks for unguessed letters)
void displayWord(std::string maskedWord);

// Prompts user for a letter, validates it hasn't been guessed,
// updates guessedLetters, returns the chosen character
char gameInput(std::string& guessedLetters);

#endif // HANGPERSON_H