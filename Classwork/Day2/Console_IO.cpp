/**************************************************************/
/*** Title: Console_IO.cpp                 					***/
/*** Description: cin & cout demo					        ***/
/**************************************************************/
#include <iostream>

using namespace std;

int main(void) {

	int a, b, c, d;	// note: not great variable name :)

	cout << "Enter A : ";
	cin >> a;

	cout << "Enter B : ";
	cin >> b;

	c = a + b;
	cout << a << " + " << b << " = " << c << endl;

	d = a - b;
	cout << a << " - " << b << " = " << d << endl;

	return (0);
}
/**************************************************************/
