// Daniel Burkholder - U74377338
// Obj Oriented Design Fall 2015 MW 9:30

#ifndef DIEHELPER_H
#define DIEHELPER_H

#include <vector>
using namespace std;


void roll(unsigned int numRolls, int numDie = 1, int numSides = 6);
void displayHistogram(vector<unsigned int>& values, int numDie);
void displayCounts(vector<unsigned int>& values, int numDie);
void findLargest(vector<unsigned int>& values, int numDie);




#endif