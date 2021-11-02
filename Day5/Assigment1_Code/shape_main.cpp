#include <iostream>
#include "shape.hpp"

int main()
{
    rectangle rect1(4,5), rect2(5,5), rect3(5,5);
    triangle tria1(7, 9),tria2(8,0);
    circle circ1(3, 5), circ2(3,10);

    std::cout << "rect1 > rect2 (Should be false(0)): " << int(rect1 > rect2) << std::endl;
    std::cout << "rect1 < rect2 (Should be true(1)): " << int(rect1 < rect2) << std::endl;
    std::cout << "rect2 == rect3 (Should be true(1)): " << int(rect2 == rect3) << std::endl;

    std::cout << "tria1 > rect1 (Should be true(1)): " << int(tria1 > rect1) << std::endl;
    std::cout << "tria1== rect1 (Should be false(0)): " << int(tria1 == rect1) << std::endl;
    std::cout << "tria1 < rect1 (Should be false(0)): " << int(tria1 < rect1) << std::endl;
    return 0;
}
