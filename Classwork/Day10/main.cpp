/**********************************************************/
/*** Title: main.cpp                 					***/
/*** Description: main code for leap year test        	***/
/**********************************************************/
#include <iostream>
using namespace std;

bool Leap_Test(int year) {
    if(year % 4 == 0) {
        if(year % 100 != 0) {
            return true;
        } else if(year % 400 == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int year;

    cin >> year;


    cout << year;
    if (Leap_Test(year))
        cout << " is ";
    else
        cout << " is NOT ";
    cout << "a leap year" << endl;

    return 0;
}
/**********************************************************/
