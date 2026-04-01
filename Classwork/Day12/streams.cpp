#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;
int main() {
    string fileName;
    ofstream out;
    string input = "CPET121";
    cin >> fileName;



    out.open(fileName);
    out

    out << input;
    out.close();
}