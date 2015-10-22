// Daniel Burkholder - U74377338
// Obj Oriented Design Fall 2015 MW 9:30
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <math.h>
#include "DieHelper.h"


using namespace std;


//Function is capable of rolling any number of die of any number of sides
//E.g. roll 6 D20s 100 times
//Default 1 die, 6 sides
void roll(unsigned int numRolls, int numDie, int numSides) {
	//Rolls a number of given die (default 1 die) a given number of times 
	//and tallys the number of outcome occurances
	int temp;
	int possibleOutcomes = numSides * numDie;
	int numElements = (possibleOutcomes + 1);

	
	
	cout << "Rolling " << numDie << " " << numSides << "-sided die " << numRolls << " times." << endl;
	//Vector with (possibleOutcomes + 1) elements 
	vector<unsigned int> values (numElements);


	for (unsigned int i = 0; i < numRolls; i++) {
		/*	
			Roll the random number, the random number is the element in the vector.
			Add + 1 to the value at that element of the vector
		*/
		//Reset temp
		temp = 0;

		for (int j = 0; j < numDie; j++) {
			temp = temp + ( (rand() % numSides) + 1 ); 
	
		}

		//Tally occurance of outcome 
		values.at(temp) = values.at(temp) + 1;


	}


	//show counts of each occurance
	displayCounts(values, numDie);

	//Display the Histogram
	displayHistogram(values, numDie);

}


void displayHistogram(vector<unsigned int>& values, int numDie) {
	float maxX = 60;

	//Find outcome with most occurance
	findLargest(values, numDie);

	//Display the histogram
	for (int i = numDie; i < values.size(); i++) {
		//Formula: (Current Value / Largest Value) ( Max # of Xs ) = Number of Xs to display
		// floor(float) to always round down. to avoid e.g. 59 getting 60 Xs
		float percentage = ((float)values.at(i) / (float)values.at(0));
		float displayX = floor(percentage * maxX);


		//Print out 
		//[Number] [Number of Xs]	e.g. 1 XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
		cout << i << " ";
		for (int j = 0; j < displayX; j++) {
			cout << "X";
		}
		cout << endl;

	}

	cout << endl;
}

void findLargest(vector<unsigned int>& values, int numDie) {
	//Find the largest valued element
	for (int i = numDie; i < values.size(); i++) {
		//Element at 0 is Largest Value in the vector

		//If current value at i is greater than the largest value at 0
		//Set largest value at 0 to the value at i
		//Else don't change the value at 0
		values.at(0) = ( values.at(i) > values.at(0) ) ? ( values.at(i) ) : (values.at(0));

		//If current value at i is greater than the largest value at 0
		//Reset the for loop to numDie to reiterate through the vector.
		//(Set i to (numDie - 1) because the for loop will add  +1 at the end of the loop; reset loop
		i = ( values.at(i) > values.at(0) ) ? (i = (numDie - 1)): ( i );

		
	}

}



void displayCounts(vector<unsigned int>& values, int numDie) {

	//Print out update results from the vector
	//Start i = numDie because minimum possible outcoem is numDie. E.g. if 2 die, 1 is not possible outcome
	//e.g. [Value] ----- [Count]
	for (int i = numDie; i < values.size(); i++) {
		cout << i << " ----- " << values.at(i) << endl;

	}

}



