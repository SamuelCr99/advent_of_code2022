#include <iostream>
#include <fstream>
#include <vector>
#include <map> 

using namespace std;



int main(){
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

        if (my_choice == 'X'){
            int points_to_add = val[their_choice];
            if (points_to_add == 0){
                points_to_add = 3;
            }
            points += points_to_add; 
        }  
        else if(my_choice == 'Y'){
            points += 3; 
            points += val[their_choice] + 1;
        }
        else if(my_choice == 'Z'){
            points += 6; 
            points += (val[their_choice] + 1)%3 + 1;
        }

    }
    cout << points;

    return 0;
}
