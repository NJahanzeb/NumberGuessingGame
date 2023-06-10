#include <iostream>
#include "playerone.h"
#include "playertwo.h"
#include "gamemanager.h"
#include <stdlib.h> 
#include<time.h>

using namespace std;

GameManager::GameManager() : secretNum(0)
{}

GameManager::GameManager(int a) : secretNum(a)
{}

void GameManager::thinkNumber()
{
	srand(time(0));
	secretNum = rand() % (100 - 0 + 1) + 0;
}

int GameManager::toss()
{
	srand(time(0));
	int value = rand() % (2 - 1 + 1) + 1;
	return value;
}

void GameManager::guessNumber(int check, PlayerOne a, PlayerTwo b)
{

	if (check == 0)
	{
		if (a.cpuGuess == secretNum)
		{
			cout << "CPU guessed the number.\nSecret number: " << secretNum << "\nTotal tries by CPU: " << a.cpuTries << endl;
			exit(0);
		}
		else
		{
			cout << "\nCPU could not guess the number.\nCPU's guess: " << a.cpuGuess << "\nTotal tries by CPU: " << a.cpuTries << endl;
		}
	}
	else
	{
		if (b.userGuess == secretNum)
		{
			cout << "Conngratulations, you guessed the number.\nSecret number: " << secretNum << "\nTotal tries: " << b.userTries << endl;
			exit(0);
		}
		else
		{
			cout << "\nYour guess was wrong.";
			if (b.userGuess < secretNum)
			{
				cout << "\nHint: go higher.";
			}
			else
			{
				cout << "\nHint: go lower.";
			}
			cout << "\nTotal tries: " << b.userTries << endl;

		}
	}
}


void GameManager::updateUserTries(PlayerTwo &b)
{
	++b.userTries;
}

void GameManager::updateCpuTries(PlayerOne &a)
{
	++a.cpuTries;
}





PlayerOne::PlayerOne() : cpuGuess(0), cpuTries(0)
{}

PlayerOne::PlayerOne(int a) : cpuGuess(a), cpuTries(0)
{}


void PlayerOne::updateCpuGuess()
{
	srand(time(0));
	cpuGuess = rand() % (100 - 0 + 1) + 0;
}





PlayerTwo::PlayerTwo() : userGuess(0), userTries(0)
{}

PlayerTwo::PlayerTwo(int a) : userGuess(a), userTries(0)
{}

void PlayerTwo::setUserGuess()
{
	cout << "\nYour turn.\nEnter number (between 0 and 100): ";
	cin >> userGuess;
}
