#pragma once
#include <iostream>

using namespace std;

class PlayerOne
{
private:
	int secretNum;
	int cpuGuess;
	int cpuTries;

public:
	PlayerOne();
	PlayerOne(int a, int b);
	void thinkNumber();
	int getSecretNumber();
	void updateCpuGuess();
	int getCpuGuess();
	int getCpuTries();
	friend void updateCpuTries(PlayerOne &a);
	friend void guessNumber(int playerGuess, PlayerOne &a, int tries, int check);


};
