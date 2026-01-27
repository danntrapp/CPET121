/**************************************************************/
/*** Title: Type_Conversion_2.cpp          					***/
/*** Description: Example of Explicit Casting or Coercion   ***/
/**************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {
	int x;
	float y;
	char z;

	/* Example #1 */
	x = 5;
	y = static_cast<float>(x);
	cout << "Example #1 (int -> float):" << endl;
	cout << fixed << setprecision(2);
	cout << setw(6) << x << setw(6) << y << endl;

	/* Example #2 */
	y = 2.6;
	x = static_cast<int>(y);
	cout << "\nExample #2 (float -> int):" << endl;
	cout << setw(6) << x << setw(6) << y << endl;

	/* Example #3 */
	y = 2.3;
	x = static_cast<int>(y);
	cout << "\nExample #3 (float -> int):" << endl;
	cout << setw(6) << x << setw(6) << y << endl;

	/* Example #4 */
	z = 'Q';
	x = static_cast<int>(z);
	cout << "\nExample #3 (char -> int):" << endl;
	cout << setw(6) << z << setw(6) << x << endl;

	return (0);
}
/**************************************************************/
