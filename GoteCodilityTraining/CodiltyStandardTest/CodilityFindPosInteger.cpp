// you can use includes, for example:
#include <algorithm>
#include <vector>
#include <iostream>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// using namespace std;

int solution(std::vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)

    std::vector<int> v = A;
    int result;

    std::sort(v.begin(), v.end());

    for (int i = 1; i < 100001; i++)
    {

        if (find(v.begin(), v.end(), i) != v.end())
        {
            continue;
        }

        else
        {
            result = i;
            break;
        }
    }

    return result;
}
int main()
{
    std::vector<int> MyVector = {1, 2, 3, 4};
    int MyResult;
    MyResult = solution(MyVector);

    std::cout << "Found Postive Integer " << MyResult << std::endl;
    return 0;
}
