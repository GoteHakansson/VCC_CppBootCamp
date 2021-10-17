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

    square_t A1 =
    {"A1",{1,2,3,4,5,6,7,8,9},0,false,
        {&A2,&A3,&A4,&A5,&A6,&A7,&A8,&A9,&B1,&C1,
        &D1,&E1,&F1,&G1,&H1,&I1,&B2,&B3,&C2,&C3},
        {&A1,&A2,&A3,&A4,&A5,&A6,&A7,&A8,&A9},
        {&A1,&B1,&C1,&D1,&E1,&F1,&G1,&H1,&I1},
        {&A1,&B1,&C1,&A2,&B2,&C2,&A3,&B3,&C3}
    };

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
