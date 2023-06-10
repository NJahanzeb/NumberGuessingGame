#pragma once
#include <iostream>

using namespace std;

class PlayerTwo
{
private:
	int tries;
	int userGuess;
	int tossValue;

public:
	PlayerTwo();
	PlayerTwo(int a);
	int getTries();
	int getUserGuess();
	friend void updateTries(PlayerTwo &b);
	friend void setUserGuess(PlayerTwo &b);
	friend int toss(PlayerTwo &b);
};
