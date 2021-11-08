#include <fstream>
#include "sudokuGrid.hh"
#include <iostream>
#include <algorithm>
#include <chrono>

void SudokuGrid::SolveSudoku(std::string Sudukostr)
//==================================================
{
    ReadSudokuStr(Sudukostr);
    std::cout << "\nInitial SudokuGrid:\n";
    std::cout << "===================\n";
    PrintMatrix();

    // Perform Rule 1 of Constraint Propagation:
    //(1) If a square has only one possible value, then eliminate that value from the square's peers.
    //============================
    InitilizeSudokuSquareMatrix();
    //============================

    // Perform Rule 2 of Constraint Propagation:
    //(2) If a unit has only one possible place for a value, then put the value there.
    //================================
    TraverseSudokuSquareMatrixUnits();
    //================================

    if (SudokuGridSolved())
    {
        //=========================================
        // Contraint propagation solved the puzze.
        //=========================================
        std::cout << "The SudokuGrid was solved using Constraint Propagation!\n";
    }
    else
    {
        //================
        applyBruteForce();
        //================

        if (SudokuGridSolved())
        {
            //========================================
            // Search (brute force) solved the puzzle.
            //========================================
            std::cout << "The SudokuGrid was solved using Brute Force!\n";
        }
        else
        {
            //===============================================
            std::cout << "The SudokuGrid is NOT SOLVABLE!\n";
            //===============================================
        }
    }

    //===================================================================
    // Print out the result(s) of the ambition to solve the sudoku puzzle.
    //===================================================================

    std::cout << "\n\nLayout of the produced (solved) SudokuGrid puzzle:\n";
    std::cout << "=======================================================\n";
    PrintsquareMatrixValues();

    std::cout << std::endl;

    std::cout << "Layout of the (final) hypothesis for the SudokuGrid puzzle:\n";
    std::cout << "(Possible Remaining Guesses After Constraint Propagation)\n";
    std::cout << "=============================================================\n";
    PrintsquareMatrixHypos();
}

