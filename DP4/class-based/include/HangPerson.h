#ifndef HANGPERSON_H
#define HANGPERSON_H

#include <string>
#include <unordered_set>
#include <vector>
#include <fstream>
#include <sstream>
class HangPerson {
public:
    HangPerson(const HangPerson&);
    HangPerson();

    void initDict();

    bool selectWord();

    bool selectWord(std::string word);

    bool gameWon() const;

    bool gameOver() const;

    // Displays the hangman gallows corresponding to the number of wrong guesses
    static void displayGallow(int wrongGuesses);
    void displayGallow() const;

    // Displays the current state of the word (letters guessed so far, * if unknown)
    static void displayWord(const std::string& displayStr);
    void displayWord() const;

    int getNumWrongGuesses() const;

    void printAns() const;

    void logGame(const std::ostringstream& oss) const;

    // Prompts the user for a letter guess, validates it against previously guessed letters,
    // re-prompts if already guessed (does NOT count as a missed guess)
    // guessedLetters: list of all previously guessed characters (updated in place)
    // returns: the new valid guessed character
    char gameInput();

    static constexpr int MAX_WRONG = 8;   // game ends after 8 incorrect guesses
    static constexpr char HIDDEN_CHAR = '*';     // placeholder for unguessed letters
private:

    const std::string WORDS_FILE = "D:/GitHub/CPET121/DP4/class-based/include/io/dict.txt";
    const std::string RESULTS_FILE = "D:/GitHub/CPET121/DP4/class-based/include/io/output.txt";
    std::unordered_set<std::string> m_dict;
    int m_wrongCount = 0;
    std::string m_word;
    std::string m_result;
    std::unordered_set<char> m_prevGuesses;
    static const std::vector<std::string> m_gallows;
    mutable std::ofstream m_ofs;
};
#endif // HANGPERSON_H