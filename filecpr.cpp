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