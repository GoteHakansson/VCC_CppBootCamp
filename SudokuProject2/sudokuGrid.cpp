#include <fstream>
#include "sudokuGrid.hh"
#include <iostream>
#include <algorithm>

SudokuGrid::SudokuGrid(std::string fileName)
//==========================================
{
    // std::cout << "\nIn the constructor of class SudokuGrid!" << std::endl << std::endl;

    ReadSudokuFile(fileName);

    std::cout << "\nInitial SudokuGrid:\n";
    std::cout << "===================\n";
    PrintMatrix();

    A1 =
    {"A1",{1,2,3,4,5,6,7,8,9},0,false,
        {&A2,&A3,&A4,&A5,&A6,&A7,&A8,&A9,&B1,&C1,
        &D1,&E1,&F1,&G1,&H1,&I1,&B2,&B3,&C2,&C3},
        {&A1,&A2,&A3,&A4,&A5,&A6,&A7,&A8,&A9},
        {&A1,&B1,&C1,&D1,&E1,&F1,&G1,&H1,&I1},
        {&A1,&B1,&C1,&A2,&B2,&C2,&A3,&B3,&C3}
    };

    A2 =
    {"A2",{1,2,3,4,5,6,7,8,9},0,false,
        {&A1,&A3,&A4,&A5,&A6,&A7,&A8,&A9,&B2,&C2,
        &D2,&E2,&F2,&G2,&H2,&I2,&B1,&B3,&C1,&C3},
        {&A1,&A2,&A3,&A4,&A5,&A6,&A7,&A8,&A9},
        {&A2,&B2,&C2,&D2,&E2,&F2,&G2,&H2,&I2},
        {&A1,&B1,&C1,&A2,&B2,&C2,&A3,&B3,&C3}
    };

    A3 =
    {"A3",{1,2,3,4,5,6,7,8,9},0,false,
        {&A1,&A2,&A4,&A5,&A6,&A7,&A8,&A9,&B3,&C3,
        &D3,&E3,&F3,&G3,&H3,&I3,&B1,&B2,&C1,&C2},
        {&A1,&A2,&A3,&A4,&A5,&A6,&A7,&A8,&A9},
        {&A3,&B3,&C3,&D3,&E3,&F3,&G3,&H3,&I3},
        {&A1,&B1,&C1,&A2,&B2,&C2,&A3,&B3,&C3}
    };

    A4 =
    {"A4",{1,2,3,4,5,6,7,8,9},0,false,
        {&A1,&A2,&A3,&A5,&A6,&A7,&A8,&A9,&B4,&C4,
        &D4,&E4,&F4,&G4,&H4,&I4,&B5,&B6,&C5,&C6},
        {&A1,&A2,&A3,&A4,&A5,&A6,&A7,&A8,&A9},
        {&A4,&B4,&C4,&D4,&E4,&F4,&G4,&H4,&I4},
        {&A4,&B4,&C4,&A5,&B5,&C5,&A6,&B6,&C6}
    };

    A5 =
    {"A5",{1,2,3,4,5,6,7,8,9},0,false,
        {&A1,&A2,&A3,&A4,&A6,&A7,&A8,&A9,&B5,&C5,
        &D5,&E5,&F5,&G5,&H5,&I5,&B4,&B6,&C4,&C6},
        {&A1,&A2,&A3,&A4,&A5,&A6,&A7,&A8,&A9},
        {&A5,&B5,&C5,&D5,&E5,&F5,&G5,&H5,&I5},
        {&A4,&B4,&C4,&A5,&B5,&C5,&A6,&B6,&C6}
    };

    A6 =
    {"A6",{1,2,3,4,5,6,7,8,9},0,false,
        {&A1,&A2,&A3,&A4,&A5,&A7,&A8,&A9,&B6,&C6,
        &D6,&E6,&F6,&G6,&H6,&I6,&B4,&B5,&C4,&C5},
        {&A1,&A2,&A3,&A4,&A5,&A6,&A7,&A8,&A9},
        {&A6,&B6,&C6,&D6,&E6,&F6,&G6,&H6,&I6},
        {&A4,&B4,&C4,&A5,&B5,&C5,&A6,&B6,&C6}
    };

    A7 =
    {"A7",{1,2,3,4,5,6,7,8,9},0,false,
        {&A1,&A2,&A3,&A4,&A5,&A6,&A8,&A9,&B7,&C7,
        &D7,&E7,&F7,&G7,&H7,&I7,&B8,&B9,&C8,&C9},
        {&A1,&A2,&A3,&A4,&A5,&A6,&A7,&A8,&A9},
        {&A7,&B7,&C7,&D7,&E7,&F7,&G7,&H7,&I7},
        {&A7,&B7,&C7,&A8,&B8,&C8,&A9,&B9,&C9}
    };

    A8 =
    {"A8",{1,2,3,4,5,6,7,8,9},0,false,
        {&A1,&A2,&A3,&A4,&A5,&A6,&A7,&A9,&B8,&C8,
        &D8,&E8,&F8,&G8,&H8,&I8,&B7,&B9,&C7,&C9},
        {&A1,&A2,&A3,&A4,&A5,&A6,&A7,&A8,&A9},
        {&A8,&B8,&C8,&D8,&E8,&F8,&G8,&H8,&I8},
        {&A7,&B7,&C7,&A8,&B8,&C8,&A9,&B9,&C9}

    };

    A9 =
    {"A9",{1,2,3,4,5,6,7,8,9},0,false,
        {&A1,&A2,&A3,&A4,&A5,&A6,&A7,&A8,&B9,&C9,
        &D9,&E9,&F9,&G9,&H9,&I9,&B7,&B8,&C7,&C8},
        {&A1,&A2,&A3,&A4,&A5,&A6,&A7,&A8,&A9},
        {&A9,&B9,&C9,&D9,&E9,&F9,&G9,&H9,&I9},
        {&A7,&B7,&C7,&A8,&B8,&C8,&A9,&B9,&C9}
    };

    B1 =
    {"B1",{1,2,3,4,5,6,7,8,9},0,false,
        {&B2,&B3,&B4,&B5,&B6,&B7,&B8,&B9,&A1,&C1,
        &D1,&E1,&F1,&G1,&H1,&I1,&A2,&A3,&C2,&C3},
        {&B1,&B2,&B3,&B4,&B5,&B6,&B7,&B8,&B9},
        {&A1,&B1,&C1,&D1,&E1,&F1,&G1,&H1,&I1},
        {&A1,&B1,&C1,&A2,&B2,&C2,&A3,&B3,&C3}
    };

    B2 =
    {"B2",{1,2,3,4,5,6,7,8,9},0,false,
        {&B1,&B3,&B4,&B5,&B6,&B7,&B8,&B9,&A2,&C2,
        &D2,&E2,&F2,&G2,&H2,&I2,&A1,&A3,&C1,&C3},
        {&B1,&B2,&B3,&B4,&B5,&B6,&B7,&B8,&B9},
        {&A2,&B2,&C2,&D2,&E2,&F2,&G2,&H2,&I2},
        {&A1,&B1,&C1,&A2,&B2,&C2,&A3,&B3,&C3}
    };

    B3 =
    {"B3",{1,2,3,4,5,6,7,8,9},0,false,
        {&B1,&B2,&B4,&B5,&B6,&B7,&B8,&B9,&A3,&C3,
        &D3,&E3,&F3,&G3,&H3,&I3,&A1,&A2,&C1,&C2},
        {&B1,&B2,&B3,&B4,&B5,&B6,&B7,&B8,&B9},
        {&A3,&B3,&C3,&D3,&E3,&F3,&G3,&H3,&I3},
        {&A1,&B1,&C1,&A2,&B2,&C2,&A3,&B3,&C3}
    };

    B4 =
    {"B4",{1,2,3,4,5,6,7,8,9},0,false,
        {&B1,&B2,&B3,&B5,&B6,&B7,&B8,&B9,&A4,&C4,
        &D4,&E4,&F4,&G4,&H4,&I4,&A5,&A6,&C5,&C6},
        {&B1,&B2,&B3,&B4,&B5,&B6,&B7,&B8,&B9},
        {&A4,&B4,&C4,&D4,&E4,&F4,&G4,&H4,&I4},
        {&A4,&B4,&C4,&A5,&B5,&C5,&A6,&B6,&C6}
    };

    B5 =
    {"B5",{1,2,3,4,5,6,7,8,9},0,false,
        {&B1,&B2,&B3,&B4,&B6,&B7,&B8,&B9,&A5,&C5,
        &D5,&E5,&F5,&G5,&H5,&I5,&A4,&A6,&C4,&C6},
        {&B1,&B2,&B3,&B4,&B5,&B6,&B7,&B8,&B9},
        {&A5,&B5,&C5,&D5,&E5,&F5,&G5,&H5,&I5},
        {&A4,&B4,&C4,&A5,&B5,&C5,&A6,&B6,&C6}
    };

    B6 =
    {"B6",{1,2,3,4,5,6,7,8,9},0,false,
        {&B1,&B2,&B3,&B4,&B5,&B7,&B8,&B9,&A6,&C6,
        &D6,&E6,&F6,&G6,&H6,&I6,&A4,&A5,&C4,&C5},
        {&B1,&B2,&B3,&B4,&B5,&B6,&B7,&B8,&B9},
        {&A6,&B6,&C6,&D6,&E6,&F6,&G6,&H6,&I6},
        {&A4,&B4,&C4,&A5,&B5,&C5,&A6,&B6,&C6}
    };

    B7 =
    {"B7",{1,2,3,4,5,6,7,8,9},0,false,
        {&B1,&B2,&B3,&B4,&B5,&B6,&B8,&B9,&A7,&C7,
        &D7,&E7,&F7,&G7,&H7,&I7,&A8,&A9,&C8,&C9},
        {&B1,&B2,&B3,&B4,&B5,&B6,&B7,&B8,&B9},
        {&A7,&B7,&C7,&D7,&E7,&F7,&G7,&H7,&I7},
        {&A7,&B7,&C7,&A8,&B8,&C8,&A9,&B9,&C9}
    };

    B8 =
    {"B8",{1,2,3,4,5,6,7,8,9},0,false,
        {&B1,&B2,&B3,&B4,&B5,&B6,&B7,&B9,&A8,&C8,
        &D8,&E8,&F8,&G8,&H8,&I8,&A7,&A9,&C7,&C9},
        {&B1,&B2,&B3,&B4,&B5,&B6,&B7,&B8,&B9},
        {&A8,&B8,&C8,&D8,&E8,&F8,&G8,&H8,&I8},
        {&A7,&B7,&C7,&A8,&B8,&C8,&A9,&B9,&C9}
    };

    B9 =
    {"B9",{1,2,3,4,5,6,7,8,9},0,false,
        {&B1,&B2,&B3,&B4,&B5,&B6,&B7,&B8,&B9,&A9,
        &D9,&E9,&F9,&G9,&H9,&I9,&A7,&A8,&C7,&C8},
        {&B1,&B2,&B3,&B4,&B5,&B6,&B7,&B8,&B9},
        {&A9,&B9,&C9,&D9,&E9,&F9,&G9,&H9,&I9},
        {&A7,&B7,&C7,&A8,&B8,&C8,&A9,&B9,&C9}
    };

    C1 =
    {"C1",{1,2,3,4,5,6,7,8,9},0,false,
        {&C2,&C3,&C4,&C5,&C6,&C7,&C8,&C9,&A1,&B1,
        &D1,&E1,&F1,&G1,&H1,&I1,&A2,&A3,&B2,&B3},
        {&C1,&C2,&C3,&C4,&C5,&C6,&C7,&C8,&C9},
        {&A1,&B1,&C1,&D1,&E1,&F1,&G1,&H1,&I1},
        {&A1,&B1,&C1,&A2,&B2,&C2,&A3,&B3,&C3}
    };

    C2 =
    {"C2",{1,2,3,4,5,6,7,8,9},0,false,
        {&C1,&C3,&C4,&C5,&C6,&C7,&C8,&C9,&A2,&B2,
        &D2,&E2,&F2,&G2,&H2,&I2,&A1,&A3,&B1,&B3},
        {&C1,&C2,&C3,&C4,&C5,&C6,&C7,&C8,&C9},
        {&A2,&B2,&C2,&D2,&E2,&F2,&G2,&H2,&I2},
        {&A1,&B1,&C1,&A2,&B2,&C2,&A3,&B3,&C3}
    };

    C3 =
    {"C3",{1,2,3,4,5,6,7,8,9},0,false,
        {&C1,&C2,&C4,&C5,&C6,&C7,&C8,&C9,&A3,&B3,
        &D3,&E3,&F3,&G3,&H3,&I3,&A1,&A2,&B1,&B2},
        {&C1,&C2,&C3,&C4,&C5,&C6,&C7,&C8,&C9},
        {&A3,&B3,&C3,&D3,&E3,&F3,&G3,&H3,&I3},
        {&A1,&B1,&C1,&A2,&B2,&C2,&A3,&B3,&C3}
    };

    C4 =
    {"C4",{1,2,3,4,5,6,7,8,9},0,false,
        {&C1,&C2,&C3,&C5,&C6,&C7,&C8,&C9,&A4,&B4,
        &D4,&E4,&F4,&G4,&H4,&I4,&A5,&A6,&B5,&B6},
        {&C1,&C2,&C3,&C4,&C5,&C6,&C7,&C8,&C9},
        {&A4,&B4,&C4,&D4,&E4,&F4,&G4,&H4,&I4},
        {&A4,&B4,&C4,&A5,&B5,&C5,&A6,&B6,&C6}
    };

    C5 =
    {"C5",{1,2,3,4,5,6,7,8,9},0,false,
        {&C1,&C2,&C3,&C4,&C6,&C7,&C8,&C9,&A5,&B5,
        &D5,&E5,&F5,&G5,&H5,&I5,&A4,&A6,&B4,&B6},
        {&C1,&C2,&C3,&C4,&C5,&C6,&C7,&C8,&C9},
        {&A5,&B5,&C5,&D5,&E5,&F5,&G5,&H5,&I5},
        {&A4,&B4,&C4,&A5,&B5,&C5,&A6,&B6,&C6}
    };

    C6 =
    {"C6",{1,2,3,4,5,6,7,8,9},0,false,
        {&C1,&C2,&C3,&C4,&C5,&C7,&C8,&C9,&A6,&B6,
        &D6,&E6,&F6,&G6,&H6,&I6,&A4,&A5,&B4,&B5},
        {&C1,&C2,&C3,&C4,&C5,&C6,&C7,&C8,&C9},
        {&A6,&B6,&C6,&D6,&E6,&F6,&G6,&H6,&I6},
        {&A4,&B4,&C4,&A5,&B5,&C5,&A6,&B6,&C6}
    };

    C7 =
    {"C7",{1,2,3,4,5,6,7,8,9},0,false,
        {&C1,&C2,&C3,&C4,&C5,&C6,&C8,&C9,&A7,&B7,
        &D7,&E7,&F7,&G7,&H7,&I7,&A8,&A9,&B8,&B9},
        {&C1,&C2,&C3,&C4,&C5,&C6,&C7,&C8,&C9},
        {&A7,&B7,&C7,&D7,&E7,&F7,&G7,&H7,&I7},
        {&A7,&B7,&C7,&A8,&B8,&C8,&A9,&B9,&C9}
    };

    C8 =
    {"C8",{1,2,3,4,5,6,7,8,9},0,false,
        {&C1,&C2,&C3,&C4,&C5,&C6,&C7,&C9,&A8,&B8,
        &D8,&E8,&F8,&G8,&H8,&I8,&A7,&A9,&B7,&B9},
        {&C1,&C2,&C3,&C4,&C5,&C6,&C7,&C8,&C9},
        {&A8,&B8,&C8,&D8,&E8,&F8,&G8,&H8,&I8},
        {&A7,&B7,&C7,&A8,&B8,&C8,&A9,&B9,&C9}
    };

    C9 =
    {"C9",{1,2,3,4,5,6,7,8,9},0,false,
        {&C1,&C2,&C3,&C4,&C5,&C6,&C7,&C8,&A9,&B9,
        &D9,&E9,&F9,&G9,&H9,&I9,&A7,&A8,&B7,&B8},
        {&C1,&C2,&C3,&C4,&C5,&C6,&C7,&C8,&C9},
        {&A9,&B9,&C9,&D9,&E9,&F9,&G9,&H9,&I9},
        {&A7,&B7,&C7,&A8,&B8,&C8,&A9,&B9,&C9}
    };

    D1 =
    {"D1",{1,2,3,4,5,6,7,8,9},0,false,
        {&D2,&D3,&D4,&D5,&D6,&D7,&D8,&D9,&A1,&B1,
        &C1,&E1,&F1,&G1,&H1,&I1,&E2,&E3,&F2,&F3},
        {&D1,&D2,&D3,&D4,&D5,&D6,&D7,&D8,&D9},
        {&A1,&B1,&C1,&D1,&E1,&F1,&G1,&H1,&I1},
        {&D1,&E1,&F1,&D2,&E2,&F2,&D3,&E3,&F3}
    };

    D2 =
    {"D2",{1,2,3,4,5,6,7,8,9},0,false,
        {&D1,&D3,&D4,&D5,&D6,&D7,&D8,&D9,&A2,&B2,
        &C2,&E2,&F2,&G2,&H2,&I2,&E1,&E3,&F1,&F3},
        {&D1,&D2,&D3,&D4,&D5,&D6,&D7,&D8,&D9},
        {&A2,&B2,&C2,&D2,&E2,&F2,&G2,&H2,&I2},
        {&D1,&E1,&F1,&D2,&E2,&F2,&D3,&E3,&F3}
    };

    D3 =
    {"D3",{1,2,3,4,5,6,7,8,9},0,false,
        {&D1,&D2,&D4,&D5,&D6,&D7,&D8,&D9,&A3,&B3,
        &C3,&E3,&F3,&G3,&H3,&I3,&E1,&E2,&F1,&F2},
        {&D1,&D2,&D3,&D4,&D5,&D6,&D7,&D8,&D9},
        {&A3,&B3,&C3,&D3,&E3,&F3,&G3,&H3,&I3},
        {&D1,&E1,&F1,&D2,&E2,&F2,&D3,&E3,&F3}
    };

    D4 =
    {"D4",{1,2,3,4,5,6,7,8,9},0,false,
        {&D1,&D2,&D3,&D5,&D6,&D7,&D8,&D9,&A4,&B4,
        &C4,&E4,&F4,&G4,&H4,&I4,&E5,&E6,&F5,&F6},
        {&D1,&D2,&D3,&D4,&D5,&D6,&D7,&D8,&D9},
        {&A4,&B4,&C4,&D4,&E4,&F4,&G4,&H4,&I4},
        {&D4,&E4,&F4,&D5,&E5,&F5,&D6,&E6,&F6}
    };

    D5 =
    {"D5",{1,2,3,4,5,6,7,8,9},0,false,
        {&D1,&D2,&D3,&D4,&D6,&D7,&D8,&D9,&A5,&B5,
        &C5,&E5,&F5,&G5,&H5,&I5,&E4,&E6,&F4,&F6},
        {&D1,&D2,&D3,&D4,&D5,&D6,&D7,&D8,&D9},
        {&A5,&B5,&C5,&D5,&E5,&F5,&G5,&H5,&I5},
        {&D4,&E4,&F4,&D5,&E5,&F5,&D6,&E6,&F6}
    };

    D6 =
    {"D6",{1,2,3,4,5,6,7,8,9},0,false,
        {&D1,&D2,&D3,&D4,&D5,&D7,&D8,&D9,&A6,&B6,
        &C6,&E6,&F6,&G6,&H6,&I6,&E4,&E5,&F4,&F5},
        {&D1,&D2,&D3,&D4,&D5,&D6,&D7,&D8,&D9},
        {&A6,&B6,&C6,&D6,&E6,&F6,&G6,&H6,&I6},
        {&D4,&E4,&F4,&D5,&E5,&F5,&D6,&E6,&F6}
    };

    D7 =
    {"D7",{1,2,3,4,5,6,7,8,9},0,false,
        {&D1,&D2,&D3,&D4,&D5,&D6,&D8,&D9,&A7,&B7,
        &C7,&E7,&F7,&G7,&H7,&I7,&E8,&E9,&F8,&F9},
        {&D1,&D2,&D3,&D4,&D5,&D6,&D7,&D8,&D9},
        {&A7,&B7,&C7,&D7,&E7,&F7,&G7,&H7,&I7},
        {&D7,&E7,&F7,&D8,&E8,&F8,&D9,&E9,&F9}
    };

    D8 =
    {"D8",{1,2,3,4,5,6,7,8,9},0,false,
        {&D1,&D2,&D3,&D4,&D5,&D6,&D7,&D9,&A8,&B8,
        &C8,&E8,&F8,&G8,&H8,&I8,&E7,&E9,&F7,&F9},
        {&D1,&D2,&D3,&D4,&D5,&D6,&D7,&D8,&D9},
        {&A8,&B8,&C8,&D8,&E8,&F8,&G8,&H8,&I8},
        {&D7,&E7,&F7,&D8,&E8,&F8,&D9,&E9,&F9}
    };

    D9 =
    {"D9",{1,2,3,4,5,6,7,8,9},0,false,
        {&D1,&D2,&D3,&D4,&D5,&D6,&D7,&D8,&A9,&B9,
        &C9,&E9,&F9,&G9,&H9,&I9,&E7,&E8,&F7,&F8},
        {&D1,&D2,&D3,&D4,&D5,&D6,&D7,&D8,&D9},
        {&A9,&B9,&C9,&D9,&E9,&F9,&G9,&H9,&I9},
        {&D7,&E7,&F7,&D8,&E8,&F8,&D9,&E9,&F9}
    };

    E1 =
    {"E1",{1,2,3,4,5,6,7,8,9},0,false,
        {&E2,&E3,&E4,&E5,&E6,&E7,&E8,&E9,&A1,&B1,
        &C1,&D1,&F1,&G1,&H1,&I1,&D2,&D3,&F2,&F3},
        {&E1,&E2,&E3,&E4,&E5,&E6,&E7,&E8,&E9},
        {&A1,&B1,&C1,&D1,&E1,&F1,&G1,&H1,&I1},
        {&D1,&E1,&F1,&D2,&E2,&F2,&D3,&E3,&F3}
    };

    E2 =
    {"E2",{1,2,3,4,5,6,7,8,9},0,false,
        {&E1,&E3,&E4,&E5,&E6,&E7,&E8,&E9,&A2,&B2,
        &C2,&D2,&F2,&G2,&H2,&I2,&D1,&D3,&F1,&F3},
        {&E1,&E2,&E3,&E4,&E5,&E6,&E7,&E8,&E9},
        {&A2,&B2,&C2,&D2,&E2,&F2,&G2,&H2,&I2},
        {&D1,&E1,&F1,&D2,&E2,&F2,&D3,&E3,&F3}
    };

    E3 =
    {"E3",{1,2,3,4,5,6,7,8,9},0,false,
        {&E1,&E2,&E4,&E5,&E6,&E7,&E8,&E9,&A3,&B3,
        &C3,&D3,&F3,&G3,&H3,&I3,&D1,&D2,&F1,&F2},
        {&E1,&E2,&E3,&E4,&E5,&E6,&E7,&E8,&E9},
        {&A3,&B3,&C3,&D3,&E3,&F3,&G3,&H3,&I3},
        {&D1,&E1,&F1,&D2,&E2,&F2,&D3,&E3,&F3}
    };

    E4 =
    {"E4",{1,2,3,4,5,6,7,8,9},0,false,
        {&E1,&E2,&E3,&E5,&E6,&E7,&E8,&E9,&A4,&B4,
        &C4,&D4,&F4,&G4,&H4,&I4,&D5,&D6,&F5,&F6},
        {&E1,&E2,&E3,&E4,&E5,&E6,&E7,&E8,&E9},
        {&A4,&B4,&C4,&D4,&E4,&F4,&G4,&H4,&I4},
        {&D4,&E4,&F4,&D5,&E5,&F5,&D6,&E6,&F6}
    };

    E5 =
    {"E5",{1,2,3,4,5,6,7,8,9},0,false,
        {&E1,&E2,&E3,&E4,&E6,&E7,&E8,&E9,&A5,&B5,
        &C5,&D5,&F5,&G5,&H5,&I5,&D4,&D6,&F4,&F6},
        {&E1,&E2,&E3,&E4,&E5,&E6,&E7,&E8,&E9},
        {&A5,&B5,&C5,&D5,&E5,&F5,&G5,&H5,&I5},
        {&D4,&E4,&F4,&D5,&E5,&F5,&D6,&E6,&F6}
    };

    E6 =
    {"E6",{1,2,3,4,5,6,7,8,9},0,false,
        {&E1,&E2,&E3,&E4,&E5,&E7,&E8,&E9,&A6,&B6,
        &C6,&D6,&F6,&G6,&H6,&I6,&D4,&D5,&F4,&F5},
        {&E1,&E2,&E3,&E4,&E5,&E6,&E7,&E8,&E9},
        {&A6,&B6,&C6,&D6,&E6,&F6,&G6,&H6,&I6},
        {&D4,&E4,&F4,&D5,&E5,&F5,&D6,&E6,&F6}
    };

    E7 =
    {"E7",{1,2,3,4,5,6,7,8,9},0,false,
        {&E1,&E2,&E3,&E4,&E5,&E6,&E8,&E9,&A7,&B7,
        &C7,&D7,&F7,&G7,&H7,&I7,&D8,&D9,&F8,&F9},
        {&E1,&E2,&E3,&E4,&E5,&E6,&E7,&E8,&E9},
        {&A7,&B7,&C7,&D7,&E7,&F7,&G7,&H7,&I7},
        {&D7,&E7,&F7,&D8,&E8,&F8,&D9,&E9,&F9}
    };

    E8 =
    {"E8",{1,2,3,4,5,6,7,8,9},0,false,
        {&E1,&E2,&E3,&E4,&E5,&E6,&E7,&E9,&A8,&B8,
        &C8,&D8,&F8,&G8,&H8,&I8,&D7,&D9,&F7,&F9},
        {&E1,&E2,&E3,&E4,&E5,&E6,&E7,&E8,&E9},
        {&A8,&B8,&C8,&D8,&E8,&F8,&G8,&H8,&I8},
        {&D7,&E7,&F7,&D8,&E8,&F8,&D9,&E9,&F9}
    };

    E9 =
    {"E9",{1,2,3,4,5,6,7,8,9},0,false,
        {&E1,&E2,&E3,&E4,&E5,&E6,&E7,&E8,&A9,&B9,
        &C9,&D9,&F9,&G9,&H9,&I9,&D7,&D8,&F7,&F8},
        {&E1,&E2,&E3,&E4,&E5,&E6,&E7,&E8,&E9},
        {&A9,&B9,&C9,&D9,&E9,&F9,&G9,&H9,&I9},
        {&D7,&E7,&F7,&D8,&E8,&F8,&D9,&E9,&F9}
    };

    F1 =
    {"F1",{1,2,3,4,5,6,7,8,9},0,false,
        {&F2,&F3,&F4,&F5,&F6,&F7,&F8,&F9,&A1,&B1,
        &C1,&D1,&E1,&G1,&H1,&I1,&D2,&D3,&E2,&E3},
        {&F1,&F2,&F3,&F4,&F5,&F6,&F7,&F8,&F9},
        {&A1,&B1,&C1,&D1,&E1,&F1,&G1,&H1,&I1},
        {&D1,&E1,&F1,&D2,&E2,&F2,&D3,&E3,&F3}
    };

    F2 =
    {"F2",{1,2,3,4,5,6,7,8,9},0,false,
        {&F1,&F3,&F4,&F5,&F6,&F7,&F8,&F9,&A2,&B2,
        &C2,&D2,&E2,&G2,&H2,&I2,&D1,&D3,&E1,&E3},
        {&F1,&F2,&F3,&F4,&F5,&F6,&F7,&F8,&F9},
        {&A2,&B2,&C2,&D2,&E2,&F2,&G2,&H2,&I2},
        {&D1,&E1,&F1,&D2,&E2,&F2,&D3,&E3,&F3}
    };

    F3 =
    {"F3",{1,2,3,4,5,6,7,8,9},0,false,
        {&F1,&F2,&F4,&F5,&F6,&F7,&F8,&F9,&A3,&B3,
        &C3,&D3,&E3,&G3,&H3,&I3,&D1,&D2,&E1,&E2},
        {&F1,&F2,&F3,&F4,&F5,&F6,&F7,&F8,&F9},
        {&A3,&B3,&C3,&D3,&E3,&F3,&G3,&H3,&I3},
        {&D1,&E1,&F1,&D2,&E2,&F2,&D3,&E3,&F3}
    };

    F4 =
    {"F4",{1,2,3,4,5,6,7,8,9},0,false,
        {&F1,&F2,&F3,&F5,&F6,&F7,&F8,&F9,&A4,&B4,
        &C4,&D4,&E4,&G4,&H4,&I4,&D5,&D6,&E5,&E6},
        {&F1,&F2,&F3,&F4,&F5,&F6,&F7,&F8,&F9},
        {&A4,&B4,&C4,&D4,&E4,&F4,&G4,&H4,&I4},
        {&D4,&E4,&F4,&D5,&E5,&F5,&D6,&E6,&F6}
    };

    F5 =
    {"F5",{1,2,3,4,5,6,7,8,9},0,false,
        {&F1,&F2,&F3,&F4,&F6,&F7,&F8,&F9,&A5,&B5,
        &C5,&D5,&E5,&G5,&H5,&I5,&D4,&D6,&E4,&E6},
        {&F1,&F2,&F3,&F4,&F5,&F6,&F7,&F8,&F9},
        {&A5,&B5,&C5,&D5,&E5,&F5,&G5,&H5,&I5},
        {&D4,&E4,&F4,&D5,&E5,&F5,&D6,&E6,&F6}
    };

    F6 =
    {"F6",{1,2,3,4,5,6,7,8,9},0,false,
        {&F1,&F2,&F3,&F4,&F5,&F7,&F8,&F9,&A6,&B6,
        &C6,&D6,&E6,&G6,&H6,&I6,&D4,&D5,&E4,&E5},
        {&F1,&F2,&F3,&F4,&F5,&F6,&F7,&F8,&F9},
        {&A6,&B6,&C6,&D6,&E6,&F6,&G6,&H6,&I6},
        {&D4,&E4,&F4,&D5,&E5,&F5,&D6,&E6,&F6}
    };

    F7 =
    {"F7",{1,2,3,4,5,6,7,8,9},0,false,
        {&F1,&F2,&F3,&F4,&F5,&F6,&F8,&F9,&A7,&B7,
        &C7,&D7,&E7,&G7,&H7,&I7,&D8,&D9,&E8,&E9},
        {&F1,&F2,&F3,&F4,&F5,&F6,&F7,&F8,&F9},
        {&A7,&B7,&C7,&D7,&E7,&F7,&G7,&H7,&I7},
        {&D7,&E7,&F7,&D8,&E8,&F8,&D9,&E9,&F9}
    };

    F8 =
    {"F8",{1,2,3,4,5,6,7,8,9},0,false,
        {&F1,&F2,&F3,&F4,&F5,&F6,&F7,&F9,&A8,&B8,
        &C8,&D8,&E8,&G8,&H8,&I8,&D7,&D9,&E7,&E9},
        {&F1,&F2,&F3,&F4,&F5,&F6,&F7,&F8,&F9},
        {&A8,&B8,&C8,&D8,&E8,&F8,&G8,&H8,&I8},
        {&D7,&E7,&F7,&D8,&E8,&F8,&D9,&E9,&F9}
    };

    F9 =
    {"F9",{1,2,3,4,5,6,7,8,9},0,false,
        {&F1,&F2,&F3,&F4,&F5,&F6,&F7,&F8,&A9,&B9,
        &C9,&D9,&E9,&G9,&H9,&I9,&D7,&D8,&E7,&E8},
        {&F1,&F2,&F3,&F4,&F5,&F6,&F7,&F8,&F9},
        {&A9,&B9,&C9,&D9,&E9,&F9,&G9,&H9,&I9},
        {&D7,&E7,&F7,&D8,&E8,&F8,&D9,&E9,&F9}
    };

    G1 =
    {"G1",{1,2,3,4,5,6,7,8,9},0,false,
        {&G2,&G3,&G4,&G5,&G6,&G7,&G8,&G9,&A1,&B1,
        &C1,&D1,&E1,&F1,&H1,&I1,&H2,&H3,&I2,&I3},
        {&G1,&G2,&G3,&G4,&G5,&G6,&G7,&G8,&G9},
        {&A1,&B1,&C1,&D1,&E1,&F1,&G1,&H1,&I1},
        {&G1,&H1,&I1,&G2,&H2,&I2,&G3,&H3,&I3}
    };

    G2 =
    {"G2",{1,2,3,4,5,6,7,8,9},0,false,
        {&G1,&G3,&G4,&G5,&G6,&G7,&G8,&G9,&A2,&B2,
        &C2,&D2,&E2,&F2,&H2,&I2,&H1,&H3,&I1,&I3},
        {&G1,&G2,&G3,&G4,&G5,&G6,&G7,&G8,&G9},
        {&A2,&B2,&C2,&D2,&E2,&F2,&G2,&H2,&I2},
        {&G1,&H1,&I1,&G2,&H2,&I2,&G3,&H3,&I3}
    };

    G3 =
    {"G3",{1,2,3,4,5,6,7,8,9},0,false,
        {&G1,&G2,&G4,&G5,&G6,&G7,&G8,&G9,&A3,&B3,
        &C3,&D3,&E3,&F3,&H3,&I3,&H1,&H2,&I1,&I2},
        {&G1,&G2,&G3,&G4,&G5,&G6,&G7,&G8,&G9},
        {&A3,&B3,&C3,&D3,&E3,&F3,&G3,&H3,&I3},
        {&G1,&H1,&I1,&G2,&H2,&I2,&G3,&H3,&I3}
    };

    G4 =
    {"G4",{1,2,3,4,5,6,7,8,9},0,false,
        {&G1,&G2,&G3,&G5,&G6,&G7,&G8,&G9,&A4,&B4,
        &C4,&D4,&E4,&F4,&H4,&I4,&H5,&H6,&I5,&I6},
        {&G1,&G2,&G3,&G4,&G5,&G6,&G7,&G8,&G9},
        {&A4,&B4,&C4,&D4,&E4,&F4,&G4,&H4,&I4},
        {&G4,&H4,&I4,&G5,&H5,&I5,&G6,&H6,&I6}
    };

    G5 =
    {"G5",{1,2,3,4,5,6,7,8,9},0,false,
        {&G1,&G2,&G3,&G4,&G6,&G7,&G8,&G9,&A5,&B5,
        &C5,&D5,&E5,&F5,&H5,&I5,&H4,&H6,&I4,&I6},
        {&G1,&G2,&G3,&G4,&G5,&G6,&G7,&G8,&G9},
        {&A5,&B5,&C5,&D5,&E5,&F5,&G5,&H5,&I5},
        {&G4,&H4,&I4,&G5,&H5,&I5,&G6,&H6,&I6}
    };

    G6 =
    {"G6",{1,2,3,4,5,6,7,8,9},0,false,
        {&G1,&G2,&G3,&G4,&G5,&G7,&G8,&G9,&A6,&B6,
        &C6,&D6,&E6,&F6,&H6,&I6,&H4,&H5,&I4,&I5},
        {&G1,&G2,&G3,&G4,&G5,&G6,&G7,&G8,&G9},
        {&A6,&B6,&C6,&D6,&E6,&F6,&G6,&H6,&I6},
        {&G4,&H4,&I4,&G5,&H5,&I5,&G6,&H6,&I6}
    };

    G7 =
    {"G7",{1,2,3,4,5,6,7,8,9},0,false,
        {&G1,&G2,&G3,&G4,&G5,&G6,&G8,&G9,&A7,&B7,
        &C7,&D7,&E7,&F7,&H7,&I7,&H8,&H9,&I8,&I9},
        {&G1,&G2,&G3,&G4,&G5,&G6,&G7,&G8,&G9},
        {&A7,&B7,&C7,&D7,&E7,&F7,&G7,&H7,&I7},
        {&G7,&H7,&I7,&G8,&H8,&I8,&G9,&H9,&I9}
    };

    G8 =
    {"G8",{1,2,3,4,5,6,7,8,9},0,false,
        {&G1,&G2,&G3,&G4,&G5,&G6,&G7,&G9,&A8,&B8,
        &C8,&D8,&E8,&F8,&H8,&I8,&H7,&H9,&I7,&I9},
        {&G1,&G2,&G3,&G4,&G5,&G6,&G7,&G8,&G9},
        {&A8,&B8,&C8,&D8,&E8,&F8,&G8,&H8,&I8},
        {&G7,&H7,&I7,&G8,&H8,&I8,&G9,&H9,&I9}
    };

    G9 =
    {"G9",{1,2,3,4,5,6,7,8,9},0,false,
        {&G1,&G2,&G3,&G4,&G5,&G6,&G7,&G8,&A9,&B9,
        &C9,&D9,&E9,&F9,&H9,&I9,&H7,&H8,&I7,&I8},
        {&G1,&G2,&G3,&G4,&G5,&G6,&G7,&G8,&G9},
        {&A9,&B9,&C9,&D9,&E9,&F9,&G9,&H9,&I9},
        {&G7,&H7,&I7,&G8,&H8,&I8,&G9,&H9,&I9}
    };

    H1 =
    {"H1",{1,2,3,4,5,6,7,8,9},0,false,
        {&H2,&H3,&H4,&H5,&H6,&H7,&H8,&H9,&A1,&B1,
        &C1,&D1,&E1,&F1,&G1,&I1,&G2,&G3,&I2,&I3},
        {&H1,&H2,&H3,&H4,&H5,&H6,&H7,&H8,&H9},
        {&A1,&B1,&C1,&D1,&E1,&F1,&G1,&H1,&I1},
        {&G1,&H1,&I1,&G2,&H2,&I2,&G3,&H3,&I3}
    };

    H2 =
    {"H2",{1,2,3,4,5,6,7,8,9},0,false,
        {&H1,&H3,&H4,&H5,&H6,&H7,&H8,&H9,&A2,&B2,
        &C2,&D2,&E2,&F2,&G2,&I2,&G1,&G3,&I1,&I3},
        {&H1,&H2,&H3,&H4,&H5,&H6,&H7,&H8,&H9},
        {&A2,&B2,&C2,&D2,&E2,&F2,&G2,&H2,&I2},
        {&G1,&H1,&I1,&G2,&H2,&I2,&G3,&H3,&I3}
    };

    H3 =
    {"H3",{1,2,3,4,5,6,7,8,9},0,false,
        {&H1,&H2,&H4,&H5,&H6,&H7,&H8,&H9,&A3,&B3,
        &C3,&D3,&E3,&F3,&G3,&I3,&G1,&G2,&I1,&I2},
        {&H1,&H2,&H3,&H4,&H5,&H6,&H7,&H8,&H9},
        {&A3,&B3,&C3,&D3,&E3,&F3,&G3,&H3,&I3},
        {&G1,&H1,&I1,&G2,&H2,&I2,&G3,&H3,&I3}
    };

    H4 =
    {"H4",{1,2,3,4,5,6,7,8,9},0,false,
        {&H1,&H2,&H3,&H5,&H6,&H7,&H8,&H9,&A4,&B4,
        &C4,&D4,&E4,&F4,&G4,&I4,&G5,&G6,&I5,&I6},
        {&H1,&H2,&H3,&H4,&H5,&H6,&H7,&H8,&H9},
        {&A4,&B4,&C4,&D4,&E4,&F4,&G4,&H4,&I4},
        {&G4,&H4,&I4,&G5,&H5,&I5,&G6,&H6,&I6}
    };

    H5 =
    {"H5",{1,2,3,4,5,6,7,8,9},0,false,
        {&H1,&H2,&H3,&H4,&H6,&H7,&H8,&H9,&A5,&B5,
        &C5,&D5,&E5,&F5,&G5,&I5,&G4,&G6,&I4,&I6},
        {&H1,&H2,&H3,&H4,&H5,&H6,&H7,&H8,&H9},
        {&A5,&B5,&C5,&D5,&E5,&F5,&G5,&H5,&I5},
        {&G4,&H4,&I4,&G5,&H5,&I5,&G6,&H6,&I6}
    };

    H6 =
    {"H6",{1,2,3,4,5,6,7,8,9},0,false,
        {&H1,&H2,&H3,&H4,&H5,&H7,&H8,&H9,&A6,&B6,
        &C6,&D6,&E6,&F6,&G6,&I6,&G4,&G5,&I4,&I5},
        {&H1,&H2,&H3,&H4,&H5,&H6,&H7,&H8,&H9},
        {&A6,&B6,&C6,&D6,&E6,&F6,&G6,&H6,&I6},
        {&G4,&H4,&I4,&G5,&H5,&I5,&G6,&H6,&I6}
    };

    H7 =
    {"H7",{1,2,3,4,5,6,7,8,9},0,false,
        {&H1,&H2,&H3,&H4,&H5,&H6,&H8,&H9,&A7,&B7,
        &C7,&D7,&E7,&F7,&G7,&I7,&G8,&G9,&I8,&I9},
        {&H1,&H2,&H3,&H4,&H5,&H6,&H7,&H8,&H9},
        {&A7,&B7,&C7,&D7,&E7,&F7,&G7,&H7,&I7},
        {&G7,&H7,&I7,&G8,&H8,&I8,&G9,&H9,&I9}
    };

    H8 =
    {"H8",{1,2,3,4,5,6,7,8,9},0,false,
        {&H1,&H2,&H3,&H4,&H5,&H6,&H7,&H9,&A8,&B8,
        &C8,&D8,&E8,&F8,&G8,&I8,&G7,&G9,&I7,&I9},
        {&H1,&H2,&H3,&H4,&H5,&H6,&H7,&H8,&H9},
        {&A8,&B8,&C8,&D8,&E8,&F8,&G8,&H8,&I8},
        {&G7,&H7,&I7,&G8,&H8,&I8,&G9,&H9,&I9}
    };

    H9 =
    {"H9",{1,2,3,4,5,6,7,8,9},0,false,
        {&H1,&H2,&H3,&H4,&H5,&H6,&H7,&H8,&A9,&B9,
        &C9,&D9,&E9,&F9,&G9,&I9,&G7,&G8,&I7,&I8},
        {&H1,&H2,&H3,&H4,&H5,&H6,&H7,&H8,&H9},
        {&A9,&B9,&C9,&D9,&E9,&F9,&G9,&H9,&I9},
        {&G7,&H7,&I7,&G8,&H8,&I8,&G9,&H9,&I9}
    };

    I1 =
    {"I1",{1,2,3,4,5,6,7,8,9},0,false,
        {&I2,&I3,&I4,&I5,&I6,&I7,&I8,&I9,&A1,&B1,
        &C1,&D1,&E1,&F1,&G1,&H1,&G2,&G3,&H2,&H3},
        {&I1,&I2,&I3,&I4,&I5,&I6,&I7,&I8,&I9},
        {&A1,&B1,&C1,&D1,&E1,&F1,&G1,&H1,&I1},
        {&G1,&H1,&I1,&G2,&H2,&I2,&G3,&H3,&I3}
    };

    I2 =
    {"I2",{1,2,3,4,5,6,7,8,9},0,false,
        {&I1,&I3,&I4,&I5,&I6,&I7,&I8,&I9,&A2,&B2,
        &C2,&D2,&E2,&F2,&G2,&H2,&G1,&G3,&H1,&H3},
        {&I1,&I2,&I3,&I4,&I5,&I6,&I7,&I8,&I9},
        {&A2,&B2,&C2,&D2,&E2,&F2,&G2,&H2,&I2},
        {&G1,&H1,&I1,&G2,&H2,&I2,&G3,&H3,&I3}
    };

    I3 =
    {"I3",{1,2,3,4,5,6,7,8,9},0,false,
        {&I1,&I2,&I4,&I5,&I6,&I7,&I8,&I9,&A3,&B3,
        &C3,&D3,&E3,&F3,&G3,&H3,&G1,&G2,&H1,&H2},
        {&I1,&I2,&I3,&I4,&I5,&I6,&I7,&I8,&I9},
        {&A3,&B3,&C3,&D3,&E3,&F3,&G3,&H3,&I3},
        {&G1,&H1,&I1,&G2,&H2,&I2,&G3,&H3,&I3}
    };

    I4 =
    {"I4",{1,2,3,4,5,6,7,8,9},0,false,
        {&I1,&I2,&I3,&I5,&I6,&I7,&I8,&I9,&A4,&B4,
        &C4,&D4,&E4,&F4,&G4,&H4,&G5,&G6,&H5,&H6},
        {&I1,&I2,&I3,&I4,&I5,&I6,&I7,&I8,&I9},
        {&A4,&B4,&C4,&D4,&E4,&F4,&G4,&H4,&I4},
        {&G4,&H4,&I4,&G5,&H5,&I5,&G6,&H6,&I6}
    };

    I5 =
    {"I5",{1,2,3,4,5,6,7,8,9},0,false,
        {&I1,&I2,&I3,&I4,&I6,&I7,&I8,&I9,&A5,&B5,
        &C5,&D5,&E5,&F5,&G5,&H5,&G4,&G6,&H4,&H6},
        {&I1,&I2,&I3,&I4,&I5,&I6,&I7,&I8,&I9},
        {&A5,&B5,&C5,&D5,&E5,&F5,&G5,&H5,&I5},
        {&G4,&H4,&I4,&G5,&H5,&I5,&G6,&H6,&I6}
    };

    I6 =
    {"I6",{1,2,3,4,5,6,7,8,9},0,false,
        {&I1,&I2,&I3,&I4,&I5,&I7,&I8,&I9,&A6,&B6,
        &C6,&D6,&E6,&F6,&G6,&H6,&G4,&G5,&H4,&H5},
        {&I1,&I2,&I3,&I4,&I5,&I6,&I7,&I8,&I9},
        {&A6,&B6,&C6,&D6,&E6,&F6,&G6,&H6,&I6},
        {&G4,&H4,&I4,&G5,&H5,&I5,&G6,&H6,&I6}
    };

    I7 =
    {"I7",{1,2,3,4,5,6,7,8,9},0,false,
        {&I1,&I2,&I3,&I4,&I5,&I6,&I8,&I9,&A7,&B7,
        &C7,&D7,&E7,&F7,&G7,&H7,&G8,&G9,&H8,&H9},
        {&I1,&I2,&I3,&I4,&I5,&I6,&I7,&I8,&I9},
        {&A7,&B7,&C7,&D7,&E7,&F7,&G7,&H7,&I7},
        {&G7,&H7,&I7,&G8,&H8,&I8,&G9,&H9,&I9}
    };

    I8 =
    {"I8",{1,2,3,4,5,6,7,8,9},0,false,
        {&I1,&I2,&I3,&I4,&I5,&I6,&I7,&I9,&A8,&B8,
        &C8,&D8,&E8,&F8,&G8,&H8,&G7,&G9,&H7,&H9},
        {&I1,&I2,&I3,&I4,&I5,&I6,&I7,&I8,&I9},
        {&A8,&B8,&C8,&D8,&E8,&F8,&G8,&H8,&I8},
        {&G7,&H7,&I7,&G8,&H8,&I8,&G9,&H9,&I9}
    };

    I9 =
    {"I9",{1,2,3,4,5,6,7,8,9},0,false,
        {&I1,&I2,&I3,&I4,&I5,&I6,&I7,&I8,&A9,&B9,
        &C9,&D9,&E9,&F9,&G9,&H9,&G7,&G8,&H7,&H8},
        {&A1,&A2,&A3,&A4,&A5,&A6,&A7,&A8,&A9},
        {&A9,&B9,&C9,&D9,&E9,&F9,&G9,&H9,&I9},
        {&G7,&H7,&I7,&G8,&H8,&I8,&G9,&H9,&I9}
    };

    InitilizeSudokuSquareMatrix();
    TraverseSquareMatrixUnits();
}

