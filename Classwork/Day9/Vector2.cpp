#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void PrintVector(vector<int> vec) {
    unsigned int i;
    for(i = 0; i < vec.size(); i++) {
        cout << setw(6) << "[" << i << "]";
    }
    cout << endl;

    for(i = 0; i < vec.size(); i++) {
        cout << setw(8) << vec.at(i);
    }
    cout << endl;
}

int main(void) {
    vector<int> user_data;
    int input;
    user_data.resize(6);
    // printf("Input 6 ints: ");
    // for(int i = 0; i < user_data.size(); i++) {
    //     printf("Input %i: ", i);
    //     cin >> input;
    //     user_data.at(i) = input;
    // }
    for(int i = 0; i < user_data.size(); i++) {
        user_data.at(i) = i + 1;
    }

    PrintVector(user_data);
    user_data.push_back(999);
    cout << "Result: \r\n\n";
    PrintVector(user_data);
    user_data.insert(user_data.begin() + 2, 555);
    cout << "Result: \r\n\n";
    PrintVector(user_data);
    user_data.erase(user_data.begin() + 4);
    cout << "Result: \r\n\n";
    PrintVector(user_data);
    user_data.pop_back();
    cout << "Result: \r\n\n";
    PrintVector(user_data);



    return 0;
}