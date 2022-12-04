#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector <string> get_pair(string s){
    int comma_index = s.find(',');
    vector <string> r_vec;
    r_vec.push_back(s.substr(0,comma_index));
    r_vec.push_back(s.substr(comma_index+1, s.size()));
    return r_vec;
}

vector <int> get_range(string s){
    int dash_index = s.find('-');
    vector <int> r_vec;
    r_vec.push_back(stoi(s.substr(0,dash_index)));
    r_vec.push_back(stoi(s.substr(dash_index+1, s.size())));
    return r_vec;
}

int main() {
    vector<string> lines;
    ifstream contents("input.txt");
    for (string line; getline(contents, line);){
        lines.push_back(line);
    }

    int pairs = 0;
    for (int i = 0; i < lines.size(); i++){
        vector <string> line_contents = get_pair(lines[i]);
        string elf1 = line_contents[0];
        string elf2 = line_contents[1];

        int elf1_low = get_range(elf1)[0];
        int elf1_high = get_range(elf1)[1];
        int elf2_low = get_range(elf2)[0];
        int elf2_high = get_range(elf2)[1];

        if ((elf1_low <= elf2_low && elf1_high >= elf2_low) || (elf2_low <= elf1_low && elf2_high >= elf1_low)){
            pairs++;
        }
    }

    cout << pairs << endl;

    return 0;
}