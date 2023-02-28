#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{

    // Added comment
    // Added yet another comment
    //Happens to add another comment here also

    unsigned int posNumber = 0;
    int x = 8, y = 9, z = 11;
    unsigned int array[x][y][z];
    int randomNumber;

    std::srand((unsigned)std::time(0));
    std::cout << "Enter a positive number: ";
    std::cin >> posNumber;

    for (size_t i = 0; i < x; i++){
        for (size_t j = 0; j < y; j++){
            for (size_t k = 0; k < z; k++){
                    randomNumber = (std::rand() % posNumber);
                    array[i][j][k]= randomNumber;
            }
        }
    }
    //Pretty print the result of the assigned 3 dimensional array residing in the dynamic memory.
    for (size_t i = 0; i < x; i++){
        for (size_t j = 0; j < y; j++){
            for (size_t k = 0; k < z; k++){
                std::cout << array[i][j][k] << "\t";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}
