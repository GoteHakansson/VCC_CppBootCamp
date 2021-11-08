#include <iostream>
#include <fstream>
#include <chrono>
#include "sudokuGrid.hh"

int main(int argc, char **argv)
{
    std::string newSudoku;
    std::ifstream myFile;
    SudokuGrid MyGrid;

    if (argc == 1)
    {
        std::cout << "You need to provide a filname as parameter to the SudokuSolver!\n (sodukosolver <fullpath to initial sudoku grid file)\n";
    }
    else
    {
        myFile.open(argv[1]);

        if (!myFile.good())
        {
            std::cout << "Something wrong with filename or file! Pls check!\n";
        }
        
        while ((myFile.good()) && !(myFile.eof()))
        {
            while (getline(myFile, newSudoku) && newSudoku.length() == 81)
            {
                auto start = std::chrono::high_resolution_clock::now();

                MyGrid.SolveSudoku(newSudoku);

                auto stop = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
                std::cout << "Time of execution (According to main-pgm...): " << duration.count() << " microseconds" <<std::endl;
            }
        }
        myFile.close();
    }
    return 0;
}