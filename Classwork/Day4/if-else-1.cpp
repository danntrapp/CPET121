/**************************************************************/
/*** Title: if-else-1.cpp									***/
/*** Description: Example #1 of if-else statement			***/
/**************************************************************/
#include <iostream>			// Required for cin & cout
#include <cmath>			// Required for all math functions
#include <iomanip>			// Required for i/o formating

using namespace std;

int main(void)
{
	double number;

	cout << "Number To Be Square-Rooted ==> ";
	cin >> number;

	cout << fixed << setprecision(2);	// output formating

	if (number < 0.0)
		cout << "The Number Must Be Positive!" << endl;
	else {
		cout << "The Square-Root Of ";
		cout << number << " is " << sqrt(number) << endl;
	}

	return (0);
}
/**************************************************************/