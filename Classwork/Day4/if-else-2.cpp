/**************************************************************/
/*** Title: if-else-2.cpp									***/
/*** Description: Example #2 of if-else statement			***/
/**************************************************************/
#include <iostream>			// Required for cin & cout
#include <cmath>			// Required for all math functions
#include <iomanip>			// Required for i/o formating

using namespace std;

int main(void)
{
	char temp_type;
	double temp, f_temp, c_temp;

	cout << "Enter The Temperature Following By A (F) or (C) : ";
	cin >> temp >> temp_type;

	cout << fixed << setprecision(2);

	if ((temp_type == 'F') || (temp_type == 'f')) {
		f_temp = temp;
		c_temp = (5.0 / 9.0) * (f_temp - 32.0);
		cout << "The Equivalent Temperature is :";
		cout << setw(8) << c_temp << " C" << endl;
	}
	else {
		c_temp = temp;
		f_temp = ((9.0 / 5.0) * c_temp) + 32.0;
		cout << "The Equivalent Temperature is :";
		cout << setw(8) << f_temp << " F" << endl;
	}

	return (0);
}
/**************************************************************/

