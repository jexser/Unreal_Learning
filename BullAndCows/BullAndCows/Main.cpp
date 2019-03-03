#include "pch.h"
#include <iostream>
#include <string>
#include "FBullAndCowsGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool ShouldPlayAgain();

FBullAndCowsGame BCGame;

int main()
{
	do 
	{
		PrintIntro();
		PlayGame();
	}
	while (ShouldPlayAgain() == true);

	return 0;
}

void PrintIntro()
{
	std::cout << "\n--- Welcome to the best game ever!" << std::endl
		<< "--- Designed by Jexser" << std::endl
		<< "--- Game description here" << std::endl
		<< std::endl
		<< "Can you guess the " << BCGame.GetHiddenWordLenght() << " letters isogram that I guessed?" << std::endl
		<< std::endl;
}

void PlayGame()
{
	BCGame.Reset();

	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= BCGame.GetMaxTry())
	{
		FText guess = GetValidGuess();

		FBullCowCount bullCowCount = BCGame.SubmitValidGuess(guess);

		std::cout << "Bulls: " << bullCowCount.Bulls;
		std::cout << "; Cows: " << bullCowCount.Cows << std::endl;
	}
}

FText GetValidGuess()
{
	int32 currentTry = BCGame.GetCurrentTry();
	FText guess;
	EGuessStatus status = EGuessStatus::Invalid_Status;

	do
	{
		std::cout << "Try #" << currentTry << ". Enter your guess: " << std::endl;
		std::getline(std::cin, guess);
		std::cout << std::endl;

		status = BCGame.IsGuessValid(guess);
		switch (status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please, enter a word without repeating letters" << std::endl;
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please, enter a " << BCGame.GetHiddenWordLenght() << " number word" << std::endl;
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please, enter a word only with lowercase letters" << std::endl;
			break;
		default:
			status = EGuessStatus::Ok;
			break;
		}
	} while (status != EGuessStatus::Ok);
	return guess;
}

bool ShouldPlayAgain()
{
	FText response;

	std::cout << "Would you like to play again?" << std::endl;
	getline(std::cin, response);
	
	return (response[0] == 'y') || (response[0] == 'Y');
}