SudokuGrid::~SudokuGrid()
//=======================
{
    // std::cout << "\nIn the destructor of class SudokuGrid!" << std::endl << std::endl;

    if (SudokuGridSolved()){
        std::cout << "\nThe SudokuGrid solved!!!";
    }else
    {
        std::cout << "\nThe SudokuGrid NOT solved...";
    }

    std::cout << "\n\nLayout of the SudokuGrid:\n";
    std::cout << "=========================\n";
    PrintsquareMatrixValues();

    std::cout << std::endl;

    std::cout << "Layout of (Possible Remaining Guesses) for the SudokuGrid:\n";
    std::cout << "==========================================================\n";
    PrintsquareMatrixHypos();
}

void SudokuGrid::ReadSudokuFile(std::string filename)
//===================================================
{
    int row, column = 0;
    int charcount = 0;
    std::string line = "";
    std::ifstream myFile;
    int checkLinePos = 0;

    myFile.open(filename);

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

void SudokuGrid::SetInitialSquareValue(squareptr_t square, int value)
//===================================================================
{
    square->value = value;
    square->possiblevalues.clear();
    square->possiblevalues.push_back(square->value);
    square->analysefinalized = true;

    for (size_t peernr = 0; peernr < NrOfPeers; peernr++)
    {
        square->peers[peernr]->possiblevalues.erase(
            std::remove(square->peers[peernr]->possiblevalues.begin(),
                        square->peers[peernr]->possiblevalues.end(),
                        square->value),
                        square->peers[peernr]->possiblevalues.end());   
    }
}

void SudokuGrid::InitilizeSquareUnits(squareptr_t square)
//========================================================
{

    for (size_t i = 0; i < 9; i++)
    {
        if (square->unit1_row[i]->possiblevalues.size() == 1)
        {
            SetSquareValue(square->unit1_row[i],*square->unit1_row[i]->possiblevalues.begin());
        }
    }

    for (size_t i = 0; i < 9; i++)
    {
        if (square->unit2_colum[i]->possiblevalues.size() == 1)
        {
            SetSquareValue(square->unit2_colum[i],*square->unit2_colum[i]->possiblevalues.begin());
        }
    }

    for (size_t i = 0; i < 9; i++)
   {
       if (square->unit3_box[i]->possiblevalues.size() == 1)
       {
           SetSquareValue(square->unit3_box[i],*square->unit3_box[i]->possiblevalues.begin());
       }
   }
}

void SudokuGrid::SetSquareValue(squareptr_t square, int value)
//============================================================
{
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
            if (square->peers[peernr]->analysefinalized != true)
            {
                square->peers[peernr]->possiblevalues.erase(
                    std::remove(square->peers[peernr]->possiblevalues.begin(),
                                square->peers[peernr]->possiblevalues.end(),
                                square->value),
                    square->peers[peernr]->possiblevalues.end());
            }
        }
    }

    /*
    std::cout << "\nCurrent layout of SquareMatrix:\n(Working values towards solution of SudokuGrid)\n";
    std::cout << "========================================\n";
    PrintsquareMatrixValues();

    std::cout << std::endl;

    std::cout << "Current layout of SquareMatrix:\n(Working possiblevalues towards solution of SudokuGrid)\n";
    std::cout << "========================================\n";
    PrintsquareMatrixHypos();
    */
}

