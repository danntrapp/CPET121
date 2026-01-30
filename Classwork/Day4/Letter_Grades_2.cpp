/**************************************************************/
/*** Title: Letter_Grades_2.cpp                             ***/
/*** Description: Determines a students letter grade        ***/
/***              based on a numerical grade.               ***/
/**************************************************************/
#include <iostream>			// Required for cin & cout
#include <cmath>			// Required for all math functions
#include <iomanip>			// Required for i/o formating

using namespace std;

int main(void)
{
	int numGrade;
	char letterGrade;

	cout << "Please enter your numerical grade (0-100) : ";
	cin >> numGrade;

	if (numGrade >= 90) {
		letterGrade = 'A';
	}
	else if (numGrade >= 80) {
		letterGrade = 'B';
	}
	else if (numGrade >= 70) {
		letterGrade = 'C';
	}
	else if (numGrade >= 60) {
		letterGrade = 'D';
	}
	else {
		letterGrade = 'F';
	}

	cout << "\nYour Number Grade: " << setw(3) << numGrade;
	cout << "; Is Equivalent To A : " << setw(2) << letterGrade << endl;

	return (0);
}
/**************************************************************/