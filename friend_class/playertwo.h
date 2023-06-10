#pragma once
#include <iostream>

using namespace std;

class PlayerTwo
{
private:
	int userGuess;
	int userTries;

public:
	PlayerTwo();
	PlayerTwo(int a);
	void setUserGuess();
	friend class GameManager;
};
