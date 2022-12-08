#include <iostream> 
#include <vector> 
#include "../read_lines_from_file.h"

using namespace std; 

int main(){
    vector <string> lines = readFiles("input.txt");
    vector <string> oldLines = readFiles("input.txt");
    int viewableTrees = 0;

    for(int i = 0; i < lines.size(); i++){
        int maxHeight = 0;
        for (int k = 0; k < lines[i].size(); k++){
            if (lines[i][k] > maxHeight){
                if (oldLines[i][k] != -1){
                    oldLines[i][k] = -1;
                    viewableTrees += 1;
                }
                maxHeight = lines[i][k];
            }
        }
        maxHeight = 0;
        for (int k = lines[i].size()-1; k >= 0; k--){
            if (lines[i][k] > maxHeight){
                if (oldLines[i][k] != -1){
                    oldLines[i][k] = -1;
                    viewableTrees += 1;
                }
                maxHeight = lines[i][k];
            }
        }
    }
    for(int i = 0; i < lines[0].size(); i++){
        int maxHeight = 0;
        for (int k = 0; k < lines.size(); k++){
            if (lines[k][i] > maxHeight){
                if (oldLines[k][i] != -1){
                    oldLines[k][i] = -1;
                    viewableTrees += 1;
                }
                maxHeight = lines[k][i];
            }
        }
        maxHeight = 0;
        for (int k = lines.size()-1; k >= 0; k--){
            if (lines[k][i] > maxHeight){
                if (oldLines[k][i] != -1){
                    oldLines[k][i] = -1;
                    viewableTrees += 1;
                }
                maxHeight = lines[k][i];
            }
        }
    }

    cout << viewableTrees;


}