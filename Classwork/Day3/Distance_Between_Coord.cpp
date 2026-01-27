/**************************************************************/
/*** Title: Distance_Between_Coord.cpp   	                ***/
/*** Description: Calculates the distance between two       ***/
/***              sets of (x,y) coordinates with formatted  ***/
/***              output & user input                       ***/
/**************************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(void) {

	float x1, y1, x2, y2;
	float delta_x, delta_y, distance;

	cout << "X1= "; cin >> x1;
	cout << "Y1= "; cin >> y1;
	cout << "X2= "; cin >> x2;
	cout << "Y2= "; cin >> y2;

	delta_x = fabs(x2 - x1);
	delta_y = fabs(y2 - y1);
	distance = sqrt(pow(delta_x, 2.0) + pow(delta_y, 2.0));

	cout << fixed << setprecision(2);
	cout << "Distance = " << setw(8) << distance << "\n\n" << endl;

	return (0);
}
/**************************************************************/