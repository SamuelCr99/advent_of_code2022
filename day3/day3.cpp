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

    for (int i = 0; i < lines.size(); i++){
        int string_length = lines[i].size();
        string subst1 = lines[i].substr(0,string_length/2);
        string subst2 = lines[i].substr(string_length/2, string_length);
        vector<char> used_letters;

        for (int j = 0; j < subst1.size(); j++){
            for (int k = 0; k < subst2.size(); k++){
                if (subst1[j] == subst2[k]){
                    if (count(used_letters.begin(), used_letters.end(), subst1[j]) == 0){
                        sum += get_val(subst1[j]);
                        used_letters.push_back(subst1[j]);
                    }
                }
            }
        }
    }

    cout << sum << endl;
    return 0;
}