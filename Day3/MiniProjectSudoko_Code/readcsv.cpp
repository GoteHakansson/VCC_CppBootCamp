#include <iostream>
#include <fstream>
#define N 9

using namespace std;

int main(){

    int grid[N][N];
    ifstream myFile;
    int row,column = 0;
    int charcount = 0;
    string line = "";
    int checkLinePos = 0;

    myFile.open("/home/gote/Desktop/altenprojects/Day3/MiniProjectSudoko_Code/MyCsvFile.csv");

    while (myFile.good()){
        for (size_t row = 0; row < N; row++){
            column = 0;
            checkLinePos = 0;
            getline(myFile, line,'\n');
            while (line[checkLinePos] != '\0'){
                if (line [checkLinePos] != ','){
                    grid [row][column] = line[checkLinePos] - '0';
                    column++;
                    charcount++;
                }
                checkLinePos++;
            }
        }
    }

    myFile.close();
    
}