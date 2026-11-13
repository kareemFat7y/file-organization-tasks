#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
   
    ifstream input("names.txt");

   
    if (!input.is_open()) {
        cout << "Unable to open the file 'names.txt'!" << endl;
        return 1;
    }

    string name;
    vector<string> data;

   
    while (getline(input, name)) {
        if (!name.empty()) { 
            data.push_back(name);
        }
    }

   
    input.close();

   
    sort(data.begin(), data.end());

   
    cout << "Names sorted successfully in ascending order:\n";
    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << endl;
    }

    return 0;
}