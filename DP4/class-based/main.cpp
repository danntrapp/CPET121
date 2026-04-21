//
// Created by danie on 4/16/2026.
//
#include "HangPerson.h"
#include <iostream>
int main() {
    HangPerson h = HangPerson();
    std::ostringstream output;
    h.selectWord();
    while (!h.gameOver()) {
        h.displayGallow();
        h.displayWord();
        h.gameInput();
        std::cout << "\r\n";
    }
    std::string result = h.gameWon() ? "You Won!\n" : "You Lose!\n";
    std::cout << result << std::endl;
    output << result;
    h.logGame(output);
    h.printAns();
}