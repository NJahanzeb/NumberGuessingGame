#include <iostream>
#include "playerone.h"
#include "playertwo.h"
#include <stdlib.h> 
#include<time.h>

using namespace std;

PlayerOne::PlayerOne() : secretNum(0), cpuGuess(0), cpuTries(0)
{}

PlayerOne::PlayerOne(int a, int b) : secretNum(a), cpuGuess(b), cpuTries(0)
{}

void PlayerOne::thinkNumber()
{
	srand(time(0));
	secretNum = rand() % (100 - 0 + 1) + 0;
}

int PlayerOne::getSecretNumber()
{
	return secretNum;
}

void PlayerOne::updateCpuGuess()
{
	srand(time(0));
	cpuGuess = rand() % (100 - 0 + 1) + 0;
}

int PlayerOne::getCpuGuess()
{
	return cpuGuess;
}

int PlayerOne::getCpuTries()
{
	return cpuTries;
}





PlayerTwo::PlayerTwo() : tries(0), userGuess(0), tossValue(1)
{}

PlayerTwo::PlayerTwo(int a) : tries(0), userGuess(a), tossValue(1)
{}

int PlayerTwo::getTries()
{
	return tries;
}

int PlayerTwo::getUserGuess()
{
	return userGuess;
}





void updateTries(PlayerTwo &b)
{
	++b.tries;
}

void setUserGuess(PlayerTwo &b)
{
	cout << "\nYour turn.\nEnter number (between 0 and 100): ";
	cin >> b.userGuess;
}

int toss(PlayerTwo &b)
{
	srand(time(0));
	b.tossValue = rand() % (2 - 1 + 1) + 1;
	return b.tossValue;
}

void updateCpuTries(PlayerOne &a)
{
	++a.cpuTries;
}

void guessNumber(int playerGuess, PlayerOne &a, int tries, int check)
{

	if (playerGuess == a.getSecretNumber())
	{
		if (check == 0)
		{
			cout << "\nCPU guessed the number.\nSecret number: " << a.getSecretNumber() << "\nTotal tries by CPU: " << tries << endl;
			exit(0);
		}
		else
		{
			cout << "\nConngratulations, you guessed the number.\nSecret number: " << a.getSecretNumber() << "\nTotal tries: " << tries << endl;
			exit(0);
		}
	}
	else
	{
		if (check == 0)
		{
			cout << "\nCPU could not guess the number.\nCPU's guess: " << playerGuess << "\nTotal tries by CPU: " << tries << endl;
		}
		else
		{
			cout << "\nYour guess was wrong.";
			if (playerGuess < a.getSecretNumber())
			{
				cout << "\nHint: go higher.";
			}
			else
			{
				cout << "\nHint: go lower.";
			}
			cout << "\nTotal tries: " << tries << endl;
		}
	}
}
