//
//  recursionExponential.h
//  triangleProblemBruteForce
//
//  Created by Randy Ram on 9/24/15.
//  Copyright (c) 2015 Randy Ram. All rights reserved.
//

#ifndef __triangleProblemBruteForce__recursionExponential__
#define __triangleProblemBruteForce__recursionExponential__

#include <stdio.h>

int recursivelyGetPath(int size, int triangle[][size], int row, int col, int pathArray[][size]);
void printPath(int size, int pathArray[][size]);

#endif /* defined(__triangleProblemBruteForce__recursionExponential__) */
