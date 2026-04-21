// ============================================================
// selectWord.cpp
// Reads all words from words_1.txt into a vector, then
// selects and returns one at random.
// ============================================================

#include "hangPerson.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
std::string selectWord()
{
        std::ifstream inFile(WORDS_FILE);

        //Validate file opened successfully
        if (!inFile.is_open())
        {
                std::cerr << "ERROR: Could not open " << WORDS_FILE << std::endl;
                exit(1);
        }

        // Read all words into a vector
        std::vector<std::string> wordList;
        std::string word;
        while (inFile >> word)
        {
                wordList.push_back(word);
        }
        inFile.close();

        //Validate word list is not empty
        if (wordList.empty())
        {
                std::cerr << "ERROR: " << WORDS_FILE << " is empty." << std::endl;
                exit(1);
        }

        //Seed random number generator and select a word
        srand(static_cast<unsigned int>(time(nullptr)));
        int index = rand() % static_cast<int>(wordList.size());

        return wordList[index];
}