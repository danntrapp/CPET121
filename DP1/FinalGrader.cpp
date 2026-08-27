#include <iostream>
#include <iomanip>
//defining consts, just makes it easier rather than checking PDF again and again
namespace GradingConsts {
    constexpr int HW_NUM = 4;
    constexpr int HW_MAX_POINTS = 5;
    constexpr double HW_WEIGHT = 0.10;

    constexpr int LAB_NUM = 3;
    constexpr int LAB_MAX_POINTS = 20;
    constexpr double LAB_WEIGHT = 0.20;

    constexpr int MIDTERM_NUM = 1;
    constexpr int MIDTERM_MAX_POINTS = 100;
    constexpr double MIDTERM_WEIGHT = 0.25;

    constexpr int FINAL_NUM = 1;
    constexpr int FINAL_POINTS = 200;
    constexpr double FINAL_WEIGHT = 0.30;

    constexpr double TERM_PAPER_WEIGHT = 0.10;

    constexpr double PARTICIPATION_WEIGHT = 0.05;
}
//vars to store each grade
double hwGrade, labGrade, midtermGrade, paperGrade, finalGrade, participationGrade;
//int arrays to store things with more than one assignment, standard ints for midterm and final
int hw[GradingConsts::HW_NUM], lab[GradingConsts::LAB_NUM], midterm, finalExam;
bool participation;     //participation is a boolean
char paper;             //char to store paper

double totGrade;        //the total grade (aka final grade, but I already have a var named that)
char letterGrade;       //char for final letter grade


using namespace GradingConsts;
int main() {
    //taking in all the grades for each assignment
    std::cin >> hw[0] >> hw[1] >> hw[2] >> hw[3];
    std::cin >> lab[0] >> lab[1] >> lab[2];
    std::cin >> midterm;
    std::cin >> finalExam;
    std::cin >> paper;
    std::cin >> participation;
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
        default:
            paperGrade = 0;
    }
    //setting output to fixed point and 2 decimal places of accuracy
    std::cout << std::fixed << std::setprecision(2);
    //small lambda to re-use for formatting each output.
    auto formatNPrint = [](const std::string &name, const double val) {
        std::cout << std::left << std::setw(21) << std::setfill('.') << name
         << " :" << std::right << std::setw(8) << std::setfill(' ') << val << std::endl;
    };
    //outputting the average grade for each category
    formatNPrint("Homework Average", hwGrade);
    formatNPrint("Laboratory Average", labGrade);
    formatNPrint("Midterm Exam", midtermGrade);
    formatNPrint("Final Exam", finalGrade);
    //setting precision to 0 places
    std::cout << std::setprecision(0) << std::fixed;
    std::cout << std::left << std::setw(21) << std::setfill('.') << "Term Paper"
         << " :" << std::right << std::setw(8) << std::setfill(' ') << paperGrade << " [" << paper << "]" << std::endl;

    formatNPrint("Class Participation", participationGrade);

    std::cout << std::setprecision(2) << std::fixed;
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
    formatNPrint("Class Average", totGrade);

    std::cout << std::left << std::setw(21) << std::setfill('.') << "Course Letter Grade"
         << " :" << std::right << std::setw(8) << std::setfill(' ') << letterGrade << std::endl;
    //if you got a D or lower output special message
    if(totGrade <= 70.0) {
        std::cout << "Please see your academic adviser." << std::endl;
    }

    return 0;

}