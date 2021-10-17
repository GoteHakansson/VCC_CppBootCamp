#ifndef SUDOKUGRID_H
#define SUDOKUGRID_H
#include <iostream>
#include <vector>
#define N 9

class SudokuGrid{

private:

    typedef std::vector<int> vectorint_t;
    typedef std::vector<bool> vectorbool_t;
    typedef std::vector<std::string> vectorstr_t;
    typedef std::vector<char> vectorchar_t;
    typedef std::vector<std::vector<char>> vector2D_t;

    struct grid{
        int matrix[N][N];
    };

    struct square{
        std::string ID;
        vectorint_t possiblevalues = {1,2,3,4,5,6,7,8,9};
        int value = 0;
        bool analysefinalized = false;
        struct square *peers[20];
        struct square *unit1_row[9];
        struct square *unit2_colum[9];
        struct square *unit3_box[9];
    };

    typedef square square_t;
    typedef square_t *squareptr_t;
    typedef grid grid_t;
    typedef std::vector<std::vector<std::vector<squareptr_t>>> squarematrix_t;

    //=====================
    grid_t grid;
    //=====================

    vectorint_t row_values(int row);
    vectorint_t column_values(int column);
    vectorint_t squere_values(int squere);
    int squere (int row, int colum);

    vectorchar_t rows{'A',9};
    vector2D_t RowsColumsVector = {{'A','B',3,4},{1,2,3,4},{1,2,3,4,5}};

    square_t
        A1,A2,A3,A4,A5,A6,A7,A8,A9,
        B1,B2,B3,B4,B5,B6,B7,B8,B9,
        C1,C2,C3,C4,C5,C6,C7,C8,C9,
        D1,D2,D3,D4,D5,D6,D7,D8,D9,
        E1,E2,E3,E4,E5,E6,E7,E8,E9,
        F1,F2,F3,F4,F5,F6,F7,F8,F9,
        G1,G2,G3,G4,G5,G6,G7,G8,G9,
        H1,H2,H3,H4,H5,H6,H7,H8,H9,
        I1,I2,I3,I4,I5,I6,I7,I8,I9;

    //========================
    square_t squarematrix[N][N] =
    //========================

    {   {A1,A2,A3,A4,A5,A6,A7,A8,A9},
        {B1,B2,B3,B4,B5,B6,B7,B8,B9},
        {C1,C2,C3,C4,C5,C6,C7,C8,C9},
        {D1,D2,D3,D4,D5,D6,D7,D8,D9},
        {E1,E2,E3,E4,E5,E6,E7,E8,E9},
        {F1,F2,F3,F4,F5,F6,F7,F8,F9},
        {G1,G2,G3,G4,G5,G6,G7,G8,G9},
        {H1,H2,H3,H4,H5,H6,H7,H8,H9},
        {I1,I2,I3,I4,I5,I6,I7,I8,I9}
    };

    public:
        SudokuGrid(std::string filename);
        ~SudokuGrid();
        // void printGrid();
        // void assign(int row,int column, int value = 0);
        // void eliminate();
        // void print();
};

#endif // SUDOKUGRID_H
