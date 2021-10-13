#include <iostream>

int main()
{

  std::string Chiper1 = "OLSSV";
  int Key1 = 7;
  std::string Chiper2 = "VKRIMHZKTIAR";
  int Key2 = 19;

  for (int i = 0; i <= 4; i++)
  {
    Chiper1[i] = Chiper1[i] - Key1;
  }
  //Print first deciffered word:
  //============================
  for (int i = 0; i <= 4; i++)
  {
    std::cout << Chiper1[i];
  }
  std::cout << std::endl;
  //=============================



  for (int i = 0; i <= 11; i++)
  {
    Chiper2[i] = Chiper2[i] - Key2;
  }

  for (int i = 0; i <= 11; i++)
  {

    if (Chiper2[i] < 'A')
    {
      Chiper2[i] = 'Z' - ('A' - Chiper2[i]);
    }
  }
  //Print second deciffered word:
  //============================
  for (int i = 0; i <= 11; i++)
  {
    std::cout << Chiper2[i];
  }
  std::cout << std::endl;
  //=============================
}
