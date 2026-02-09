#include <iostream>
#include <iomanip>
//defining consts, just makes it easier rather than checking pdf again and again
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
//vars to store each grade
double hwGrade, labGrade, midtermGrade, paperGrade, finalGrade, participationGrade;
//int arrays to store things with more than one assignment, standard ints for midterm and final
int hw[hwNum], lab[labNum], midterm, finalExam;
bool participation;     //participation is a boolean
char paper;             //char to store paper

double totGrade;        //the total grade (aka final grade but I already have a var named that)
char letterGrade;       //char for final letter grade


using namespace std;
int main() {
    //taking in all the grades for each assignment
    cin >> hw[0] >> hw[1] >> hw[2] >> hw[3];
    cin >> lab[0] >> lab[1] >> lab[2];
    cin >> midterm;
    cin >> finalExam;
    cin >> paper;
    cin >> participation;
    /*  little lambda function to use for hw and lab to make it easier
        intakes an arr of ints, the size of the arr and the max pts each assignment can get */
    auto grade = [](int arr[], int size, int maxPts) {
        //initializing return val
        double grade = 0.0; 
        /*  iterating through the array, casting the ints to doubles, then dividing
            by max points and multiplying by 100 to find the percent grade. Then they
            are added to grade. */
        for(int i = 0; i < size; i++) {
            grade += (static_cast<double>(arr[i]) / maxPts) * 100;
        }
        //dividing the sum of all grades by the number of assignments to determine avg
        grade /= size;
        return grade;
    };
    //grading all the assignments out of 100%
    hwGrade = grade(hw, hwNum, hwMaxPoints);
    labGrade = grade(lab, labNum, labMaxPoints);
    midtermGrade = (static_cast<double>(midterm) / midtermMaxPoints) * 100;
    finalGrade = (static_cast<double>(finalExam) / finalPoints) * 100;
    participationGrade = static_cast<int>(participation) * 100;
    //switch case for the paper to determine numerical grade
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
    //setting output to fixed point and 2 decimal places of accuracy
    cout << fixed << setprecision(2);
    //outputting the average grade for each category
    cout << left << setw(21) << setfill('.') << "Homework Average"
         << " :" << right << setw(8) << setfill(' ') << hwGrade << endl;
    cout << left << setw(21) << setfill('.') << "Laboratory Average"
         << " :" << right << setw(8) << setfill(' ') << labGrade << endl;

    cout << left << setw(21) << setfill('.') << "Midterm Exam"
         << " :" << right << setw(8) << setfill(' ') << midtermGrade << endl;

    cout << left << setw(21) << setfill('.') << "Final Exam"
         << " :" << right << setw(8) << setfill(' ') << finalGrade << endl;
         
    cout << setprecision(0) << fixed;
    cout << left << setw(21) << setfill('.') << "Term Paper"
         << " :" << right << setw(8) << setfill(' ') << paperGrade << " [" << paper << "]" << endl;

    cout << left << setw(21) << setfill('.') << "Class Participation"
         << " :" << right << setw(8) << setfill(' ') << participationGrade << endl;
    cout << setprecision(2) << fixed;
    //multiply each grade by their weight and then sum all to determine final grade
    hwGrade *= hwWeight;
    labGrade *= labWeight;
    midtermGrade *= midtermWeight;
    finalGrade *= finalWeight;
    paperGrade *= termPaperWeight;
    participationGrade *= participationWeight;

    totGrade = hwGrade + labGrade + midtermGrade + finalGrade + paperGrade + participationGrade;
    //determining final letter grade using if else
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
    //outputting the final grade in numerical and letter form
    cout << left << setw(21) << setfill('.') << "Class Average"
         << " :" << right << setw(8) << setfill(' ') << totGrade << endl << endl;;

    cout << left << setw(21) << setfill('.') << "Course Letter Grade"
         << " :" << right << setw(8) << setfill(' ') << letterGrade << endl;
    //if you got a D or lower output special message
    if(totGrade <= 70.0) {
        cout << "Please see your academic adviser." << endl;
    }

    return 0;

}