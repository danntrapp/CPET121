#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
using namespace std;
int main() {
    int creds;
    int years;
    bool fiveYear = false;
    string s;
    cout << "Num Credits: ";
    cin >> creds;
    cout << "How many years is your program: ";
    cin >> years;
    if(years == 4)
        fiveYear = false;
    else if(years == 5) 
        fiveYear = true;
    else {
        cout << "jump" << endl;
        return 0;
    }

    if((creds > 0) && (creds < 27))
        s = "First year";
    else if(creds < 55)
        s = "second year";
    else if((creds < 0) && (creds > 95)) {
        cout << "You're a bum";
        return(0);
    } else if(!fiveYear) {
        if(creds <= 84)
            s = "second year";
        else if(creds > 84)
            s = "Fourth year";
    } else if(creds <= 75 ) 
        s = "Fourth year";
    else if(creds >= 95)
        s = "Fifth year";
    
    cout << s << endl;
    
}