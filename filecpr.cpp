#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
using namespace std;

// Check if File exists
bool fileExists(const string &filename) {
    struct stat buffer;
    return (stat(filename.c_str(), &buffer) == 0);
}

// Check if file has data
bool fileHasData(const string &filename) {
    ifstream file(filename);
    return file.peek() != ifstream::traits_type::eof();
}
// Get file size in bytes
long getFileSize(const string &filename) {
    ifstream file(filename, ios::binary | ios::ate);
    return file.tellg();
}
int main() {
    string fileA = "Original_Record.csv";
    string fileB = "Temporary_Record.csv";

// STEP 1: Check if Original_Record exists

    if (!fileExists(fileA)) {
        ofstream outA(fileA);
        int n;
        cout << "File 'Original_Record' not found.Please Wait Creating it...\n";
        cout << "Enter number of records: ";
        cin >> n;
        cin.ignore();

        // Write header
        outA << "Name,Age,Class,Div,Teacher\n";

        // Write data
        for (int i = 0; i < n; i++) {
            string name, cls, div, teacher;
            int age;
            cout << "\nRecord " << i + 1 << ":\n";
            cout << "Name: ";
            getline(cin, name);
            cout << "Age: ";
            cin >> age;
            cin.ignore();
            cout << "Class: ";
            getline(cin, cls);
            cout << "Division: ";
            getline(cin, div);
            cout << "Teacher: ";
            getline(cin, teacher);

            outA << "\"" << name << "\"," << age << ",\"" << cls << "\",\"" << div << "\",\"" << teacher << "\"\n";
        }
        outA.close();
        cout << "Original_Record created successfully.\n";
    }
    // STEP 2: Check readability of Original_Record

    ifstream testRead(fileA);
    if (!testRead.is_open()) {
        cout << "Error: Cannot read Original_Record. Check permissions!.\n";
        return 1;
    }
    testRead.close();

   // STEP 3: Check if Temporary_Record exists

    if (!fileExists(fileB)) {
        ofstream outB(fileB); 
        outB.close();
    }
    // STEP 4: Check writability of Temporary_Record

    ofstream testWrite(fileB, ios::app);
    if (!testWrite.is_open()) {
        cout << "Error: Cannot write to Temporary_Record. Check permissions or disk space.\n";
        return 1;
    }
    testWrite.close();

    // STEP 5: Check if Original_Record has data

    if (!fileHasData(fileA)) {
        cout << "Error: 'Original_Record' is empty. Cannot copy.\n";
        return 1;
    }
    // STEP 6: Clear Temporary_Record if it has old data
    if (fileHasData(fileB)) {
        ofstream clearB(fileB, ios::trunc);
        clearB.close();
        cout << "Temporary_Record cleared.\n";
    }
