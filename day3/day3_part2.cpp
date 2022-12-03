#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int get_val(char c){
    int ascii_val = (int) c;
    if (ascii_val > 90){
        return ascii_val - 96;
    }
    return ascii_val - 38;
}

int main()
{
    vector<string> lines;
    ifstream contents("input.txt");
    for (string line; getline(contents, line);){
        lines.push_back(line);
    }

    int sum = 0;

    for (int i = 0; i < lines.size(); i += 3){
        string bag1 = lines[i];
        string bag2 = lines[i+1];
        string bag3 = lines[i+2];
        bool loop_done = false;

        for (int j = 0; j < bag1.size(); j++){
            for (int k = 0; k < bag2.size(); k++){
                if (bag1[j] == bag2[k]){
                    for (int l = 0; l < bag3.size(); l++){
                        if (bag1[j] == bag3[l]){
                            sum += get_val(bag1[j]);
                            goto BADGE_FOUND; 
                        }
                    }
                }
            }
        }
        BADGE_FOUND:;
    }
    cout << sum << endl;
    return 0;
}