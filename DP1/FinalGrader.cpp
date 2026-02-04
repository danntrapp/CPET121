//#include "Assignment.hpp"
#include <iostream>
#include <iomanip>



const int hwNum = 4;
const int hwMaxPoints = 5;
const double hwWeight = 0.10;

const int labNum = 3;
const int labMaxPoints = 20;
const double labWeight = 0.20;

const int midtermNum = 1;
const int midtermMaxPoints = 100;
const double midtermWeight = 0.25;

const int finalNum = 1;
const int finalPoints = 200;
const double finalWeight = 0.30;

const double termPaperWeight = 0.10;

const double participationWeight = 0.05;

double hwGrade, labGrade, midtermGrade, paperGrade, finalGrade, participationGrade;

int hw[hwNum], lab[labNum], midterm, finalExam;
bool participation;
char paper;

double totGrade;
char letterGrade;


using namespace std;
int main() {
    
    cin >> hw[0] >> hw[1] >> hw[2] >> hw[3];
    cin >> lab[0] >> lab[1] >> lab[2];
    cin >> midterm;
    cin >> finalExam;
    cin >> paper;
    cin >> participation;

    auto grade = [](int arr[], int size, int maxPts) {
        double grade = 0.0;
        for(int i = 0; i < size; i++) {
            grade += (static_cast<double>(arr[i]) / maxPts) * 100;
        }
        grade /= size;
        return grade;
    };

    hwGrade = grade(hw, hwNum, hwMaxPoints);
    labGrade = grade(lab, labNum, labMaxPoints);
    midtermGrade = (static_cast<double>(midterm) / midtermMaxPoints) * 100;
    finalGrade = (static_cast<double>(finalExam) / finalPoints) * 100;
    participationGrade = static_cast<int>(participation) * 100;

    switch(paper) {
        case 'A':
        case 'a':
            paperGrade = 95;
            break;
        case 'B':
        case 'b':
            paperGrade = 85;
            break;
        case 'C':
        case 'c':
            paperGrade = 75;
            break;
        case 'D':
        case 'd':
            paperGrade = 65;
            break;
        case 'F':
        case 'f':
            paperGrade = 55;
            break;
    }

        cout << fixed << setprecision(2);

    cout << left << setw(21) << setfill('.') << "Homework Average"
         << ": " << right << setw(8) << setfill(' ') << hwGrade << endl;
    cout << left << setw(21) << setfill('.') << "Laboratory Average"
         << ": " << right << setw(8) << setfill(' ') << labGrade << endl;

    cout << left << setw(21) << setfill('.') << "Midterm Exam"
         << ": " << right << setw(8) << setfill(' ') << midtermGrade << endl;

    cout << left << setw(21) << setfill('.') << "Final Exam"
         << ": " << right << setw(8) << setfill(' ') << finalGrade << endl;
         

    cout << left << setw(21) << setfill('.') << "Term Paper"
         << ": " << right << setw(8) << setfill(' ') << paperGrade << "[" << paper << "]" << endl;

    cout << left << setw(21) << setfill('.') << "Class Participation"
         << ": " << right << setw(8) << setfill(' ') << participationGrade << endl;

    hwGrade *= hwWeight;
    labGrade *= labWeight;
    midtermGrade *= midtermWeight;
    finalGrade *= finalWeight;
    paperGrade *= termPaperWeight;
    participationGrade *= participationWeight;

    totGrade = hwGrade + labGrade + midtermGrade + finalGrade + paperGrade + participationGrade;

    if(totGrade >= 90.0) {
        letterGrade = 'A';
    } else if(totGrade >= 80.0) {
        letterGrade = 'B';
    } else if(totGrade >= 70.0) {
        letterGrade = 'C';
    } else if(totGrade >= 60.0) {
        letterGrade = 'D';
    } else {
        letterGrade = 'F';
    }

    cout << left << setw(21) << setfill('.') << "Class Average"
         << ": " << right << setw(8) << setfill(' ') << totGrade << endl << endl;;

    cout << left << setw(21) << setfill('.') << "Course Letter Grade"
         << ": " << right << setw(8) << setfill(' ') << letterGrade << endl;
    

    return 0;
}