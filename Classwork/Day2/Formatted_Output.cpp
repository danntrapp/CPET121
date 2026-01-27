/**************************************************************/
/*** Title: Formatted_Output.cpp          					***/
/*** Description: Formatted cout					        ***/
/**************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {

	float a = 12.34567;
	float b = 9.872;

	cout << "Without Formating:" << endl;
	cout << a << endl;
	cout << b << endl;

	cout << "\nWith Fixed Formating:" << endl;
	cout << setw(10) << fixed << setprecision(3) << a << endl;
	cout << setw(10) << b << endl;

	cout << "\nWith Scientific Formating:" << endl;
	cout << setw(15) << scientific << setprecision(4) << a << endl;
	cout << setw(15) << setprecision(2) << b << endl;

	return (0);
}
/**************************************************************/