#ifndef MULTISIDED_DIE
#define MULTISIDED_DIE
#include <iostream>

class MultiSidedDie {
    public:
    MultiSidedDie(int numSides) : m_numSides(numSides) {}

    int roll() {
        srand(time(NULL));
        return (rand() % m_numSides) + 1;
    }

    void print() {
        printf("Roll: %i\n", roll());
    }

    private:
    unsigned int m_numSides;
    

};
#endif