SudokuGrid::SudokuGrid()
//======================
{
    // std::cout << "\nIn the constructor of class SudokuGrid!" << std::endl << std::endl;

    SudokuGrid::InitilizeSquare("A1",0,0);
    SudokuGrid::InitilizeSquare("A2",0,1);
    SudokuGrid::InitilizeSquare("A3",0,2);
    SudokuGrid::InitilizeSquare("A4",0,3);
    SudokuGrid::InitilizeSquare("A5",0,4);
    SudokuGrid::InitilizeSquare("A6",0,5);
    SudokuGrid::InitilizeSquare("A7",0,6);
    SudokuGrid::InitilizeSquare("A8",0,7);
    SudokuGrid::InitilizeSquare("A9",0,8);
    SudokuGrid::InitilizeSquare("B1",1,0);
    SudokuGrid::InitilizeSquare("B2",1,1);
    SudokuGrid::InitilizeSquare("B3",1,2);
    SudokuGrid::InitilizeSquare("B4",1,3);
    SudokuGrid::InitilizeSquare("B5",1,4);
    SudokuGrid::InitilizeSquare("B6",1,5);
    SudokuGrid::InitilizeSquare("B7",1,6);
    SudokuGrid::InitilizeSquare("B8",1,7);
    SudokuGrid::InitilizeSquare("B9",1,8);
    SudokuGrid::InitilizeSquare("C1",2,0);
    SudokuGrid::InitilizeSquare("C2",2,1);
    SudokuGrid::InitilizeSquare("C3",2,2);
    SudokuGrid::InitilizeSquare("C4",2,3);
    SudokuGrid::InitilizeSquare("C5",2,4);
    SudokuGrid::InitilizeSquare("C6",2,5);
    SudokuGrid::InitilizeSquare("C7",2,6);
    SudokuGrid::InitilizeSquare("C8",2,7);
    SudokuGrid::InitilizeSquare("C9",2,8);
    SudokuGrid::InitilizeSquare("D1",3,0);
    SudokuGrid::InitilizeSquare("D2",3,1);
    SudokuGrid::InitilizeSquare("D3",3,2);
    SudokuGrid::InitilizeSquare("D4",3,3);
    SudokuGrid::InitilizeSquare("D5",3,4);
    SudokuGrid::InitilizeSquare("D6",3,5);
    SudokuGrid::InitilizeSquare("D7",3,6);
    SudokuGrid::InitilizeSquare("D8",3,7);
    SudokuGrid::InitilizeSquare("D9",3,8);
    SudokuGrid::InitilizeSquare("E1",4,0);
    SudokuGrid::InitilizeSquare("E2",4,1);
    SudokuGrid::InitilizeSquare("E3",4,2);
    SudokuGrid::InitilizeSquare("E4",4,3);
    SudokuGrid::InitilizeSquare("E5",4,4);
    SudokuGrid::InitilizeSquare("E6",4,5);
    SudokuGrid::InitilizeSquare("E7",4,6);
    SudokuGrid::InitilizeSquare("E8",4,7);
    SudokuGrid::InitilizeSquare("E9",4,8);
    SudokuGrid::InitilizeSquare("F1",5,0);
    SudokuGrid::InitilizeSquare("F2",5,1);
    SudokuGrid::InitilizeSquare("F3",5,2);
    SudokuGrid::InitilizeSquare("F4",5,3);
    SudokuGrid::InitilizeSquare("F5",5,4);
    SudokuGrid::InitilizeSquare("F6",5,5);
    SudokuGrid::InitilizeSquare("F7",5,6);
    SudokuGrid::InitilizeSquare("F8",5,7);
    SudokuGrid::InitilizeSquare("F9",5,8);
    SudokuGrid::InitilizeSquare("G1",6,0);
    SudokuGrid::InitilizeSquare("G2",6,1);
    SudokuGrid::InitilizeSquare("G3",6,2);
    SudokuGrid::InitilizeSquare("G4",6,3);
    SudokuGrid::InitilizeSquare("G5",6,4);
    SudokuGrid::InitilizeSquare("G6",6,5);
    SudokuGrid::InitilizeSquare("G7",6,6);
    SudokuGrid::InitilizeSquare("G8",6,7);
    SudokuGrid::InitilizeSquare("G9",6,8);
    SudokuGrid::InitilizeSquare("H1",7,0);
    SudokuGrid::InitilizeSquare("H2",7,1);
    SudokuGrid::InitilizeSquare("H3",7,2);
    SudokuGrid::InitilizeSquare("H4",7,3);
    SudokuGrid::InitilizeSquare("H5",7,4);
    SudokuGrid::InitilizeSquare("H6",7,5);
    SudokuGrid::InitilizeSquare("H7",7,6);
    SudokuGrid::InitilizeSquare("H8",7,7);
    SudokuGrid::InitilizeSquare("H9",7,8);
    SudokuGrid::InitilizeSquare("I1",8,0);
    SudokuGrid::InitilizeSquare("I2",8,1);
    SudokuGrid::InitilizeSquare("I3",8,2);
    SudokuGrid::InitilizeSquare("I4",8,3);
    SudokuGrid::InitilizeSquare("I5",8,4);
    SudokuGrid::InitilizeSquare("I6",8,5);
    SudokuGrid::InitilizeSquare("I7",8,6);
    SudokuGrid::InitilizeSquare("I8",8,7);
    SudokuGrid::InitilizeSquare("I9",8,8);
}

SudokuGrid::~SudokuGrid()
//=======================
{
    // std::cout << "\nIn the destructor of class SudokuGrid!" << std::endl << std::endl;
}

void SudokuGrid::ReadSudokuStr(std::string SudokuStr)
//===================================================
{
    int checkLinePos = 0;

    for (size_t gridRow = 0; gridRow < N; gridRow++)
    {
        for (size_t gridColumn = 0; gridColumn < N; gridColumn++)
        {
            if (SudokuStr[checkLinePos] == '.')
            {
                grid.matrix[gridRow][gridColumn] = 0;
                // std::cout << "Read '.': " << line[checkLinePos] << std::endl;
                // std::cout << "Read character: " << line[checkLinePos] - '0' << std::endl;
            }
            else
            {
                grid.matrix[gridRow][gridColumn] = SudokuStr[checkLinePos] - '0';
                // std::cout << "Read character: " << line[checkLinePos] - '0' << std::endl;
            }
            checkLinePos++;
        }
    }
}

