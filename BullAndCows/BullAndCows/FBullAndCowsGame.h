#pragma once
#include <string>

class FBullAndCowsGame
{
public:
	void Reset();
	int GetMaxTry();
	int GetCurrentTry();
	bool IsGameWon();
	bool IsGuessValid(std::string);

private:
	int MyCurrentTry;
	int MyMaxTries;
};