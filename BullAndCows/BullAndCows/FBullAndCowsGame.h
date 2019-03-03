#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullAndCowsGame
{
public:
	FBullAndCowsGame();

	int32 GetMaxTry() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLenght() const;
	bool IsGameWon() const;
	bool IsGuessValid(FString);

	void Reset();
	FBullCowCount SubmitGuess(FString guess);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};