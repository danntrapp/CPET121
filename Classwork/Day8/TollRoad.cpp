#include <iostream>
#include <iomanip>
using namespace std;

double CalcToll(char time, char day, int hour) {
    double toll;
    day = tolower(day);
    time = tolower(time);
    bool weekday = day == 'd';
    if(time == 'p')
        hour += 12;
    if(weekday) {
        if(hour < 7) {
            toll = 1.15;
        } else if(hour < 10) {
            toll = 2.95;
        } else if(hour < 15) {
            toll = 1.9;
        } else if(hour < 20) {
            toll = 3.95;
        } else if(hour > 24 || hour < 0) {
            cout << "Invalid time given" << endl;
            return 0;
        }
    } else {
        if(hour < 7) {
            toll = 1.05;
        } else if(hour < 20) {
            toll = 2.15;
        } else {
            toll = 1.1;
        }
    }
    return toll;
}

int main(void) {
    char day, time;
    int hour;
    cout << "Enter hour: ";
    cin >> hour;
    cout << "Enter AM/PM [A/P]: ";
    cin >> time;
    cout << "Enter Weekend/Weekday [E/D]: ";
    cin >> day;
    double toll = CalcToll(time, day, hour);
    cout << "Toll: $" << toll << endl;
}