//
//  bruteforce.h
//  triangleProblemBruteForce
//
//  Created by Randy Ram on 9/24/15.
//  Copyright (c) 2015 Randy Ram. All rights reserved.
//

#ifndef __triangleProblemBruteForce__bruteforce__
#define __triangleProblemBruteForce__bruteforce__

#include <stdio.h>

//Function to calculate integer exponentiation
int ipow(int base, int exp);

void getBestPath(int numBits, int size, int triangle[][size]);

int sumOfPath(int size, int triangle[][size], int* bitArray, int bitArrayLength);

#endif /* defined(__triangleProblemBruteForce__bruteforce__) */
