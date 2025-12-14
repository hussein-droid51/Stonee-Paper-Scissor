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

Mychose User_Choice( )
{
    int choice = 0;
   cout<<"your choice : [1]:stone , [2]:paper, [3]: Scissor ? \n";
   cin >> choice;


    if (choice == 1)
       return Stone;

    if (choice == 2)
        return Paper;

    if (choice == 3)
        return  Scissor;
}

Mychose PC_Choice()
{
    int pcchoice = rand() % 3 + 1;
    return static_cast<Mychose>(pcchoice);
}
void Determine_Winner(Mychose user, Mychose pc)
{
	int playerWinCount = 0;
	int pcWinCount = 0;
	int drawCount = 0;
    if (user == pc)
    {
        cout << "No winner!" << endl;
        drawCount++;
    }
    else if (
        (user == Stone && pc == Scissor) ||
        (user == Paper && pc == Stone) ||
        (user == Scissor && pc == Paper))
    {
        cout << "[Player win]" << endl;
        playerWinCount++;
    }
    else
    {
        cout << "[PC wins]" << endl;
		pcWinCount++;
    }
}



 
int Startgame()
{
    int Number = HowmanyRounds("who many Rounds 1 to 10  ? ");
    for (int i = 1; i <=Number; i++)
    {
        cout << "Round [" << i << "] begins :\n" << endl;
        Mychose user = User_Choice();
        Mychose Pc = PC_Choice();
		cout << "             Round                           "<<endl;
        cout << "----------     [" << i << "]--------------\n" << endl;
		cout << "Player   choice is : " << user << endl;
		cout << "Computer choice is : " << Pc << endl;
        cout << "Round Winner       : ";
            Determine_Winner(user, Pc);
			cout << "------------------------------\n" << endl;
            cout << "-------------------------------\n" << endl;
            cout << "         Game Over          \n" << endl;
            cout << "-------------------------------\n" << endl;
            cout << "----------Game Result----------\n" << endl;
            cout << "Game Rounds   " << Number;
            cout << "Player won times "<< Determine_Winner()


    }
	return 0;
}


int main()
{
    srand((unsigned)time(NULL));

	Startgame();
    

}


