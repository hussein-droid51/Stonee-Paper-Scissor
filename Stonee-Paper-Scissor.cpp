#include <iostream>
#include <cstdlib>    // Include cstdlib for rand() and srand() functions.
using namespace std;
enum Mychose { Stone = 1,Paper=2,Scissor=3 };//For the chose

int HowmanyRounds(string Message )
{
    int Number;
    cout << Message << endl;
    cin >> Number;
    return Number;
}

Mychose choice(int choice )
{
     choice = HowmanyRounds("your choice : [1]:stone , [2]:paper, [3]: Scissor ? ");


    if (choice == 1)
        return Mychose::Stone;

    if (choice == 2)
        return Mychose::Paper;

    if (choice == 3)
        return Mychose::Scissor;
}

int RandomChoicePc(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum; 
}

int  RandomPCChoice()
{
    return RandomChoicePc(1, 3);
}



 
int sartgame()
{
    int Number = HowmanyRounds("who many Rounds 1 to 10  ? ");
    for (int i = 1; i < Number; i++)
    {
        cout << "Round [" << i << "] begins :" << endl;
        

    }
}


int main()
{
    srand((unsigned)time(NULL));


}


