#include <iostream>
#include <fstream>
#include <vector>
#include "../read_lines_from_file.h"
#include <algorithm>

using namespace std;

int main() {
    vector<string> lines = readFiles("input.txt");

    string line = lines[0];

    for (int i = 0; i < line.size()-13; i++){
        string linesub = line.substr(i,14);
        sort(linesub.begin(),linesub.end());
        bool duplicateFound = false;
        for (int k = 0; k < linesub.size() - 1; k++){
            if (linesub[k] == linesub[k+1]){
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