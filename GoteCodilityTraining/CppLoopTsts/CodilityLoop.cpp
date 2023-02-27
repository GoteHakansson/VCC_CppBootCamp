#ifndef BLIPP
#define BLIPP

#include <vector>
#include <cstdlib>
#include <iostream>

int ArrayInt[3] = {3,4,5};
std::vector<int> VectorArray = {-5,-4,-3,-2,-1,0,1};

void PrintIntArray (int A[]){
    for (auto i = 0;i<3; i++){
        std::cout << A[i] << ' ';
    }
    std::cout << std::endl;
}

void PrintVectorArray (std::vector<int> v){
    for (auto e = v.cbegin(); e < v.cend(); e++){
        std::cout << *e << ' ';
    }
    std::cout << std::endl;
} 

int main(){
    std::cout << "Blipp" << std::endl;
    PrintIntArray(ArrayInt);
    PrintVectorArray(VectorArray);
    return 0;
}

#endif //BLIPP
