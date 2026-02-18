#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;
int main(void) {
    string s;
    getline(cin, s);
    int nonAlphaNum = 0;
    for(char c : s) {
        if(!isalpha(c)) {
            nonAlphaNum++;
        }
    }
    cout << s.size() << " " << nonAlphaNum;
}