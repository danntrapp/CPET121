/**********************************************************/
/*** Title: Ops_Exp_Prec.cpp							***/
/*** Description: Demonstrate arithmetic operators,     ***/
/***              expressions, And operator precedence  ***/
/***              using predefined values.              ***/
/**********************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << fixed << setprecision(2);

    int a = 7;
    double result1 = a;
    cout << result1 << endl;

    double result2 = 5 + 2.5;
    cout << result2 << endl;

    double result3 = 9 / 2;
    cout << result3 << endl;

    double result4 = 9.0 / 2;
    cout << result4 << endl;

    double result5 = static_cast<double>(9) / 2;
    cout << result5 << endl;

    int result6 = 4.9;
    cout << result6 << endl;

    int result7 = (int)7.8;
    cout << result7 << endl;

    return 0;
}
/**********************************************************/