void SudokuGrid::InitilizeSquare(std::string ID, int row, int column)
//====================================================================================
{
    square_t *currentSquare = squarematrix[row][column];
    int boxRow = (row / 3) * 3;
    int boxColumn = column - (column % 3);
    int gridBox = 0;
    int peerNr =0;
    bool rowPeersDone = false;
    bool columnPeersDone = false;
    bool boxPeersDone = false;
    int dummy;

    currentSquare->ID = ID;
    currentSquare->possiblevalues = {1,2,3,4,5,6,7,8,9};
    currentSquare->value = 0;
    currentSquare->analysefinalized = false;
    
    for (size_t gridColumn = 0; gridColumn < N; gridColumn++)
    {        
        currentSquare->unit1_row[gridColumn] = squarematrix[row][gridColumn];
    }

    for (size_t gridRow = 0; gridRow < N; gridRow++)
    {
        currentSquare->unit2_colum[gridRow] = squarematrix[gridRow][column];
    }

    for (size_t boxR = boxRow; boxR < boxRow + 3; boxR++)
    {
        for (size_t boxC = boxColumn; boxC < boxColumn + 3; boxC++)
        {
            currentSquare->unit3_box[gridBox] = squarematrix[boxC][boxR];
            gridBox++;
        }
    }

    if (!rowPeersDone)
    {
        for (size_t gridColumn = 0; gridColumn < N; gridColumn++)
        {
            if (column != gridColumn)
            {
                currentSquare->peers[peerNr] = currentSquare->unit1_row[gridColumn];
                peerNr++;
            }
        }
        rowPeersDone = true;
    }

    if (!columnPeersDone)
    {
        for (size_t gridRow = 0; gridRow < N; gridRow++)
        {
            if (row != gridRow)
            {
                currentSquare->peers[peerNr] = currentSquare->unit2_colum[gridRow];
                peerNr++;
            }
        }
        columnPeersDone = true;
    }

    boxRow = (row / 3) * 3;
    boxColumn = column - (column % 3);

    if (!boxPeersDone)
    {

        for (size_t boxR = boxRow; boxR < boxRow + 3; boxR++)
        {
            for (size_t boxC = boxColumn; boxC < boxColumn + 3; boxC++)
            {
                if ((boxR != row) && (boxC != column))
                {
                    currentSquare->peers[peerNr] = squarematrix[boxR][boxC];
                    peerNr++;
                }
            }
        }

        boxPeersDone = true;
    }
}

void SudokuGrid::InitilizeSudokuSquareMatrix()
//============================================
{
    for (size_t row = 0; row < N; row++)
    {
        for (size_t column = 0; column < N; column++)
        {
            if (SudokuGrid::grid.matrix[row][column] != 0)
            {
                SetInitialSquareValue(SudokuGrid::squarematrix[row][column],SudokuGrid::grid.matrix[row][column]);
            }
        }
    }

    for (size_t row = 0; row < N; row++)
    {
        for (size_t column = 0; column < N; column++)
        {
            if (squarematrix[row][column]->value == 0)
            {
                InitilizeSquareUnits(squarematrix[row][column]);
            }
        }
    }
}

void SudokuGrid::SetInitialSquareValue(squareptr_t &square, int value)
//===================================================================
{
    int dummy;

    if (!square->analysefinalized)
    {
        square->value = value;
        square->possiblevalues.clear();
        square->possiblevalues.push_back(square->value);
        square->analysefinalized = true;

        // std::cout << "ID: " << square->ID << "\n";
        // std::cout << "Value: " << square->value << "\n";
        // std::cout << "Number of Possiblevalued :" << square->possiblevalues.size() << std::endl;
        // std::cout << std::endl;

        for (size_t peernr = 0; peernr < NrOfPeers; peernr++)
        {
            // std::cout << "Peer.ID: " << square->peers[peernr]->ID << "\n";
            // std::cout << "Peer-Value: " << square->peers[peernr]->value << "\n";
            // std::cout << "Peer-Number of Possiblevalues :" << square->peers[peernr]->possiblevalues.size() << std::endl;

            if (square->peers[peernr]->possiblevalues.size() == 1)
            {
                SetInitialSquareValue(square->peers[peernr],
                square->peers[peernr]->possiblevalues.front());
            }
            else
            {
                square->peers[peernr]->possiblevalues.erase(
                std::remove(square->peers[peernr]->possiblevalues.begin(),
                square->peers[peernr]->possiblevalues.end(),
                square->value),square->peers[peernr]->possiblevalues.end());
            }
        }
    }
}

