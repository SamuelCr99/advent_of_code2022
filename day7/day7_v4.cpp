#include <iostream> 
#include <vector> 
#include "../read_lines_from_file.h"
#include <regex>
#include <map>

using namespace std; 
vector <string> lines = readFiles("input.txt");
int totalSize = 0;
int maxDepth = 0;
vector <int> directorySizes;

vector <string> getFolderContent(string folderName){
    vector <string> content; 
    for (int i = maxDepth; i < lines.size(); i++){
        smatch m; 
        regex pattern("cd " + folderName);
        regex_search(lines[i],m, pattern);
        string s = m[0];
        if (s != ""){
            for (int k = i+2; k < lines.size(); k++){
                maxDepth = k;
                if (lines[k][0] == '$'){ //REMEMBER TO CHECK THIS
                    return content;
                }
                content.push_back(lines[k]);
            }
        }
    }
}

int sizeOfFolder(string folderName){
    int folderSize = 0;
    vector <string> folderContent = getFolderContent(folderName);
    for (int i = 0; i < folderContent.size(); i++){
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
    }

    if (folderSize <= 100000){
        totalSize += folderSize;
    }
    directorySizes.push_back(folderSize);
    return folderSize;
}

int main(){
    int rootSize = sizeOfFolder("/");
    int spaceForUpdate = 30000000;
    int totalSpace = 70000000;
    int freeSpace =  totalSpace - rootSize; 
    int spaceToDelete = spaceForUpdate - freeSpace;
    int smallest = rootSize;
    for (int directory : directorySizes){
        if (directory >= spaceToDelete && directory < smallest){
            smallest = directory;
        }
    }

    cout << smallest << endl;

    return 0;
}