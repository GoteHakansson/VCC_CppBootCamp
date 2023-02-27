#include <iostream>
#include <vector>
using namespace std;

int solution(vector<string> &R)
{
   int NrofRows = R.size();
   int NrofCleanSpots = 0;
   string Column = "";
   
   for (int i = 0; i < NrofRows; i++)
   {
       Column = R[i];
       for (int j = 0; j < Column.size(); i++)
       {

           if (Column[j]=='.')
           {
               NrofCleanSpots++;
           } else if (Column[j]=='X'){
               break;
           }
           
       }
   }
   
   return NrofCleanSpots;
};

int main()

{
    vector<string> A {{"...."},{"...."},{"...."}};
    cout << solution(A) << endl;
}