#include <iostream>
#include <fstream>
#include <vector>
#include <stack> 
#include <regex>

using namespace std;

int get_stack_start(vector<string> lines){
    int stackStart = 0;
    for (int i = 0; i < lines.size(); i++){
        if (lines[i][1] == '1'){
            stackStart = i;
            break;
        }
    }
    return stackStart;
}

vector <stack <string>> fixStacks (vector <string> lines, int stackStart){
    vector <stack <string>> stacks;

    for (int i = 0; i < 9; i++){
        stack <string> s;
        stacks.push_back(s);
    }

    for (int i = stackStart - 1; i >= 0; i--){
        for (int k = 0; k < 9; k++){
            if (lines[i].substr(k*4, 3) != "   "){
                stacks[k].push(lines[i].substr(k*4,3));
            }
        }
    }

    return stacks;
}

int* move_values (string line){
    static int a[3];

    regex move("move ([0-9]+)"); 
    smatch m;
    regex_search(line, m, move);
    a[0] = stoi(m[1]);

    regex from("from ([0-9]+)"); 
    regex_search(line, m, from);
    a[1] = stoi(m[1]);
    
    regex to("to ([0-9]+)"); 
    regex_search(line, m, to);
    a[2] = stoi(m[1]);

    return a;
}

int main() {
    vector<string> lines;
    ifstream contents("input.txt");
    for (string line; getline(contents, line);){
        lines.push_back(line);
    }

    int stackStart = get_stack_start(lines);

    vector <stack <string>> stacks = fixStacks(lines, stackStart);

    for (int i = stackStart+2; i < lines.size(); i++){
        int* moveInfo = move_values(lines[i]);
        int itemsToMove = moveInfo[0];
        int from = moveInfo[1];
        int to = moveInfo[2];
        for (int k = 0; k < itemsToMove; k++){
            string itemToMove = stacks[from-1].top();
            stacks[from-1].pop();
            stacks[to-1].push(itemToMove);
        }
    }
    for (stack s : stacks){
        if (s.size() > 0) {
            cout << s.top()[1];
            }
        else{
            cout << -1;
        }
    }


    return 0;
}