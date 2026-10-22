#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


struct Person {
    string name;
    int age;
};

int main() {
    int n;
    string filename = "persons.txt";

    
    cout << "Enter how many persons you want to add: ";
    cin >> n;

    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error opening file for writing" << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        string name;
        int age;
        cout << "\nEnter details for person " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> ws; 
        getline(cin, name);
        cout << "Age: ";
        cin >> age;

        
        outFile << name << " " << age << endl;
    }
    outFile.close();
    cout << "\nData saved to '" << filename << "' successfully!\n" << endl;

    
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error opening file for reading" << endl;
        return 1;
    }

    vector<Person> persons;
    Person p;
  
    while (inFile >> p.name >> p.age) {
        persons.push_back(p);
    }
    inFile.close();

    
    if (persons.empty()) {
        cout << "No data found in the file" << endl;
        return 1;
    }

    
    Person youngest = persons[0];
    Person oldest = persons[0];

    for (size_t i = 1; i < persons.size(); i++) {
        if (persons[i].age < youngest.age) {
            youngest = persons[i];
        }
        if (persons[i].age > oldest.age) {
            oldest = persons[i];
        }
    }

    
    ofstream resultsFile("results.txt");
    if (!resultsFile) {
        cout << "Error opening results file!" << endl;
        return 1;
    }

    resultsFile << "Youngest Person: " << youngest.name << " (Age: " << youngest.age << ")" << endl;
    resultsFile << "Oldest Person: " << oldest.name << " (Age: " << oldest.age << ")" << endl;
    resultsFile.close();

    cout << "Task 4 completed successfully" << endl;
    cout << "Results have been saved to 'results.txt'." << endl;

    return 0;
}