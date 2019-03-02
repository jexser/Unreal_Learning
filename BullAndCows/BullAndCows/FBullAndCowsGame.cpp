#include "pch.h"
#include "FBullAndCowsGame.h"

using FString = std::string;
using int32 = int;

FBullAndCowsGame::FBullAndCowsGame()
{
	Reset();
}

int32 FBullAndCowsGame::GetMaxTry() const { return MyMaxTries; }
int32 FBullAndCowsGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullAndCowsGame::IsGameWon() const { return false; }

void FBullAndCowsGame::Reset()
{
	constexpr int32 MAX_TRIES = 3;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
}

bool FBullAndCowsGame::IsGuessValid(FString)
{
	return false;
}

BullCowCount FBullAndCowsGame::SubmitGuess(FString)
{
	MyCurrentTry++;
	BullCowCount bullCowCount;

	return bullCowCount;
}
