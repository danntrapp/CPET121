#include "../include/HangPerson.h"
#include <fstream>
#include <iostream>
#include <random>

bool HangPerson::selectWord() {
        if (m_dict.empty()) {
                throw std::runtime_error("Dictionary is empty");
        }
        std::srand(time(nullptr));
        std::vector<std::string> words(m_dict.begin(), m_dict.end());

        int index = rand() % words.size();
        this->m_word = words[index];
        m_result.resize(m_word.size());
        for (char& c : m_result) {
                c = '*';
        }
        std::ostringstream output;
        output << "The word chosen is: " + this->m_word;
        logGame(output);
        return true;
}


