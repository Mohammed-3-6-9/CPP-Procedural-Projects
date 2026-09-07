#include <iostream>
#include <cstdlib>
using namespace std;

enum enChoice { Stone = 1, Papier = 2, Scissor = 3 };

enum enWinnerOrNot{Loser = 0 , Winner =1, Equal = 2};

int ReadNumber(string Message)
{
	int Number;

	cout << Message;
	cin >> Number;

	return Number;
}

int RandomNumber(int From, int To)
{
	return (rand() % (To - From + 1) + From);
}

string Choice(int Choic)
{
	switch ((enChoice)Choic)
	{
	case enChoice::Stone:
		return "[Stone]";
		break;
	case enChoice::Papier:
		return "[Papier]";
		break;
	case enChoice::Scissor:
		return "[Scissor]";
		break;
	}
}

int CheckWinner(int UserChoice, int ComputerChoice)
{
	switch ((enChoice)ComputerChoice)
	{
	case enChoice::Stone:
	{
		if ((enChoice)UserChoice == enChoice::Stone)
		{
			return 2;
		}
		else if ((enChoice)UserChoice == enChoice::Papier)
		{
			return 1;
		}
		else
		{
			return 0;
		}
		break;
	}
	case enChoice::Papier:
	{
		if ((enChoice)UserChoice == enChoice::Stone)
		{
			return 0;
		}
		else if ((enChoice)UserChoice == enChoice::Papier)
		{
			return 2;
		}
		else
		{
			return 1;
		}
		break;
	}
	case enChoice::Scissor:
	{
		if ((enChoice)UserChoice == enChoice::Stone)
		{
			return 1;
		}
		else if ((enChoice)UserChoice == enChoice::Papier)
		{
			return 0;
		}
		else
		{
			return 2;
		}
		break;
	}
	}
}

void StartRound(int NumberOfRounds,int& UserWinnerCount , int& ComputerWinnerCount)
{
	int UserChoice = 0, ComputerChoice = 0;
	string RoundWinner = "";

	for (int i = 1; i <= NumberOfRounds; i++)
	{	
		cout << " Round [" << i << "] Begins \n" << endl;
		ComputerChoice = RandomNumber(1, 3);
		UserChoice = ReadNumber("Your Choice : Stone --> [1] , Papier --> [2] , Scissor --> [3] ? \n");
		switch (CheckWinner(UserChoice, ComputerChoice))
		{
		case 0:
			RoundWinner = "[Computer]\a";
			system("color 4f");
			ComputerWinnerCount++;
			
			break;
		case 1:
			RoundWinner = "[User]";
			system("color 2f");
			UserWinnerCount++;
			break;
		case 2:
			RoundWinner = "[None]";
			system("color 6f");
			break;
		}
		cout << "\n---------------- Round [" << i << "]----------------" << endl;
		cout << " Player 1 Choice " << Choice(UserChoice) << endl;
		cout << " Computer Choice " << Choice(ComputerChoice) << endl;
		cout << " Round Winner " << RoundWinner << endl;
		cout << "--------------------------------\n" << endl;
	}
}

void PrintGameResult(int NumberOfRounds,int UserWinnerCount,int ComputerWinnerCount)
{
	cout << "\t\t\t\t------------------------------------------------\n" << endl;
	cout << "\t\t\t\t\t + + + G A M E   O V E R + + + \n" << endl;
	cout << "\t\t\t\t------------------------------------------------\n" << endl;
	cout << "\t\t\t\t----------------[ Game Results ]----------------" << endl;
	cout << "\t\t\t\tGame Rounds : " << NumberOfRounds << endl;
	cout << "\t\t\t\tPlayer1 Won Times : " << UserWinnerCount << endl;
	cout << "\t\t\t\tComputer Won Times : " << ComputerWinnerCount << endl;
	cout << "\t\t\t\tDraw Times : " << NumberOfRounds - (ComputerWinnerCount + UserWinnerCount) << endl;
	if (UserWinnerCount > ComputerWinnerCount)
	{
		cout << "\t\t\t\tFinal Winner : User" << endl;
		system("color 2f");
	}
	else if (ComputerWinnerCount > UserWinnerCount)
	{
		cout << "\t\t\t\tFinal Winner : Computer\a" << endl;
		system("color 4f");
	}
	else
	{
		cout << "\t\t\t\tFinal Winner : None" << endl;
		system("color 6f");
	}
	cout << "\t\t\t\t------------------------------------------------\n" << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	int NumberOfRounds = 0;
	int UserWinnerCount = 0, ComputerWinnerCount = 0;
	bool RePlay;

	do
	{
		system("cls");
		system("color 0f");
		NumberOfRounds = ReadNumber("Please enter the number of rounds ? \n");

		StartRound(NumberOfRounds, UserWinnerCount, ComputerWinnerCount);
		PrintGameResult(NumberOfRounds, UserWinnerCount, ComputerWinnerCount);

		cout << " Are You Want To Play Again ( 1 -->[Yes] , 0 -->[No] ) ";
		cin >> RePlay;
		cout << endl;
	} while (RePlay);
	

	return 0;
}