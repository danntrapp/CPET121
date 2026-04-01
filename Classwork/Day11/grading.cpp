#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct student {
   std::pair<std::string, std::string> names;
   int exams[3];
   char letterGrade;
   void Grade() {
    float avg = 0;
    for(int i : exams) {
        avg += i;
    }
    avg /= 3;
    switch(static_cast<int>(avg) / 10) {
        case(10):
        case(9): letterGrade = 'A'; break;
        case(8): letterGrade = 'B'; break;
        case(7): letterGrade = 'C'; break;
        case(6): letterGrade = 'D'; break;
        default: letterGrade = 'F'; break;
    }
   }
};

std::istream& operator>>(std::istream& is, student &s) {
   is >> s.names.second >> s.names.first >> s.exams[0] >> s.exams[1] >> s.exams[2];
   return is;
}
std::ostream& operator<<(std::ostream& os, student &s) {
   os << s.names.second << "\t" << s.names.first << "\t";
   for(int i = 0; i < 3; i++) {
    os << s.exams[i] << "\t";
   }
   os << s.letterGrade << "\n\n";
   return os;
}

int main() {
    std::ifstream inFile;
    std::ofstream outFile;
    std::string inName;
    std::string outName = "report.txt";
    student s;
    std::vector<student> data;
    float examAvg[3] = {0, 0, 0};

    std::cin >> inName;
    inFile.open(inName);
    if(!inFile.is_open()) return 0;
    while(inFile >> s) {
        data.push_back(s);
    }
    inFile.close();
    outFile.open(outName);
    if(!outFile.is_open()) return 0;
    for(student s : data) {
        s.Grade();
        for(int i = 0; i < 3; i++) {
            examAvg[i] += s.exams[i];
        }
        outFile << s;
    }
    for(float f : examAvg) {
        f /= 3;
    }
    outFile << "Averages: midterm1 " << examAvg[0] << ", midterm2 " << examAvg[1] << ", final" << examAvg[2];
   /* TODO: Declare any necessary variables here. */
      
      
   /* TODO: Read a file name from the user and read the tsv file here. */
   
   
   /* TODO: Compute student grades and exam averages, then output results to a text file here. */

   return 0;
}
