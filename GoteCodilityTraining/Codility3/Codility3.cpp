
// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

#include <vector>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

char *solution(int A[], int N)
{
    // write your code in C99 (gcc 6.2.0)

    string StrOutput = "";
    char *CharOutput;

    for (size_t i = 0; i < N; i++)
    {
        if (A[i] == 0)
        {
            StrOutput.push_back('=');
        }
        else if (A[i] < 0)
        {
            StrOutput.push_back('<');
        }
        else
        {
            StrOutput.push_back('>');
        }
    }
    CharOutput = new char(StrOutput.size() + 1);
    std::copy(StrOutput.begin(), StrOutput.end(), CharOutput);
    CharOutput[StrOutput.size()] = '\0';

    return CharOutput;
}

int IntArray[] = {1, 4, 0, -1};

int main()
{
    cout << solution(IntArray,4) << endl;
    return 0;
}
