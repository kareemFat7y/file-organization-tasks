#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string filename = "welcome.txt";

    
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error opening file for writing" << endl;
        return 1;
    }
    outFile << "Hello Everybody";
    outFile.close();

    
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error opening file for reading" << endl;
        return 1;
    }

    string content;
    getline(inFile, content); 
    inFile.close();

    
    size_t pos = content.find("body");
    if (pos != string::npos) {
        content.replace(pos, 4, "one"); 
    }

    
    ofstream outFileFinal(filename);
    if (!outFileFinal) {
        cout << "Error opening file for updating!" << endl;
        return 1;
    }
    outFileFinal << content;
    outFileFinal.close();

    cout << "Task 3 completed successfully!" << endl;
    cout << "Final result in 'welcome.txt': " << content << endl;

    return 0;
}