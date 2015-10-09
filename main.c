//
//  main.c
//  triangleProblemBruteForce
//
//  Created by Randy Ram on 9/24/15.
//  Copyright (c) 2015 Randy Ram. All rights reserved.
//

#include <stdio.h>
#include "bruteforce.h"
#include "recursionExponential.h"
#include "recursionMemoization.h"


int main(int argc, const char * argv[]) {
    int numRows;
    //FILE* in  = fopen("/Users/randy/Developer/triangleProblemBruteForce/triangleProblemBruteForce/input.txt", "r");
    FILE* in = fopen("/Users/randy/Downloads/TriangleTestData/triangle6.in", "r");
    if (in == NULL)
    {
        printf("Could not open file");
        return -1;
    }
    fscanf(in, "%d", &numRows);  //First number is the number of rows
    int triangleArray[numRows + 1][numRows + 1];
    int k, i = 1, numsToReadIn = 1;
    while (numsToReadIn <= numRows) {
        int j = 1;
        for (k = 1; k <=numsToReadIn; k++) {
            fscanf(in, "%d", &triangleArray[i][j]);
            j++;
        }
        i++;
        numsToReadIn++;
    }
    fclose(in);
    
    //Test Brute Force Method
    //getBestPath(numRows - 1, numRows + 1, triangleArray);
    
    
    //Declare path array and set all values to -1
    int pathArray[numRows + 1][numRows +  1];
    int x, y;
    for (x = 1; x <= numRows; x++) {
        for (y = 1; y <= numRows; y++) {
            pathArray[x][y] = -1;
        }
    }
/*
    //--------Test Exponential Recursion method - Failed at triangle5 input
    printf("Best Sum: %d\n", recursivelyGetPath(numRows + 1, triangleArray, 1, 1, pathArray));
    printf("Path from Apex: ");
    for (x = 1; x <= numRows; x++) {
        for (y = 1; y <= numRows; y++) {
            printf("%d ", pathArray[x][y]);
        }
        printf("\n");
    }
    
    //Careful here. The actual size is of the the array is 6 x 6 which is one more than numRows since we index from 1.
    printPath(numRows + 1, pathArray);*/
    //----------------------
    
    
    //Test memoized recursion
    
    //Declare memoized array and set all values to -1
    int memoizedArray[numRows + 1][numRows + 1];
    for (x = 1; x <= numRows; x++) {
        for (y = 1; y <= numRows; y++) {
            memoizedArray[x][y] = -1;
        }
    }
    printf("Best Sum: %d\n", recursivelyMemoizedGetPath(numRows + 1, triangleArray, 1, 1, pathArray, memoizedArray));
    printMemoizedPath(numRows + 1, pathArray);
    return 0;
}
