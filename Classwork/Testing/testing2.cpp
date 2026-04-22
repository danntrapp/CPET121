//
// Created by danie on 4/22/2026.
//
#include <iostream>
#include <string>

struct grade {
    double weight;
    double grade;
    char n;
};

int main() {
    grade grades[5] {{10, 10, 't'},
                    {10, 7.73, 'w'},
                    {15, (5.81 + (1.67*3)), 'q'}};
    double final = 0;
    double totWeight = 0;
    double exams = (11.73 + 10.8 + 18)/3.0;
    grades[3] = {40, exams, 'e'};
    grades[4] = {25, 22, 'f'};

    for (grade g : grades) {
        final += g.grade;
        totWeight += g.weight;
    }
    printf("Grade: %f", (final/totWeight));
}