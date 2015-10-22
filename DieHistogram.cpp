// DieHistogram.cpp : Defines the entry point for the console application.
// Daniel Burkholder - U74377338
// Obj Oriented Design Fall 2015 MW 9:30

#include "stdafx.h"
#include <iostream>
#include <istream>
#include "DieHelper.h"

using namespace std;

int main()
{
	cout << "Daniel Burkholder - U74377338" << endl << "Obj Oriented Design Fall 2015 MW 9:30" << endl;

	int numRolls = 0;
	int seed = 666;


	//Prompt for input, seed number
	cout << "Set a seed? (e.g. 3331; Default 666)" << endl;

	//Retrieve input from user -> seed
	cin >> seed;

	//Set the seed
	srand(seed);


	//Prompt for input, number of rolls
	cout << "How many rolls?" << endl;

	//Retrieve input from user -> numRolls
	cin >> numRolls;

	cout << "Rolling " << numRolls << endl;


	roll(numRolls, 1);
	roll(numRolls, 2);

	system("pause");
    return 0;
}

