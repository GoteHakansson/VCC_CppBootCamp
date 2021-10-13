#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){

    signed int HighGuess = 128;
    signed int LowGuess = 1;
    signed int CurrentGuess = 64;
    signed int NumberOfAttempts = 0;
    bool CorrectGuess = false;
    char Answer = 'n';
    std::string const InitialQuestion1 = "Think of an integer number between 1 - 128!\n";
    std:: string const InitialQuestion2 = "(I will try to guess which number within 7 attemps...)\n\n";
    std::string const MyGuessStr = "Is this the number you are thinking of ";
    std::string const QuestionStr = "?\n(Enter: y => For Yes, h => No, my number is higer, l => No, my number is lower)\n";
    std::string const NrOfAttempsStr = "Numerber of attempts by me: ";

    std::srand((unsigned) std::time(0));
    CurrentGuess = (std::rand() % 128 + 1);
    // CurrentGuess = 64;

    std::cout << InitialQuestion1 << InitialQuestion2;

    while (!CorrectGuess && NumberOfAttempts < 7){

        std::cout << MyGuessStr << CurrentGuess << QuestionStr;
        std::cin >> Answer;
        switch (Answer){
            case 'Y': CorrectGuess= true; break;
            case 'y': CorrectGuess= true; break;
            case 'H':
                LowGuess = CurrentGuess;CurrentGuess = CurrentGuess + ((HighGuess - LowGuess)/2);
                if (HighGuess == (LowGuess + 1)){CurrentGuess = CurrentGuess + 1;}
                // std::cout << "lowGuess: " << LowGuess << std::endl;
                // std::cout << "higGuess: " << HighGuess << std::endl;
                break;
            case 'h':
                LowGuess = CurrentGuess;CurrentGuess = CurrentGuess + ((HighGuess - LowGuess)/2);
                if (HighGuess == LowGuess + 1){CurrentGuess = CurrentGuess + 1;}
                // std::cout << "lowGuess: " << LowGuess << std::endl;
                // std::cout << "higGuess: " << HighGuess << std::endl;
                break;
            case 'L':
                HighGuess = CurrentGuess;CurrentGuess = CurrentGuess - ((HighGuess - LowGuess)/2);
                if (HighGuess == (LowGuess + 1)){CurrentGuess = CurrentGuess - 1;}
                // std::cout << "lowGuess: " << LowGuess << std::endl;
                // std::cout << "higGuess: " << HighGuess << std::endl;
                break;
            case 'l':
                HighGuess = CurrentGuess;CurrentGuess = CurrentGuess - ((HighGuess - LowGuess)/2);
                if (HighGuess == (LowGuess +1)){CurrentGuess = CurrentGuess - 1;}
                // std::cout << "lowGuess: " << LowGuess << std::endl;
                // std::cout << "higGuess: " << HighGuess << std::endl;
                break;
            default: break;
        }
        NumberOfAttempts++;        
    }
        std::cout << NrOfAttempsStr << NumberOfAttempts << std::endl;
}