void SudokuGrid::TraverseSquareMatrixUnits()
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
            // std::cout << "Id: " << unit[i]->ID << "\n";
        }
    }

    for (auto i = Temp1Vec.cbegin(); i < Temp1Vec.cend(); i++)
    {
        if (std::count(Temp1Vec.begin(), Temp1Vec.end(), *i)== 1)
        {
            Tmp2Vec.push_back(*i);
        }
    }

    // std::cout << "\nContent of concatenated possible row values for IDs : \n";
    // for (auto i = Temp1Vec.cbegin(); i < Temp1Vec.cend(); i++)
    // {
    //     std::cout << *i << " ";
    // }

    // std::cout << "\nContent of traversed concatenated possible row values for IDs : \n";
    for (auto i = Tmp2Vec.cbegin(); i < Tmp2Vec.cend(); i++)
    {
        // std::cout << *i << " ";

        for (size_t j = 0; j < 9; j++)
        {
            if (std::count(unit[j]->possiblevalues.begin(),
                           unit[j]->possiblevalues.end(), *i) == 1)
            {
                SetSquareValue(unit[j], *i);
            }
        }
    }

    // std::cout << "\n";
    // std:: cin >> dummy;
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
            std::cout << "\t ";
        }
        std::cout << "\n";

        if (row == 2 || row == 5)
        {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

