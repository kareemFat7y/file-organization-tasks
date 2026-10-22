#include <iostream>
#include <fstream>   
#include <string>

using namespace std;

int main() {
    string fullName;
    int id;
    float grade;

    cout << "Enter Full Name: ";
    getline(cin, fullName); 

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter Grade: ";
    cin >> grade;

    
    ofstream outFile("Student.txt");

    if (!outFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    outFile << "Full Name: " << fullName << endl;
    outFile << "ID: " << id << endl;
    outFile << "Grade: " << grade << endl;

    outFile.close();

    cout << "Student data has been written to 'Student.txt' successfully!" << endl;

    return 0;
}