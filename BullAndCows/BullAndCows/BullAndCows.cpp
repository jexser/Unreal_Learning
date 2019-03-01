#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

constexpr int WORD_LENGTH = 5;
constexpr int GAME_LENGHT = 3;

void PrintIntro();
void PlayGame();
string GetGuess();
bool ShouldPlayAgain();

int main()
{
	PrintIntro();
	PlayGame();
	ShouldPlayAgain();

	return 0;
}

void PrintIntro()
{
	cout << "--- Welcome to the best game ever!" << endl
		<< "--- Designed by Jexser" << endl
		<< "--- Game description here" << endl
		<< endl
		<< "Can you guess the " << WORD_LENGTH << " letters isogram that I guessed?" << endl;
}

void PlayGame()
{
	for (int count = 1; count <= GAME_LENGHT; count++)
	{
		string guess = GetGuess();
		cout << "You guess is '" << guess << "'" << endl;
	}
}

string GetGuess()
{
	string guess;

	cout << "Enter your guess: " << endl;
	getline(cin, guess);
	return guess;
}

bool ShouldPlayAgain()
{
	string response;

	cout << "Would you like to play again?" << endl;
	getline(cin, response);
	
	return (response[0] == 'y') || (response[0] == 'Y');
}
