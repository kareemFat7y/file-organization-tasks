#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    
    ofstream outFile("students.txt", ios::app);

    if (!outFile) {
        cout << "Error opening file for writing" << endl;
        return 1;
    }

    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        string name;
        int id;
        float grade;

        
        cout << "\nEnter Student Name: ";
        cin >> ws;
        getline(cin, name);

        cout << "Enter Student ID: ";
        cin >> id;

        cout << "Enter Student Grade: ";
        cin >> grade;

        
        outFile << name << ", " << id << ", " << grade << " $" << endl;

        
        cout << "Do you want to add another student? (y/n): ";
        cin >> choice;
    }

    outFile.close();
    cout << "\nAll student records have been saved to 'students.txt' successfully" << endl;

    return 0;
}