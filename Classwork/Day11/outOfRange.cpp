#include <iostream>
#include <vector>
#include <stdexcept>      // For std::out_of_range
using namespace std;

int main() {
   std::vector<std::string> names = { "Ryley", "Edan", "Reagan", "Henry", "Caius", "Jane", "Guto", "Sonya", "Tyrese", "Johnny" };
   int index;

   
   
   try {
        std::cin >> index;
        cout << names.at(index);
   } catch(std::out_of_range& oof) {
        if(index < 0) index = 0;
        if(index >= names.size()) index = names.size() - 1;
        std::cout << "Exception! " << oof.what() << std::endl;
        printf("The closest name is: %s\n", names.at(index).c_str());
   }

   return 0;
}
