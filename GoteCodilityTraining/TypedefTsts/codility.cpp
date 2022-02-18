#include <cstdlib>
#include <iostream>

int main()
{

    typedef struct GoteRecord_t
    {
        int first = 0;
        int second[3] = {2, 4, 5};
        char third[5] = {'a','b','c','d','\0'};
        char forth[6] = "blipp";
        std::string fith = "sss";
    };

    GoteRecord_t GoteRecord;
    char tmpchar = ' ';
    int tmpint = 0;

    std::cout << GoteRecord.fith << std::endl;
    std::cout << GoteRecord.third << std::endl;

    for (size_t i = 0; i < 6; i++)
    {
        std::cout << "String content (third): " << GoteRecord.third[i] << std::endl;
    }
    size_t i = 0;

    tmpchar = GoteRecord.third[i];

    while (tmpchar != '\0')
    {
        i++;
        tmpchar = GoteRecord.third[i];
    }

    std::cout << "Size of char array GoteRecord.third: " << i << std::endl;
    std::cin >> tmpint;

};
