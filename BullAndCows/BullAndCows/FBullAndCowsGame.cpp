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
int32 FBullAndCowsGame::GetHiddenWordLenght() const { return MyHiddenWord.length(); }
bool FBullAndCowsGame::IsGameWon() const { return bIsGameWon; }

void FBullAndCowsGame::Reset()
{
	constexpr int32 MAX_TRIES = 3;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bIsGameWon = false;
}

EGuessStatus FBullAndCowsGame::IsGuessValid(FString guess)
{
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (guess.length() != GetHiddenWordLenght())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::Ok;
	}
}

FBullCowCount FBullAndCowsGame::SubmitValidGuess(FString guess)
{
	MyCurrentTry++;
	FBullCowCount bullCowCount;

	for (int32 word1 = 0; word1 < GetHiddenWordLenght(); word1++)
	{
		for (int32 word2 = 0; word2 < GetHiddenWordLenght(); word2++)
		{
			if (guess[word1] == MyHiddenWord[word2])
			{
				if (word1 == word2)
				{
					bullCowCount.Bulls++;
				}
				else
				{
					bullCowCount.Cows++;
				}
			}
		}
	}

	if (bullCowCount.Bulls == GetHiddenWordLenght())
	{
		bIsGameWon = true;
	}
	else 
	{
		bIsGameWon = false;
	}
	
	return bullCowCount;
}
