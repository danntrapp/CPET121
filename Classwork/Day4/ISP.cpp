#include <iostream>
/*
Class Activity : Internet Service Provider – Specifications
An ISP has three different subscription packages for its customers:
– Package X : $9.95 per month for 10 hours of access. Each additional hour is
$2.00 per hour.
– Package Y : $14.95 per month for 20 hours of access. Each additional hour is
$1.00 per hour.
– Package Z : $19.95 per month for unlimited access.
Write a C++ program that reads in the customer’s service package (X, Y,
Z) and the number of hours they have used. Using this information, the
program should calculate the total bill.*/
using namespace std;
int main() {
    char package;
    double rate;
    double extraRate;
    double bill;
    int hours;
    int userHours;

    cout << "Package: ";
    cin >> package;
    cout << "Num hours: ";
    cin >> userHours;
    auto calculateBill = [] (int userHours, double rate, double extraRate, int hours) -> double {
        double bill;
        if(userHours >= hours) {
            bill = rate;
            userHours -= hours;
            bill += userHours * extraRate;
        } else {
            bill += rate * hours;
        }
        return bill;
    };
    switch(package) {
        case('X'):
            rate = 9.95;
            extraRate = 2.00;
            hours = 10;
            bill = calculateBill(userHours, rate, extraRate, hours);
            break;
        case('Y'):
            rate = 14.95;
            extraRate = 1.00;
            hours = 20;
            bill = calculateBill(userHours, rate, extraRate, hours);
            break;
        case('Z'):
            rate = 19.95;
            bill = rate;
            break;
    }

    cout << "Final bill is: " << bill << endl;


}