#include <iostream>
#include <chrono>
#include "sudokuGrid.hh"

int main(int argc, char** argv){

    if (argc == 1){
        std::cout << "You need to provide a filname as parameter to the SudokuSolver!\n (sodukosolver <fullpath to initial sudoku grid file)\n";
    } else {
        auto start = std::chrono::high_resolution_clock::now();
        
        SudokuGrid MyGrid(argv[1]);
        
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "Time of execution (According to main()pgm...): " << duration.count() << " microseconds" << std::endl;
    }    
return 0;
}