void SudokuGrid::InitilizeSquareUnits(squareptr_t square)
//========================================================
{

    for (size_t i = 0; i < 9; i++)
    {
        if (square->unit1_row[i]->possiblevalues.size() == 1)
        {
            SetSquareValue(square->unit1_row[i],square->unit1_row[i]->possiblevalues.front());
        }
    }

    for (size_t i = 0; i < 9; i++)
    {
        if (square->unit2_colum[i]->possiblevalues.size() == 1)
        {
            SetSquareValue(square->unit2_colum[i],square->unit2_colum[i]->possiblevalues.front());
        }
    }

    for (size_t i = 0; i < 9; i++)
   {
       if (square->unit3_box[i]->possiblevalues.size() == 1)
       {
           SetSquareValue(square->unit3_box[i],square->unit3_box[i]->possiblevalues.front());
       }
   }

}

void SudokuGrid::SetSquareValue(squareptr_t square, int value)
//============================================================
{
    // int dummy;

    if (square->analysefinalized != true)
    {
        // std::cout << "inside setSquareValue for ID: " << square->ID << std::endl;
        // std::cout << "inside setSquarevalue using value: " << value << std::endl;

        SudokuGrid::vectorint_t::iterator hypoToRemove;
        square->value = value;
        hypoToRemove = square->possiblevalues.begin() + (square->value - 1);
        square->possiblevalues.clear();
        square->possiblevalues.push_back(square->value);
        square->analysefinalized = true;

        for (size_t peernr = 0; peernr < NrOfPeers; peernr++)
        {                     
            if (square->peers[peernr]->possiblevalues.size() == 1)
            {
                SetInitialSquareValue(square->peers[peernr],
                square->peers[peernr]->possiblevalues.front());
            }
            else
            {
                square->peers[peernr]->possiblevalues.erase(
                std::remove(square->peers[peernr]->possiblevalues.begin(),
                square->peers[peernr]->possiblevalues.end(),
                square->value),square->peers[peernr]->possiblevalues.end());
            }           
        }
    }

/*
    std::cout << "\nCurrent layout of SquareMatrix:\n(Working values towards solution of SudokuGrid)\n";
    std::cout << "========================================\n";
    PrintsquareMatrixValues();

    std::cout << std::endl;

    std::cout << "Current layout of SquareMatrix Hypotesis:\n(Working possiblevalues towards solution of SudokuGrid)\n";
    std::cout << "==========================================\n";
    PrintsquareMatrixHypos();

    std::cin >> dummy;
*/

}

void SudokuGrid::TraverseSudokuSquareMatrixUnits()
//==========================================
{
    for (size_t row = 0; row < N; row++)
    {
        for (size_t column = 0; column < N; column++)
        {
            TraverseSquareUnits(squarematrix[row][column]);
        }
    }
}

bool SudokuGrid::SudokuGridSolved()
//================================
{   
    bool Solved = true;

    for (size_t row = 0; row < N; row++)
    {
        for (size_t column = 0; column < N; column++)
        {
            if ( squarematrix[row][column]->analysefinalized == false)
            {
                Solved = false;
                break;
            }
        }
    }
    return Solved;
}

void SudokuGrid::TraverseSquareUnits(squareptr_t square)
//================================================
{
    TraverseUnit(square->unit1_row);
    TraverseUnit(square->unit2_colum);
    TraverseUnit(square->unit3_box);
}

void SudokuGrid::TraverseUnit(squareptr_t *unit)
//==============================================
{
    SudokuGrid:vectorint_t Temp1Vec ={}, Tmp2Vec = {};
    // int dummy;

    for (size_t i = 0; i < 9; i++)
    {
        if (unit[i]->value == 0)
        {
            Temp1Vec.insert(Temp1Vec.begin(),
            unit[i]->possiblevalues.begin(),
            unit[i]->possiblevalues.end());
        }
    }

    for (auto i = Temp1Vec.cbegin(); i < Temp1Vec.cend(); i++)
    {
        if (std::count(Temp1Vec.begin(), Temp1Vec.end(), *i)== 1)
        {
            Tmp2Vec.push_back(*i);
        }
    }

    // std::cout << "\nContent of traversed concatenated possible row values for IDs : \n";
    for (auto i = Tmp2Vec.cbegin(); i < Tmp2Vec.cend(); i++)
    {
        // std::cout << *i << " \n";

        for (size_t j = 0; j < 9; j++)
        {
            if (std::count(unit[j]->possiblevalues.begin(),
                           unit[j]->possiblevalues.end(), *i) == 1)
            {
                SetSquareValue(unit[j], *i);
            }
        }
    }
}

