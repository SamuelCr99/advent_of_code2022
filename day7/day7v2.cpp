#include <iostream> 
#include <vector> 
#include "../read_lines_from_file.h"
#include <regex>
#include <map>

using namespace std; 



vector <string> lines = readFiles("input2.txt");
int totalSize = 0;

vector <string> getFolderContent(string folderName){
    vector <string> content; 
    bool found_value = false;
    for (int i = 0; i < lines.size(); i++){
        regex pattern("cd " + folderName);
        smatch m; 
        regex_search(lines[i],m, pattern);
        string s = m[0];
        if (m[0] != "" && lines[i+2] != ""){
            found_value = true;
            for (int k = i+2; k < lines.size(); k++){
                if (lines[k][0] == '$'){
                    break;
                }
                content.push_back(lines[k]);
            }
        }
        if (found_value){
            break;
        }
    }
    return content;
}

int sizeOfFolder(string folderName){
    int folderSize = 0;
    vector <string> folderContent = getFolderContent(folderName);
    for (int i = 0; i < folderContent.size(); i++){
        folderContent = getFolderContent(folderName);
            regex pattern("dir");
            smatch m; 
            regex_search(folderContent[i],m, pattern);
            if (m[0] != ""){
                regex pattern ("dir ([a-z0-9]+)");
                smatch z;
                regex_search(folderContent[i],z,pattern);
                string s = z[1];
                folderSize += sizeOfFolder(z[1]);
            }
            else{
                regex pattern ("([0-9]+)");
                smatch z;
                regex_search(folderContent[i],z,pattern);
                folderSize += stoi(z[1]);
            }
            auto ln = find(lines.begin(),lines.end(), folderContent[i]);
            lines[ln - lines.begin()] = "";
        }
    if (folderSize <= 100000){
        totalSize += folderSize;
    } 
    return folderSize;
}


int main(){
    sizeOfFolder("/"); 
    cout << totalSize << endl;
    return 0;
}