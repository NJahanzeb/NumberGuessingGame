#include <iostream>
#include "playerone.h"
#include "playertwo.h"
#include <stdlib.h>
#include <chrono>
#include <thread>
#include "gamemanager.h"

using namespace std;

int main()
{
	GameManager g;
	PlayerOne a;
	PlayerTwo b;

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   Welcome to number guessing game.\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPress enter to start";
	cin.ignore();
	system("CLS");

	g.thinkNumber();
	int turn = g.toss();

	if (turn == 1)
	{
		cout << "\nYou won the toss!\n\n";
		while (1)
		{
			b.setUserGuess();
			g.updateUserTries(b);
			g.guessNumber(1, a, b);
			chrono::seconds dura(1);
			this_thread::sleep_for(dura);
			a.updateCpuGuess();
			g.updateCpuTries(a);
			g.guessNumber(0, a, b);
		}
	}
	else
	{
		cout << "\nCPU won the toss!\n\n";
		while (1)
		{
			chrono::seconds dura(1);
			this_thread::sleep_for(dura);
			a.updateCpuGuess();
			g.updateCpuTries(a);
			g.guessNumber(0, a, b);
			b.setUserGuess();
			g.updateUserTries(b);
			g.guessNumber(1, a, b);
		}
	}
}
