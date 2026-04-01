#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct food {
   std::string category;
   std::string name;
   std::string description;
   bool availible;
};
std::istream& operator>>(std::istream& is, food& f) {
    std::string input;
    if (!std::getline(is, f.category, '\t')) return is;
    if (!std::getline(is, f.name, '\t')) return is;
    if (!std::getline(is, f.description, '\t')) return is;
    if (!std::getline(is, input)) return is;
    if (!input.empty() && input.back() == '\r') input.pop_back();
    f.availible = (input == "Available");
    return is;
}
int main(void) {
    std::vector<food> input;
    std::string inFileName;
    std::ifstream fin;

    std::cin >> inFileName;
    fin.open(inFileName);
    if(!fin.is_open()) return 0;
    food f;
    while(fin >> f) {
        input.push_back(f);
    }
    fin.close();
    for(food f : input) {
        
            printf("%s ", f.name.c_str());
            printf("(%s) -- ", f.category.c_str());
            printf("%s", f.description.c_str());
        
    }


   return 0;
}