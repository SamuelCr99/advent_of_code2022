#include <iostream> 
#include <vector> 
#include <regex>
#include "../read_lines_from_file.h"

using namespace std; 

char getDir(string s){

    return s[0];
}

int getSteps(string s){
    smatch m; 
    regex pattern(" ([0-9]+)");
    regex_search(s,m, pattern);
    return stoi(m[1]);
}

int getMove(pair <int,int> headPos, pair<int,int> tailPos){
    if (abs(headPos.first - tailPos.first) > 1){
        return 1;
    }
    if (abs(headPos.second - tailPos.second) > 1){
        return 1;
    }
    return 0;
}

int main(){
    vector <string> lines = readFiles("input.txt");
    pair <int, int> headPos(0,0);
    pair <int, int> tailPos(0,0);
    vector <pair <int, int>> exploredPositions;
    vector <pair <int, int>> bodyPos;
    int exploredCount = 0;

    for (string s: lines){
        char dir = getDir(s);
        int steps = getSteps(s);
        int prevPos;
        for (int i = 0; i < steps; i++){
            if (dir == 'U'){
                prevPos = headPos.second;
                headPos.second += 1;
            }
            else if(dir == 'D'){
                prevPos = headPos.second;
                headPos.second -= 1;
            }
            else if(dir == 'L'){
                prevPos = headPos.first;
                headPos.first -= 1;
            }
            else if(dir == 'R'){
                prevPos = headPos.first;
                headPos.first += 1;
            }

            if (getMove(headPos, tailPos)){
                if (dir == 'U' || dir == 'D'){
                    tailPos.second = prevPos;
                    tailPos.first = headPos.first;
                }
                else if(dir == 'R' || dir == 'L'){
                    tailPos.first = prevPos;
                    tailPos.second = headPos.second;
                }
                if (!(count(exploredPositions.begin(), exploredPositions.end(), tailPos))){
                    exploredCount++;
                }
                exploredPositions.push_back(tailPos);
            }

        }

    }
    cout << exploredCount + 1 << endl;
}