#pragma once

#include "pch.h"
#include "FBullAndCowsGame.h"
#include <map>
#define TMap std::map

using FString = std::string;
using int32 = int;

FBullAndCowsGame::FBullAndCowsGame()
{
	Reset();
}

int32 FBullAndCowsGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullAndCowsGame::GetHiddenWordLenght() const { return MyHiddenWord.length(); }
bool FBullAndCowsGame::IsGameWon() const { return bIsGameWon; }

int32 FBullAndCowsGame::GetMaxTries() const 
{ 
	TMap<int32, int32> WordLenghtToMaxTries
	{
		{3, 5}, {4, 6}, {5, 7}, {6, 9}, {7, 10}
	};
	return WordLenghtToMaxTries[MyHiddenWord.length()];
}

void FBullAndCowsGame::Reset()
{
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bIsGameWon = false;
}

EGuessStatus FBullAndCowsGame::IsGuessValid(FString guess)
{
	if (!IsIsogram(guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowerCase(guess))
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

bool FBullAndCowsGame::IsIsogram(FString word) const
{
	if (word.length() <= 1)
	{
		return true;
	}

	TMap<char, bool> LettersSeen;

	for (auto letter : word)
	{
		letter = tolower(letter);
		if (LettersSeen[letter])
		{
			return false;
		}
		else LettersSeen[letter] = true;
	}

	return true;
}

bool FBullAndCowsGame::IsLowerCase(FString word) const
{
	for (auto letter : word)
	{
		if (!islower(letter))
		{
			return false;
		}
	}
	return true;
}
