#include <iostream> 
#include <vector> 
#include "../read_lines_from_file.h"
#include <regex>
#include <map>

using namespace std; 

map <string, vector<string>> folderContents;

int sizeOfFolder(string folderName){
    int totalSize = 0;
    vector <string> folderContent = folderContents[folderName];
    for (int i = 0; i < folderContent.size(); i++){
        regex pattern("dir");
        smatch m; 
        regex_search(folderContent[i],m, pattern);
        if (m[0] != ""){
            regex pattern ("dir ([a-z0-9]+)");
            smatch z;
            regex_search(folderContent[i],z,pattern);
            totalSize += sizeOfFolder(z[1]);
        }
        else{
            regex pattern ("([0-9]+)");
            smatch z;
            regex_search(folderContent[i],z,pattern);
            totalSize += stoi(z[1]);
        }
    }
    cout << totalSize << endl;
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
    vector <string> lines = readFiles("input2.txt");
    folderContents = getFolderContents(lines);

    sizeOfFolder("/"); 
    int totalSize = 0;
    // for (auto s: folderSize){
    //     if (folderSize[s.first] <= 100000){
    //         totalSize += folderSize[s.first];
    //     }
    // }
    cout << totalSize << endl;
    return 0;
}