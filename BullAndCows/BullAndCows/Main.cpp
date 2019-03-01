#include "pch.h"
#include <iostream>
#include <string>

constexpr int WORD_LENGTH = 5;
constexpr int GAME_LENGHT = 3;

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool ShouldPlayAgain();

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
	for (int count = 1; count <= GAME_LENGHT; count++)
	{
		std::string guess = GetGuess();
		std::cout << "You guess is '" << guess << "'" << std::endl;
	}
}

std::string GetGuess()
{
	std::string guess;

	std::cout << "Enter your guess: " << std::endl;
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