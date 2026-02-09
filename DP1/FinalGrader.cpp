#include <iostream>
#include <iomanip>
//defining consts, just makes it easier rather than checking pdf again and again
const int HW_NUM = 4;
const int HW_MAX_POINTS = 5;
const double HW_WEIGHT = 0.10;

const int LAB_NUM = 3;
const int LAB_MAX_POINTS = 20;
const double LAB_WEIGHT = 0.20;

const int MIDTERM_NUM = 1;
const int MIDTERM_MAX_POINTS = 100;
const double MIDTERM_WEIGHT = 0.25;

const int FINAL_NUM = 1; 
const int FINAL_POINTS = 200;
const double FINAL_WEIGHT = 0.30;

const double TERM_PAPER_WEIGHT = 0.10;

const double PARTICIPATION_WEIGHT = 0.05;
//vars to store each grade
double hwGrade, labGrade, midtermGrade, paperGrade, finalGrade, participationGrade;
//int arrays to store things with more than one assignment, standard ints for midterm and final
int hw[HW_NUM], lab[LAB_NUM], midterm, finalExam;
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
    hwGrade = grade(hw, HW_NUM, HW_MAX_POINTS);
    labGrade = grade(lab, LAB_NUM, LAB_MAX_POINTS);
    midtermGrade = (static_cast<double>(midterm) / MIDTERM_MAX_POINTS) * 100;
    finalGrade = (static_cast<double>(finalExam) / FINAL_POINTS) * 100;
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
    hwGrade *= HW_WEIGHT;
    labGrade *= LAB_WEIGHT;
    midtermGrade *= MIDTERM_WEIGHT;
    finalGrade *= FINAL_WEIGHT;
    paperGrade *= TERM_PAPER_WEIGHT;
    participationGrade *= PARTICIPATION_WEIGHT;

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