#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{

    unsigned int posNumber = 0;
    //====================
    unsigned int*** array;
    //====================
    int randomNumber;
    int x, y, z;

    std::cout << "Enter the size of the 3 dimesional array (Input-example => 6 7 8): ";
    std::cin >> x >> y >> z;

    std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;

    std::srand((unsigned)std::time(0));
    std::cout << "Enter a positive number: ";
    std::cin >> posNumber;

    //First dimension (x).
    // Create a one dimensional array which contains x number of pointers to arrays of pointers to integegers.
    array = new unsigned int **[x];

    // Loop thru the first dimension array (x) and create the second dimesion array (y).
    // A one dimesional arrays of pointers to integers. 
    for (size_t i = 0; i < x ; i++){
        array[i] = new unsigned int *[y];

        // Loop thru the second dimesion array (y) and create the tird dimensinonal array (z).
        // A one dimensional arrays of pointers to instantiated integers.
        // Assign the instasiated integer a random value lower then the given positive number.
        for (size_t j = 0;j < y; j++){
            array[i][j] = new unsigned int[z];   
            for (int k = 0; k < z; k++){                    
                randomNumber = (std::rand() % posNumber);
                array[i][j][k] = randomNumber;
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
      
    // Return the assigned dynamic memory
    for (size_t i = 0; i < x; i++){
        for (size_t j = 0; j < y; j++){
            delete[] array[i][j];
        }
        delete[] array[i];
    }
    delete[] array;

}