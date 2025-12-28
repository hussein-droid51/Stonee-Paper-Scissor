#include <iostream>
#include <cstdlib>   
#include <ctime>

using namespace std;
enum enGameChoice{ Stone=1, Paper=2, Scissor=3 };
enum enWinner{ Player1=1, Computer=2, Draw=3 };

struct StRoundInfo {
    short RoundNumber = 0;
    enGameChoice Player1Choice;      // was enGameChoice Player1Choice();
    enGameChoice ComputerChoice;     // was enGameChoice ComputerChoice();
    enWinner Winner;
    string winnerName = " ";
};

struct stGameResult {
    short GameRound;
    short Player1WinsTimes;
    short ComputerWinsTimes;
    short DrawTimes;
    enWinner GameWinner;
    string WinnerName=" ";
};
 
short ReadHowmanyRound()
{
    short HowmanyRound =1;
    do
    {
        cout<<"How many round you want to play ? ";
        cin >> HowmanyRound;
    } while (HowmanyRound <1 || HowmanyRound>10);
    
    return HowmanyRound;
}

enGameChoice Player1Choice()
{
    short choice;
    do {
       cout<<" your choice is [1]Stone,[2]Paper,[3]Scissor?"<<endl;
      cin >> choice;
    }while(choice <1 || choice > 3);
  return (enGameChoice)choice;
}

void setScreenWinner(StRoundInfo RoundInfo)
{
    if (RoundInfo.Winner == Player1)
    {
        system("color 2F");
       
    }
    else if (RoundInfo.Winner == Computer)
    {
        system("color 4F");
        cout << "\a";
    }
    else if (RoundInfo.Winner == Draw)
    {
        system("color 6F");

    }
    

    

}
int RandomChoice(int From,int To)
{
    return rand() % (To-From+1)+From;
}

enGameChoice GetComputerChoice()
{
    return (enGameChoice) RandomChoice(1,3);
}

enWinner WhoWonTheRound(StRoundInfo RoundInfo)
{
    if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
    {
        return enWinner::Draw;
    }

    switch (RoundInfo.Player1Choice)
    {
        case enGameChoice::Stone:
            if (RoundInfo.ComputerChoice == enGameChoice::Paper)
            {
                return enWinner::Computer;
            }
            break;
        case enGameChoice::Paper:
            if (RoundInfo.ComputerChoice == enGameChoice::Scissor)
            {
                return enWinner::Computer;
            }
            break;
        case enGameChoice::Scissor:
            if (RoundInfo.ComputerChoice == enGameChoice::Stone)
            {
                return enWinner::Computer;
            }
            break;
    }
    return enWinner::Player1;
}

enWinner WhoWonTheGame(short player1WinsTimes, short ComputerWinsTimes)
{
    if (player1WinsTimes > ComputerWinsTimes) return enWinner::Player1;
    else if (ComputerWinsTimes > player1WinsTimes) return enWinner::Computer;
    else return enWinner::Draw;
}

string  WinnerName(enWinner winner)
{
    string  arrWinnerName[3] = { "Player1","Computer","(No Winner)Draw" };
    return arrWinnerName[winner - 1];
}

string ChoiceName(enGameChoice Choice)
{
    string arrGamechoices[3]={"Stone","Paper","Scissors"};
    return arrGamechoices[Choice - 1];
}

// setWinerScreenColor ;

void PrintRoundResult(StRoundInfo RoundInfo)
{
    cout<<"\n__________Round["<<RoundInfo.RoundNumber<<"]_________\n\n";
    cout<<"Player1  Choice : "<<ChoiceName(RoundInfo.Player1Choice)<<endl;
    cout<<"Computer Choice : "<<ChoiceName(RoundInfo.ComputerChoice)<<endl;
    cout<<"  Round  winner : ["<<RoundInfo.winnerName<<"] \n";
    cout<<"______________________________________________\n"<<endl;
    setScreenWinner(RoundInfo);
}
stGameResult FillGameResult(int GameRound, short player1WinsTimes, short computerWinsTimes, short DrawTimes)
{
    stGameResult GameResult;
    GameResult.GameRound = GameRound;
    GameResult.Player1WinsTimes = player1WinsTimes;
    GameResult.ComputerWinsTimes = computerWinsTimes;
    GameResult.DrawTimes = DrawTimes;
    GameResult.GameWinner = WhoWonTheGame(player1WinsTimes, computerWinsTimes);
    GameResult.WinnerName = WinnerName(GameResult.GameWinner);
    
    return GameResult;
}
stGameResult playGame(short HowManyRound)
{
 StRoundInfo RoundInfo ;
  short Player1WinTimes=0 , ComputerWinTimes=0 ,DrawTimes=0;

  for (short GameRoud = 1; GameRoud <= HowManyRound; GameRoud++)
  {
    cout<<"\nRound ["<<GameRoud<<"] Begins :\n";
    RoundInfo.RoundNumber=GameRoud;
    RoundInfo.Player1Choice=Player1Choice();
    RoundInfo.ComputerChoice= GetComputerChoice();
    RoundInfo.Winner= WhoWonTheRound(RoundInfo);
    RoundInfo.winnerName = WinnerName(RoundInfo.Winner);
   //increse win/Draw counters
    if (RoundInfo.Winner == enWinner::Player1)
        Player1WinTimes++;
    else if (RoundInfo.Winner == enWinner::Computer)
        ComputerWinTimes++;
    else if (RoundInfo.Winner == enWinner::Draw)
    DrawTimes++;
     PrintRoundResult(RoundInfo);

  }
  return  FillGameResult( HowManyRound,Player1WinTimes ,ComputerWinTimes,DrawTimes) ;
}

string tabs(short NumberOFTabs)
{
    string t = "";
    for (int i = 0; i < NumberOFTabs; i++)
    {
        t = t + '\t';
        cout<< t;
    }
    return t;
}

void showGameOverScreen()
{
    cout << tabs(2) << "__________________________________________________\n\n";
    cout << tabs(2) << "      ++++++++++++   Game Over  +++++++++++ \n";
    cout << tabs(2) << "__________________________________________________\n\n";

}

void setscreencolor(enWinner winner)
{
    switch (winner)
    {
    case enWinner::Player1:
        system("color F2");//tern to Green 
        break;
    case enWinner::Computer:
        system("color 4F");// tern to red
        cout << "\a";
        break;
    default:
        system("color F6");// tern to yellow
        break;

    }
}

void showFinalGameResult(stGameResult GameResult)
{
    cout << tabs(2) << "_______________________[Game Result ]_______________\n";
    cout << tabs(2) << "Game Rounds        : " << GameResult.GameRound << endl;
    cout << tabs(2) << "player1 Won times  : " << GameResult.Player1WinsTimes << endl;
    cout << tabs(2) << "Computer Won times : " << GameResult.ComputerWinsTimes << endl;
    cout << tabs(2) << "Draw Times         : " << GameResult.DrawTimes << endl;
    cout << tabs(2) << "Final winner       : " << GameResult.WinnerName << endl;
    cout << tabs(2) << "_____________________________________________________"  << endl;
    setscreencolor(GameResult.GameWinner);
}
void ResatScreen()
{
    system("cls");  // Clear the screen before starting a new game.
    system("color 0F");

}
void startGame()
{
    char PlayAgain = 'Y';

    do
    {
        ResatScreen();
        stGameResult GameResults = playGame(ReadHowmanyRound()); // Play 3 rounds.
        showGameOverScreen();
        showFinalGameResult(GameResults);
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}


int main() {
 srand((unsigned)time(NULL));
 startGame();
    return 0;
}