void SudokuGrid::PrintMatrix()
//============================
{

    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (col == 3 || col == 6)
                std::cout << " | ";
            std::cout << SudokuGrid::grid.matrix[row][col] << " ";
        }
        if (row == 2 || row == 5)
        {
            std::cout << std::endl;
            for (int i = 0; i < N; i++)
                std::cout << "---";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void SudokuGrid::PrintsquareMatrixValues()
//========================================
{
    
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (col == 3 || col == 6)
                std::cout << " | ";
            std::cout << SudokuGrid::squarematrix[row][col]->value << " ";
            // std::cout << SudokuGrid::squarematrix[row][col]->analysefinalized << " ";
        }
        if (row == 2 || row == 5)
        {
            std::cout << std::endl;
            for (int i = 0; i < N; i++)
                std::cout << "---";
        }
        std::cout << std::endl;
    }
}

void SudokuGrid::PrintsquareMatrixHypos()
//=======================================
{

    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (col == 3 || col == 6)
            {
                std::cout << " | ";
            }

            for (auto i = SudokuGrid::squarematrix[row][col]->possiblevalues.begin();
                 i != SudokuGrid::squarematrix[row][col]->possiblevalues.end(); ++i)
            {
                std::cout << *i;
            }
            std::cout << "\t";
        }
        std::cout << "\n";

        if (row == 2 || row == 5)
        {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

//=================================================
// Code Implementing Bruce Force
//=================================================

bool SudokuGrid::isPresentInCol(int col, int num)
//-----------------------------------------------
{ // check whether num is present in col or not
    for (int row = 0; row < N; row++)
        if (squarematrix[row][col]->value == num)
        {
            return true;
        }
    return false;
}

bool SudokuGrid::isPresentInRow(int row, int num)
//-----------------------------------------------
{ // check whether num is present in row or not
    for (int col = 0; col < N; col++)
        if (squarematrix[row][col]->value == num)
        {
            return true;
        }
    return false;
}

bool SudokuGrid::isPresentInBox(int boxStartRow, int boxStartCol, int num)
//------------------------------------------------------------------------
{ // check whether num is present in 3x3 box or not
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (squarematrix[row + boxStartRow][col + boxStartCol]->value == num)
            {
                return true;
            }
    return false;
}

void SudokuGrid::printBruceForceSudokuGrid()
//-----------------------------------------
{ // print the sudoku grid after solve
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (col == 3 || col == 6)
                std::cout << " | ";
            std::cout << squarematrix[row][col]->value << " ";
        }
        if (row == 2 || row == 5)
        {
            std::cout << std::endl;
            for (int i = 0; i < N; i++)
                std::cout << "---";
        }
        std::cout << std::endl;
    }
}

bool SudokuGrid::findEmptyPlace(int &row, int &col)
//------------------------------------------------
{ // get empty location and update row and column
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (squarematrix[row][col]->value == 0) // marked with 0 is empty
            {
                return true;
            }
    return false;
}

bool SudokuGrid::isValidPlace(int row, int col, int num)
//------------------------------------------------------
{
    // when item not found in col, row and current 3x3 box
    return !isPresentInRow(row, num) && !isPresentInCol(col, num) &&
           !isPresentInBox(row - row % 3, col - col % 3, num);
}

bool SudokuGrid::applyBruteForce()
//=================================
{
    int row, col;
    if (!findEmptyPlace(row, col))
        return true; // when all places are filled
    for (int num = 1; num <= 9; num++)
    { // valid numbers are 1 - 9
        if (isValidPlace(row, col, num))
        { // check validation, if yes, put the number in the grid
            squarematrix[row][col]->value = num;
            squarematrix[row][col]->analysefinalized = true;
            if (applyBruteForce()) // recursively go for other rooms in the grid
                return true;
            SudokuGrid::squarematrix[row][col]->value = 0; // turn to unassigned space when conditions are not satisfied
        }
    }
    return false;
}

//=================================================
// End Of Code Implementing Bruce Force
//=================================================
