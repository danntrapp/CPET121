/**************************************************************/
/*** Title: Vowels.cpp                                      ***/
/*** Description: Example of the switch statement           ***/
/**************************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(void)
{
	char inputLetter;

	cout << "Please enter your letter : ";
	cin >> inputLetter;

	switch (inputLetter) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u': cout << "Your letter is a lower case vowel" << endl;
		break;
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U': cout << "Your letter is a upper case vowel" << endl;
		break;
	default: cout << "Your letter must be a consonant" << endl;
	}

	return (0);
}
/**************************************************************/
