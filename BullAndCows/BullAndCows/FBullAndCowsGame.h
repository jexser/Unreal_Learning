#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	Ok,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullAndCowsGame
{
public:
	FBullAndCowsGame();

	int32 GetMaxTry() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLenght() const;
	bool IsGameWon() const;

	void Reset();
	EGuessStatus IsGuessValid(FString guess);
	FBullCowCount SubmitValidGuess(FString guess);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bIsGameWon;
};