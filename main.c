#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "SPBufferset.h"
#include "main_aux.h"
#include "sp_nim.h"
#define user 1
#define computer -1

int main(){
	int numberOfHeaps;
	int* heapSizesArr;
	int player = user;			 /* player =-1 means computer's turn, =1 means user's turn */
	int turn = 1;
	SP_BUFF_SET();

	printf("Enter the number of heaps:\n");
	
	if((scanf("%d", &numberOfHeaps)<=0)){
		if(feof(stdin)){ return -1;}
		else{
			printf("Error: the number of heaps must be between 1 and 32.\n");
			return -1;	
		}			
	}
	if(numberOfHeaps<1||numberOfHeaps>32){
		printf("Error: the number of heaps must be between 1 and 32.\n");
			return -1;
	}
	
	heapSizesArr = malloc(numberOfHeaps*sizeof(int));
	printf("Enter the heap sizes:\n");
	if(enterHeapSizes(heapSizesArr, numberOfHeaps)<=0){
		free(heapSizesArr);
		return -1;
	}
					
	while(!isGameOver(heapSizesArr, numberOfHeaps, player)){
		
		printHeaps(heapSizesArr, numberOfHeaps, turn);
		
		if(player == user){
			if(userTurn(heapSizesArr, numberOfHeaps)<0){
				free(heapSizesArr);
				return -1;
			}
		}
		else if(player == computer){
			computerTurn(heapSizesArr, numberOfHeaps);
		}
		else{
			printf("ERROR, PLAYER != 1/-1");
		}
				
		turn++;
		player *= -1; /*switch player*/
	}	
	free(heapSizesArr);
	return 1;
}

