#include <iostream> 
#include <vector> 
#include "../read_lines_from_file.h"

using namespace std; 

int main(){
    vector <string> lines = readFiles("input.txt");
    int bestScenicScore = 0;

    for (int i = 1; i < lines.size() - 1; i++){
        for (int k = 1; k < lines[i].size() - 1; k++){
            int leftMovement = 0;
            int rightMovement = 0;
            int upMovement = 0;
            int downMovement = 0;
            int treeHeight = lines[i][k];

            int maxFoundDown = 0;
            for (int z = 1; z+i < lines.size(); z++){
                downMovement += 1;
                if (lines[z+i][k] >= treeHeight){
                    break;
                }
            } 

            int maxFoundUp = 0;
            for (int z = 1; i-z >= 0; z++){
                upMovement += 1;
                if (lines[i - z][k] >= treeHeight){
                    break;
                }
            } 
            
            int maxFoundRight = 0;
            for (int z = 1; z+k < lines[i].size(); z++){
                rightMovement += 1;
                if (lines[i][k+z] >= treeHeight){
                    break;
                }
            } 

            int maxFoundLeft = 0;
            for (int z = 1; k-z >= 0; z++){
                leftMovement += 1;
                if (lines[i][k-z] >= treeHeight){
                    break;
                }
            } 

            int scenicScore = downMovement * upMovement * rightMovement * leftMovement;
            if (scenicScore > bestScenicScore){
                bestScenicScore = scenicScore;
            } 
        }
    }

    cout << bestScenicScore;


}