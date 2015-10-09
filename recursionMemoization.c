//
//  recursionMemoization.c
//  triangleProblemBruteForce
//
//  Created by Randy Ram on 9/26/15.
//  Copyright (c) 2015 Randy Ram. All rights reserved.
//

#include "recursionMemoization.h"


int recursivelyMemoizedGetPath(int size, int triangle[][size], int row, int col, int pathArray[][size], int memoizedArray[][size])
{
    if (memoizedArray[row][col] != -1) {
        return memoizedArray[row][col];
    }
    if (row == size - 1) {
        //printf("Base Case: %d\n", triangle[row][col]);
        //printf("Row: %d, Col: %d\n", row, col);
        return triangle[row][col];
    }
    int left = recursivelyMemoizedGetPath(size, triangle, row + 1, col, pathArray, memoizedArray);
    int right = recursivelyMemoizedGetPath(size, triangle, row + 1, col + 1, pathArray, memoizedArray);
    if (left > right) {
        pathArray[row][col] = 0;
        return memoizedArray[row][col] = triangle[row][col] + left;
    }
    //printf("Row: %d, Col: %d\n", row, col);
    pathArray[row][col] = 1;
    return memoizedArray[row][col] = triangle[row][col] + right;
}

void printMemoizedPath(int size, int pathArray[][size])
{
    
    int i = 1, j = 1;
    while (i < size - 1) //We Stop one row for the end
    {
        if (pathArray[i][j] == 0)
        {   //Go Left!
            printf("Left ");
            i++;
        }
        else
        {
            printf("Right ");
            i++;
            j++;
        }
    }
}