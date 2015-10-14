//
//  bruteforce.c
//  triangleProblemBruteForce
//
//  Created by Randy Ram on 9/24/15.
//  Copyright (c) 2015 Randy Ram. All rights reserved.
//

#include "bruteforce.h"

//Integer exponentiation
int ipow(int base, int exp)
{
    int result = 1;
    while (exp)
    {
        if (exp & 1)
        {
            result *= base;
        }
        exp >>= 1;
        base *= base;
    }
    
    return result;
}

/*
 For each bit sequence from 0 to the max number, find the
 sum along that path.
 */
void getBestPath(int numBits, int size, int triangle[][size])
{
    int bitArray[numBits];  //Store each binary count in an array
    int bestPath[numBits];
    int bestSum = 0;
    int currentSum = 0;
    int maxNum = ipow(2, numBits);
    int i; int j;
    for (i = 0; i < maxNum; i++)
    {
        for (j = numBits; j > 0; j--)
        {
            // Get bit sequence and store it in a bit array.
            int currentBit =  (i/ipow(2, j - 1)) % 2;
            bitArray[j - 1] = currentBit;
        }
        currentSum = sumOfPath(size, triangle, bitArray, numBits);
        if (currentSum > bestSum) {
            bestSum = currentSum;
            int k;
            for (k = 0; k < numBits; k++)
            {
                bestPath[k] = bitArray[k];
            }
        }
    }
    
    //Print Best Sum and the Path
    printf("Best Sum: %d\n", bestSum);
    printf("Path from apex: ");
    int l;
    for (l = 0; l < numBits; l++) {
        if (bestPath[l] == 0) {
            printf("Left ");
        }
        else
        {
            printf("Right ");
        }
        //printf("%d ", bestPath[l]);
    }
}

int sumOfPath(int size, int triangle[][size], int* bitArray, int bitArrayLength)
{
    int i, j =1, k = 1;
    int sum = triangle[j][k];
    for (i = 0; i < bitArrayLength; i++)
    {
        if (bitArray[i] == 0)  //If bit array is 0, we go left, else go right
        {
            sum += triangle[j + 1][k];
            j++;
        }
        else
        {
            sum += triangle[j + 1][k + 1];
            j++;
            k++;
        }
    }
    return sum;
}