#pragma once
#include <iostream>

using namespace std;

class PlayerOne
{
private:
	int cpuGuess;
	int cpuTries;

public:
	PlayerOne();
	PlayerOne(int a);
	void updateCpuGuess();
	friend class GameManager;
};
