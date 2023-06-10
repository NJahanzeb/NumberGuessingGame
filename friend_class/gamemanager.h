#pragma once
using namespace std;

class GameManager
{
private:
	int secretNum;

public:
	GameManager();
	GameManager(int a);
	void thinkNumber();
	int toss();
	void guessNumber(int check, PlayerOne a, PlayerTwo b);
	void updateUserTries(PlayerTwo &b);
	void updateCpuTries(PlayerOne &a);

};
