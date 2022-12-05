#include <iostream>
#include <fstream>
#include <vector>
#include <stack> 

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

    for (int i = 0; i < line.size() - 1; i++){
        if (line[i] == 'm' && line[i+1] == 'o'){
            a[0] = line[i+5] - 48;
            if (line[i+6] != ' '){
                a[0] *= 10;
                a[0]+=line[i+6]-48;
            }
        }
        else if (line[i] == 'f' && line[i+1] == 'r'){
            a[1] = line[i+5] - 48;
        }
        else if (line[i] == 't' && line[i+1] == 'o'){
            a[2] = line[i+3] - 48;
        }
    }
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
        int itemsToMove = move_values(lines[i])[0];
        int from = move_values(lines[i])[1];
        int to = move_values(lines[i])[2];

        stack <string> newStack;

        for (int k = 0; k < itemsToMove; k++){
            string itemToMove = stacks[from-1].top();
            stacks[from-1].pop();
            newStack.push(itemToMove);
        }

        for (int k = 0; k < itemsToMove; k++){
            string itemToMove = newStack.top();
            newStack.pop();
            stacks[to-1].push(itemToMove);
        }

    }

    for (stack s : stacks){
        if (s.size() > 0) {
            cout << s.top()[1];
            }
        else{
            cout << 0;
        }
    }


    return 0;
}