#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    
    ifstream x("file.txt");
    ofstream temp("t.txt");

    
    if (!x.is_open()) {
        cout << "Unable to open the file 'file.txt'" << endl;
        return 1;
    }

    int line;
    int c_line = 1;

    cout << "Enter line number you want to delete: ";
    cin >> line;

    string text;
   
    while (getline(x, text)) {
        
        if (c_line != line) {
            temp << text << endl;
        }
        c_line++;
    }

    
    x.close();
    temp.close();

    
    remove("file.txt");
    rename("t.txt", "file.txt");

    cout << "Line " << line << " deleted successfully" << endl;

    return 0;
}