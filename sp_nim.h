/*
 * main.c
 *
 *  Created on: Ap 20, 2019
 *      Author: ozgra
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "SPBufferset.h"
typedef int bool;
#define true 1
#define false 0
#define user 1
#define computer -1

void printWinner(int player);

int isGameOver(int* heapSizesArr, int numberOfHeaps, int player);

void computerTurn(int* heapSizesArr, int numberOfHeaps);

int isLegal(int* heapSizesArr, int numberOfHeaps, int heapIndex,int numOfRemovedObj);

int userTurn(int* heapSizesArr, int numberOfHeaps);
