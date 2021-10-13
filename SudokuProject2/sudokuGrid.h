#ifndef SUDOKUGRID_H
#define SUDOKUGRID_H
#include <iostream>
#include <vector>
#define N 9

class SudokuGrid{

private:

    struct grid{
        // std::string gridfilename;
        std::vector<int> values;
        int matrix[N][N];
        // std::vector<int> [N][N];
    };

    typedef grid grid_t;
    typedef std::vector<int> vector_t;


    //=====================
    grid_t grid;
    //=====================

    vector_t row_values(int row);
    vector_t column_values (int column);
    vector_t squere_values (int squere);
    int squere (int row, int colum);

public:
    SudokuGrid(std::string filename);
    ~SudokuGrid();
    // void printGrid();
    // void assign(int row,int column, int value = 0);
    // void eliminate();
    // void print();
};

#endif // SUDOKUGRID_H
