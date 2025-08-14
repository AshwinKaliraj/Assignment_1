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
