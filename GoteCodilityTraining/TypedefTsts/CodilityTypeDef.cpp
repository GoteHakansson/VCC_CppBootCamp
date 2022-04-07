#ifndef BLIPP
#define BLIPP

#include <cstdlib>
#include <iostream>
#include <map>

using namespace std;

typedef map<string, int> ScoreByName;
struct GoteRecord_t
{
    int first = 0;
    int second[3] = {2, 4, 5};
    char third[5] = {'a', 'b', 'c', 'd', '\0'};
    char forth[6] = "blipp";
    string fith = "sss";
};

GoteRecord_t* function1(string str)
{
    GoteRecord_t* Gotefunc = new GoteRecord_t;
    Gotefunc->fith = str;
    Gotefunc->second[0] = 8;
    return Gotefunc;
};

int main()
{
    GoteRecord_t GoteRecord;
    GoteRecord_t* GoteRecord2;
    char tmpchar = ' ';
    int tmpint = 0;
    ScoreByName GolfRound1;

    GolfRound1["Lisa"]  = 56;
    GolfRound1["Pia"]   = 81;
    GolfRound1["Tora"]  = 93;

    cout << GoteRecord.fith << std::endl;
    cout << GoteRecord.third << std::endl;

    for (size_t i = 0; i < 6; i++)
    {
        std::cout << "String content (third): " << GoteRecord.third[i] << std::endl;
    }
    
    size_t i = 0;

    for (map<string,int>::iterator i = GolfRound1.begin();(i != GolfRound1.end());i++)
    {
        cout << i->first << " " << i->second << endl;
    }
    

    tmpchar = GoteRecord.third[i];

    while (tmpchar != '\0')
    {
        i++;
        tmpchar = GoteRecord.third[i];
    }

    cout << "Size of char array GoteRecord.third: " << i << endl;

    GoteRecord2 = function1("jhhhd");
    delete GoteRecord2;

    cout << "String GoteRecord2.fith: " << GoteRecord2->fith << endl;
    cin >> tmpint;
};

#endif //BLIPP
