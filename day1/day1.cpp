#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> lines;
    ifstream contents("input.txt");
    for (string line; getline(contents, line);){
        lines.push_back(line);
    }

    int running_total = 0;
    vector<int> max_val{0,0,0};

    for (int i = 0; i < lines.size(); i++){
        if (lines[i] == "" ){
            if (running_total > max_val[0]){
                max_val[0] = running_total;
                sort(max_val.begin(), max_val.end());
            }
            running_total = 0;
        }
        else{
            running_total += stoi(lines[i]);
        }
    }
    cout << max_val[0] + max_val[1] + max_val[2] << endl;
    return 0;
}
