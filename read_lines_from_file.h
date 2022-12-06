#include <fstream>
#include <vector>

using namespace std;

vector <string> readFiles(string fileLocation){
    vector <string> lines;
    ifstream contents(fileLocation);
    for(string line; getline(contents, line);){
        lines.push_back(line);
    }
    return lines;
}

