//
//  recursionExponential.c
//  triangleProblemBruteForce
//
//  Created by Randy Ram on 9/24/15.
//  Copyright (c) 2015 Randy Ram. All rights reserved.
//

#include "recursionExponential.h"

int recursivelyGetPath(int size, int triangle[][size], int row, int col, int pathArray[][size])
{
    if (row == size - 1) {
        //printf("Base Case: %d\n", triangle[row][col]);
        //printf("Row: %d, Col: %d\n", row, col);
        return triangle[row][col];
    }
    int left = recursivelyGetPath(size, triangle, row + 1, col, pathArray);
    int right = recursivelyGetPath(size, triangle, row + 1, col + 1, pathArray);
    if (left > right) {
        pathArray[row][col] = 0;
        return triangle[row][col] + left;
    }
    //printf("Row: %d, Col: %d\n", row, col);
    pathArray[row][col] = 1;
    return triangle[row][col] + right;
}

void printPath(int size, int pathArray[][size])
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