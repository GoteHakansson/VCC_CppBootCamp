#include <fstream>
#include "sudokuGrid.hh"
#include <iostream>

SudokuGrid::SudokuGrid(std::string fileName)
{

    int row, column = 0;
    int charcount = 0;
    std::string line = "";
    std::ifstream myFile;
    int checkLinePos = 0;

    myFile.open(fileName);

    while (myFile.good())
    {
        for (size_t row = 0; row < N; row++)
        {
            column = 0;
            checkLinePos = 0;
            getline(myFile, line, '\n');
            while (line[checkLinePos] != '\0')
            {
                if (line[checkLinePos] != ',')
                {
                    grid.matrix[row][column] = line[checkLinePos] - '0';
                    column++;
                    charcount++;
                }
                checkLinePos++;
            }
        }
    }
    myFile.close();
}

SudokuGrid::~SudokuGrid()
{
    //print the sudoku grid after solve
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (col == 3 || col == 6)
                std::cout << " | ";
            std::cout << grid.matrix[row][col] << " ";
        }
        if (row == 2 || row == 5)
        {
            std::cout << std::endl;
            for (int i = 0; i < N; i++)
                std::cout << "---";
        }
        std::cout << std::endl;
    }

    std::cout << "In descructor of class SudokuGrid!" << std::endl;
}

//void eliminate();
// void print();
