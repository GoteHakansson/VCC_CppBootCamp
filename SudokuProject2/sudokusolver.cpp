#include <iostream>
#include "sudokuGrid.hh"

int main(int argc, char** argv){

    if (argc == 1){
        std::cout << "You need to provide a filname as parameter to the SudokuSolver!\n (sodukosolver <fullpath to initial sudoku grid file)\n";
    } else {
        SudokuGrid MyGrid(argv[1]);
    }
    
return 0;

}