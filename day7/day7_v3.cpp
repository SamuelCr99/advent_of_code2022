#include <iostream> 
#include <vector> 
#include "../read_lines_from_file.h"
#include <regex>
#include <map>

using namespace std; 



vector <string> lines = readFiles("input2.txt");
int totalSize = 0;
int maxDepth = 0;


vector <string> getFolderName(string folderName){
    vector <string> fcn;
    for (int i = maxDepth; i < lines.size(); i++){
        regex pattern("cd " + folderName);
        smatch m; 
        regex_search(lines[i],m, pattern);
        if (m[0] != ""){
            i += 2;
            while (lines[i][0] != '$'){
                fcn.push_back(lines[i]);
                i += 1;
            }
            return fcn;
        }
    }
}

vector <string> getFolderContent(string folderName){
    vector <string> content; 
    bool found_value = false;
    for (int i = maxDepth; i < lines.size(); i++){
        regex pattern("cd " + folderName);
        smatch m; 
        regex_search(lines[i],m, pattern);
        if (m[0] != ""){
            found_value = true;
            for (int k = i+2; k < lines.size(); k++){
                if (lines[k][0] == '$'){
                    break;
                }
                content.push_back(lines[k]);
                maxDepth += 1;
            }
        }
        if (found_value){
            maxDepth += 2;
            break;
        }
    }
    return content;
}

int sizeOfFolder(string folderName){
    int folderSize = 0;
    vector <string> contentNames = getFolderName(folderName);
    for (int i = 0; i < folderName.size(); i++){
        regex pattern("dir");
        smatch m; 
        regex_search(contentNames[i],m, pattern);
        if (m[0] != ""){
            regex pattern ("dir ([a-z0-9]+)");
            smatch z;
            regex_search(contentNames[i],z,pattern);
            string s = z[1];
            folderSize += sizeOfFolder(z[1]);
        }
        else{
            regex pattern ("([0-9]+)");
            smatch z;
            regex_search(contentNames[i],z,pattern);
            folderSize += stoi(z[1]);
        }
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