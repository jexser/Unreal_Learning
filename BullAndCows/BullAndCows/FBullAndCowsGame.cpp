#include "pch.h"
#include "FBullAndCowsGame.h"


int FBullAndCowsGame::GetMaxTry() const { return MyMaxTries; }
int FBullAndCowsGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullAndCowsGame::IsGameWon() const { return false; }

void FBullAndCowsGame::Reset()
{
}

bool FBullAndCowsGame::IsGuessValid(std::string)
{
	return false;
}
