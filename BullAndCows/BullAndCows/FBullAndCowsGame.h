#pragma once
#include <string>

class FBullAndCowsGame
{
public:
	int GetMaxTry() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();
	bool IsGuessValid(std::string);

private:
	int MyCurrentTry = 1;
	int MyMaxTries = 3;
};