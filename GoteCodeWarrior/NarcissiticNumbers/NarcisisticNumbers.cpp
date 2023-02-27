#include <cmath>
#include <iostream>

using namespace std;

int TestInteger = 1;

bool narcissistic(int value)
{
  // Code away
  int InputValue = value;
  int Nvalue = 0;
  int NSumFrDigit = 0;
  int NRofFigures = 0;
  int DigitX = 0;

  while (value != 0)
  {
    value = value / 10;
    NRofFigures++;
  }

  value = InputValue;

  while (value != 0)
  {
    DigitX = value % 10;

    // here you will get its element one by one but in reverse order
    // you can perform your action here.

    Nvalue = Nvalue + pow(DigitX, NRofFigures);
    value /= 10;
  }

  return (Nvalue == InputValue);
}

int main()
{

  while (true)
  {
    cout << "Give Value To Be Tested If It Is "
            "Narcissistic"
            "(Quit with 0): ";
    cin >> TestInteger;

    if (TestInteger == 0)
    {
      break;
    }

    if (narcissistic(TestInteger))
    {
      cout << "True" << endl;
    }
    else
    {
      cout << "False" << endl;
    }
  }

  return 0;
}
