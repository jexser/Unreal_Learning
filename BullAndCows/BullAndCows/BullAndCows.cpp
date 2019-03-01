#include "pch.h"
#include <iostream>

//using namespace std;

int main()
{
	constexpr int WORD_LENGTH = 5;

	std::cout << "--- Welcome to the best game ever!" << std::endl
		<< "--- Designed by Jexser" << std::endl
		<< "--- Game description here" << std::endl
		<< std::endl
		<< "Can you guess the " << WORD_LENGTH << " letters isogram that I guessed?" << std::endl;

	return 0;
}