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
#include "sp_nim.h"
#define user 1
#define computer -1

void printWinner(int player){
	if(player == user){
		printf("Computer wins!\n");
	}
	else if(player == computer){
		printf("You win!\n");
	}
	else{
		printf("ERROR, PLAYER!=1/-1");
	}
}

int isGameOver(int* heapSizesArr, int numberOfHeaps, int player){
	bool over = true;
	int i;
	for(i=0; i<numberOfHeaps; i++){
		if(heapSizesArr[i]!=0){
			over = false;
		}
	}
	if(over){
		printWinner(player);
		return 1;
	}
	else{
		return 0;
	}
}

void computerTurn(int* heapSizesArr, int numberOfHeaps){
	int NimSum = heapSizesArr[0];
	int numOfobj;
	int winnerIndex = -1;
	int i;
	for(i=1; i<numberOfHeaps; i++){
		NimSum ^= heapSizesArr[i];
	}
	if(NimSum!=0){		
		for(i=0; i<numberOfHeaps; i++){
			if((NimSum^heapSizesArr[i]) < heapSizesArr[i]){
				numOfobj = heapSizesArr[i] - (NimSum^heapSizesArr[i]);
				winnerIndex = i+1;
				heapSizesArr[i] = (NimSum^heapSizesArr[i]);	/*i is the winner heap*/
				break;
			}
		}		
	}
	else{
		for(i=0; i<numberOfHeaps; i++){
			if(heapSizesArr[i]>0){
				numOfobj = 1;
				winnerIndex = i+1;
				heapSizesArr[i] -= 1;
				break;
			}
		}
	}	
	printf("Computer takes %d objects from heap %d.\n", numOfobj, winnerIndex);
}

int isLegal(int* heapSizesArr, int numberOfHeaps, int heapIndex,int numOfRemovedObj){
	if(heapIndex-1 < 0 || heapIndex > numberOfHeaps){
		return 0;
	}
	if(heapSizesArr[heapIndex-1] < numOfRemovedObj){
		return 0;
	}
	if(numOfRemovedObj<=0){
		return 0;
	}
	return 1;
}

int userTurn(int* heapSizesArr, int numberOfHeaps){
	int heapIndex;
	int numOfRemovedObj;
	
	printf("Your turn: please enter the heap index and the number of removed objects:\n");
	do{
		if((scanf("%d", &heapIndex)<=0)||(scanf("%d", &numOfRemovedObj)<=0)){
			if(feof(stdin)){ return -1;}
			else{
				printf("Error: invalid input.\n");
				return -1;
			}
		}
		if(!isLegal(heapSizesArr, numberOfHeaps, heapIndex,numOfRemovedObj)){
			printf("ERROR: Invalid input.\nPlease enter again the heap index and the number of removed objects:\n");
		}
	} while(!isLegal(heapSizesArr, numberOfHeaps, heapIndex,numOfRemovedObj));
	
	printf("You take %d objects from heap %d.\n", numOfRemovedObj, heapIndex);
	heapSizesArr[heapIndex-1] -= numOfRemovedObj;
	return 1;
}