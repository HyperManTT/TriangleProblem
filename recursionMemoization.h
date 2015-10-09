//
//  recursionMemoization.h
//  triangleProblemBruteForce
//
//  Created by Randy Ram on 9/26/15.
//  Copyright (c) 2015 Randy Ram. All rights reserved.
//

#ifndef __triangleProblemBruteForce__recursionMemoization__
#define __triangleProblemBruteForce__recursionMemoization__

#include <stdio.h>

int recursivelyMemoizedGetPath(int size, int triangle[][size], int row, int col, int pathArray[][size], int memoizedArray[][size]);
void printMemoizedPath(int size, int pathArray[][size]);

#endif /* defined(__triangleProblemBruteForce__recursionMemoization__) */
