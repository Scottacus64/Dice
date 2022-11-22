#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "Dice.h"

using namespace std;

string rollInput;
int parsedString[5];

void print(int result[]);
void diceToRoll(string rollInput);

int main()
{   
    Dice dieArray[5];                       // create the array of dice objects
    bool again = true;
    while (again == true)
    {
        rollInput = "12345";                // default rollInput so that all dice will be rolled the first time
        int result[5];                      // create an array of roll results

    

        for (int i=0; i<5; i++){            
            Dice die(6);                    // populate the dieArray
            dieArray[i] = die;              
        }
        for (int a=0; a<3; a++){            // roll the dice three times
            if (a>0)                        // every time but the first time ask which dice to re-roll
            {
                cout << "Which dice do you want to re-roll (enter \"q\" to stop rolling)?\n";
                cin >> rollInput;
            }
            string test = "q";
            if (rollInput == test)
            {
                break;
            }
            diceToRoll(rollInput);
            for (int i=0; i<5; i++){
                for (int j = 0; j<5; j++){
                    if (parsedString[j] == i)
                    {
                    result[i] = dieArray[i].roll();
                    }
                }
                
            }
            print(result);
        }
        cout << "Do you want to try again (y/n)?";
        char inputChar;
        cin >> inputChar;
        if (inputChar == 'n' or inputChar == 'N')
        {
            again = false;
        }
    }
    return 0;
}

void print(int result[])
{
    cout << "\nDie Number: 1  2  3  4  5 \n";
    cout << "Dice Roll:  ";
    for (int i=0; i<5; i++)
    {
        cout << result[i] << "  ";
    }
    cout << "\n";
}


void diceToRoll(string rollInput)
{
    int stringLen;
    int rollThese[5];
    stringLen = rollInput.length();
    cout << stringLen << "\n";
    vector<char> rollChar(rollInput.begin(), rollInput.end());
    for (int i=0; i<stringLen; i++)
    {
        parsedString[i] = rollChar[i] - 49;
        if (parsedString[i] < 0 || parsedString[i] > 4)
        {
            parsedString[i] = 6;
        }
        cout << (parsedString[i]) << " ";
    }
    if (stringLen < 5)
    {
        for (int i=stringLen; i<5; i++)
        {
            parsedString[i] = 6;
        }
    }
    cout << "\n";
 
}
