#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void) {
    auto finder = [](char oldC, char newC, string &s) -> void {
        while(s.find(oldC) != s.npos) {
            int i = s.find(oldC);
            s.replace(i, 1, &newC);
        }
    };
    string pass;
    cin >> pass;
    
    finder('E', '3', pass);
    finder('a', '@', pass);
    finder('S', '$', pass);
    pass.push_back('!');

    cout << pass;
}