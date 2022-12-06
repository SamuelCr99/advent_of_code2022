#include <iostream>
#include <fstream>
#include <vector>
#include "../read_lines_from_file.h"
#include <map>

using namespace std;

int main() {
    vector<string> lines = readFiles("input.txt");
    string line = lines[0];

    for (int i = 0; i < line.size()-13; i++){
        string linesub = line.substr(i,14);
        map<char, int> charCount;
        bool duplicateFound = false;
        for (char c : linesub){
            if (charCount.find(c) == charCount.end()){
                charCount[c] = 1;
            }
            else{
                duplicateFound = true;
                break;
            }
        }
        if (!duplicateFound){
            cout << i+14;
            break;
        }
    }

    return 0;
}