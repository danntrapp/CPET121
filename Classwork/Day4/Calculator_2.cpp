/**************************************************************/
/*** Title: Calculator_2.cpp								***/
/*** Description: Simple four function calculator using		***/
/****			  a switch statement						***/
/**************************************************************/
#include <iostream>			// Required for cin & cout
#include <cmath>			// Required for all math functions
#include <iomanip>			// Required for i/o formating

using namespace std;

int main(void)
{
	double operand_x, operand_y, answer;
	char opselect;

	cout << "Enter Your Two Numbers : ";
	cin >> operand_x >> operand_y;

	cout << "Enter The Operation:";
	cout << "\nA: Addition \nS: Subtraction \nM: Multiply \nD: Divide : ";
	cin >> opselect;

	cout << fixed << setprecision(2);
	switch (opselect) {
	case 'A': answer = operand_x + operand_y;
		cout << operand_x << " + " << operand_y;
		cout << " = " << answer << endl;
		break;
	case 'S': answer = operand_x - operand_y;
		cout << operand_x << " - " << operand_y;
		cout << " = " << answer << endl;
		break;
	case 'M': answer = operand_x * operand_y;
		cout << operand_x << " * " << operand_y;
		cout << " = " << answer << endl;
		break;
	case 'D': if (operand_y != 0)
	{
		answer = operand_x / operand_y;
		cout << operand_x << " / " << operand_y << " = " << answer << endl;
	}
			else
		cout << "DIVIDE BY ZERO DETECTED\n" << endl;
		break;
	default: cout << "Illegal Operation\n" << endl;
	}

	return (0);
}
/**************************************************************/
