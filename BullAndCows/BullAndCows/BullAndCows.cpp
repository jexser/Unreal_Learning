#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

constexpr int WORD_LENGTH = 5;
string guess;

void PrintIntro();
string GetGuess();

int main()
{
	PrintIntro();
	GetGuess();

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

string GetGuess()
{
	cout << "Enter your guess: " << endl;
	getline(cin, guess);
	cout << "You guess is '" << guess << "'" << endl;
	return guess;
}