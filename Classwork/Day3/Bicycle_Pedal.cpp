/**************************************************************/
/*** Title: Bicycle_Pedal.cpp								***/
/*** Description: Calculates the required radius for a bike	***/
/***	          pedal given a set of parameters			***/
/***														***/
/**************************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(void) {

	const double PI = 3.14159;

	double radius;	// radius of cylindrical rod in inches
	double length;	// length of crank arm in inches
	double weight;	// weight placed on the pedal in lbs
	double stress;	// stress in lbs/in2
	double temp;

	length = 7.0;
	weight = 300.0;
	stress = 10000.0;

	temp = (length * weight) / (PI * stress);

	radius = pow(temp, 0.3333);

	radius = pow(((length * weight) / (PI * stress)), 0.3333);

	cout << fixed << setprecision(3);
	cout << "Radius = " << setw(7) << radius << " inches \n" << endl;

	return (0);
}
/**************************************************************/


// radius = pow(((length * weight) / (PI * stress)), 0.3333);
