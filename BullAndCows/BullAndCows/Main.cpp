#include "pch.h"
#include <iostream>
#include <string>
#include "FBullAndCowsGame.h"

constexpr int WORD_LENGTH = 5;

void PrintIntro();
void PlayGame();
std::string GetGuess();
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
	int maxTries = BCGame.GetMaxTry();

	for (int count = 1; count <= maxTries; count++)
	{
		std::string guess = GetGuess();
		std::cout << "You guess is '" << guess << "'" << std::endl;
	}
}

std::string GetGuess()
{
	int currentTry = BCGame.GetCurrentTry();
	std::string guess;

	std::cout << "Try #" << currentTry << ". Enter your guess: " << std::endl;
	std::getline(std::cin, guess);
	std::cout << std::endl;
	return guess;
}

bool ShouldPlayAgain()
{
	std::string response;

	std::cout << "Would you like to play again?" << std::endl;
	getline(std::cin, response);
	
	return (response[0] == 'y') || (response[0] == 'Y');
}