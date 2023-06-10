#include <iostream>
#include "playerone.h"
#include "playertwo.h"
#include <stdlib.h>
#include <chrono>
#include <thread>

using namespace std;

void updateTries(PlayerTwo& b);
void setUserGuess(PlayerTwo& b);
int toss(PlayerTwo &b);
void updateCpuTries(PlayerOne& a);
void guessNumber(int playerGuess, PlayerOne &a, int tries, int check);

int main()
{
	PlayerOne a;
	PlayerTwo b;

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   Welcome to number guessing game.\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPress enter to start";
	cin.ignore();
	system("CLS");

	a.thinkNumber();
	int turn = toss(b);

	if (turn == 1)
	{
		cout << "\nYou won the toss!\n\n";
		while (1)
		{
			setUserGuess(b);
			updateTries(b);
			guessNumber(b.getUserGuess(), a, b.getTries(), 1);
			chrono::seconds dura(1);
			this_thread::sleep_for(dura);
			a.updateCpuGuess();
			updateCpuTries(a);
			guessNumber(a.getCpuGuess(), a, a.getCpuTries(), 0);
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
			updateCpuTries(a);
			guessNumber(a.getCpuGuess(), a, a.getCpuTries(), 0);
			setUserGuess(b);
			updateTries(b);
			guessNumber(b.getUserGuess(), a, b.getTries(), 1);
		}
	}
}
