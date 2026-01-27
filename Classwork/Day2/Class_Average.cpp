/**************************************************************/
/*** Title: Class_Average.cpp								***/
/*** Description: Calculates Class Average					***/
/**************************************************************/
#include <iostream>

using namespace std;

int main(void) {

	float average;
	float midtermExam;
	float finalExam;
	float problem1, problem2, problem3;
	float problemAverage;
	float project1, project2;
	float projectAverage;
	cout << "Enter Midterm Exam Grade: ";
	cin >> midtermExam;
	cout << "Enter Midterm Exam Grade: ";
	cin >> midtermExam;
	midtermExam = 82.0;// <- In future programs the user will enter this
	finalExam = 93.0;	// <- SAME

	problem1 = 92.0;	// <- SAME
	problem2 = 74.0;	// <- SAME
	problem3 = 86.0;	// <- SAME
	problemAverage = (problem1 + problem2 + problem3) / 3;

	project1 = 82.0;	// <- SAME
	project2 = 65.0;	// <- SAME
	projectAverage = (project1 + project2) / 2;

	// the equation for average was split onto two lines for readability
	average = (midtermExam * 0.15) + (finalExam * 0.15) +
		(problemAverage * 0.30) + (projectAverage * 0.40);

	cout << "Your class average is: " << average << endl;

	return (0);
}
/**************************************************************/
