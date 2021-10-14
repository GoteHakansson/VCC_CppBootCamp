#include <iostream>
#include "sudokuGrid.hh"

int main() {
    std::string MyGridFile = "./MyCsvFileSolvable.csv";
    SudokuGrid MyGrid(MyGridFile);
    return 0;
}
