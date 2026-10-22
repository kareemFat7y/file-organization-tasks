#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string line;

    
    ifstream inFile("fruit.txt");
    if (inFile.is_open()) {
        cout << "--- Reading contents of fruit.txt ---" << endl;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }
    else {
        cout << "Note: 'fruit.txt' does not exist yet, it will be created." << endl;
    }

    
    ofstream outFile("fruit.txt", ios::app);
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return 1;
    }

    
    outFile << "Fresh Fruits" << endl;
    outFile.close();

    cout << "\nMessage 'Fresh Fruits' added to 'fruit.txt' successfully!" << endl;

    return 0;
}