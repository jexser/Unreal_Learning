#include "pch.h"
#include <iostream>
#include <string>
#include "FBullAndCowsGame.h"

using FText = std::string;
using int32 = int;

constexpr int32 WORD_LENGTH = 5;

void PrintIntro();
void PlayGame();
FText GetGuess();
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
	std::cout << "--- Welcome to the best game ever!" << std::endl
		<< "--- Designed by Jexser" << std::endl
		<< "--- Game description here" << std::endl
		<< std::endl
		<< "Can you guess the " << WORD_LENGTH << " letters isogram that I guessed?"<< std::endl
		<< std::endl;
}

void PlayGame()
{
	BCGame.Reset();
	int32 maxTries = BCGame.GetMaxTry();

	for (int32 count = 1; count <= maxTries; count++)
	{
		FText guess = GetGuess();
		std::cout << "You guess is '" << guess << "'" << std::endl
			<< std::endl;
	}
}

FText GetGuess()
{
	int32 currentTry = BCGame.GetCurrentTry();
	FText guess;

	std::cout << "Try #" << currentTry << ". Enter your guess: " << std::endl;
	std::getline(std::cin, guess);
	std::cout << std::endl;
	return guess;
}

bool ShouldPlayAgain()
{
	FText response;

	std::cout << "Would you like to play again?" << std::endl;
	getline(std::cin, response);
	
	return (response[0] == 'y') || (response[0] == 'Y');
}