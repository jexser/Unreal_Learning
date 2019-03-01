#include "pch.h"
#include "FBullAndCowsGame.h"

FBullAndCowsGame::FBullAndCowsGame()
{
	Reset();
}

int FBullAndCowsGame::GetMaxTry() const { return MyMaxTries; }
int FBullAndCowsGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullAndCowsGame::IsGameWon() const { return false; }

void FBullAndCowsGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	MyCurrentTry = 1;
}

bool FBullAndCowsGame::IsGuessValid(std::string)
{
	return false;
}
