#include <iostream>
#include "sudokuGrid.hh"

int main() {
    std::string MyGridFile = "./MyCsvFileSolvable.csv";
    // std::string MyGridFile = "./MyCsvFileUnsolvable.csv";
    SudokuGrid MyGrid(MyGridFile);
    return 0;
}
