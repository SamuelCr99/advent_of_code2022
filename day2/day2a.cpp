#include <iostream>
#include <fstream>
#include <vector>
#include <map> 

using namespace std;

int main()
{
    vector<string> lines;
    ifstream contents("input.txt");
    for (string line; getline(contents, line);){
        lines.push_back(line);
    }

    map<char, int> val;

    val['A'] = 0; //Rock
    val['B'] = 1; // Paper
    val['C'] = 2; // Scissors
    val['X'] = 0; //Rock
    val['Y'] = 1; // Paper
    val['Z'] = 2; // Scissors

    int points = 0;
    for(int i = 0; i < lines.size(); i++){
        char my_choice = lines[i][2];
        char their_choice = lines[i][0];

        if (val[my_choice] == val[their_choice]){
            points += 3;
        }
        else if (val[my_choice] == (val[their_choice]+1)%3){
            points += 6;
        }
        points += val[my_choice] + 1;
    }
    cout << points;

    return 0;
}
