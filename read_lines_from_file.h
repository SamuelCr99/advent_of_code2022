#include <fstream>
#include <vector>

using namespace std;

int main(){
    vector <string> lines;
    ifstream contents("input.txt");
    for(string line; getline(contents, line);){
        lines.push_back(line);
    }
}

