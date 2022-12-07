#include <iostream> 
#include <vector> 
#include "../read_lines_from_file.h"
#include <regex>
#include <map>

using namespace std; 

map <string, int> folderSize;
map <string, vector<string>> folderContents;

int sizeOfFolder(string folderName){
    int totalSize = 0;
    vector <string> folderContent = folderContents[folderName];
    for (int i = 0; i < folderContent.size(); i++){
        if (folderContent[i].substr(0,3) == "dir"){
            regex pattern ("dir ([a-z0-9]+)");
            smatch m;
            regex_search(folderContent[i],m,pattern);
            if (folderSize.count(m[1])){
                totalSize += folderSize[m[1]];
            }
            // else{
            //     totalSize += sizeOfFolder(m[1]);
            // }
        }
        else{
            regex pattern ("([0-9]+)");
            smatch m;
            regex_search(folderContent[i],m,pattern);
            totalSize += stoi(m[1]);
        }
    }
    return totalSize;
}

map <string ,vector <string>> getFolderContents(vector <string> lines){
    map <string, vector <string>> folderContents;
    for (int i = 0; i < lines.size(); i++){
        regex pattern("cd ([a-z/]+)");
        smatch m; 
        regex_search(lines[i], m, pattern);
        if (m[1] != ""){
            int k = i+2;
            while (k < lines.size() && lines[k][0] != '$'){
                folderContents[m[1]].push_back(lines[k]);
                k++;
            }
        }
    }
    return folderContents;
}

int main(){
    vector <string> lines = readFiles("input.txt");
    folderContents = getFolderContents(lines);

    for (auto s: folderContents){
        folderSize[s.first] = sizeOfFolder(s.first);
        int x;
    }
    int totalSize = 0;
    for (auto s: folderSize){
        if (folderSize[s.first] <= 100000){
            totalSize += folderSize[s.first];
        }
    }
    cout << totalSize << endl;
    return 0;
}