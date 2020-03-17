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
#include "main_aux.h"


int enterHeapSizes(int* heapSizesArr, int numberOfHeaps){
	int i;
	for(i=0; i<numberOfHeaps; i++){
		if(scanf("%d", &heapSizesArr[i])<=0){
			if(feof(stdin)){ return -1;}
			else{
				printf("Error: the size of heap %d should be positive.\n", i+1);
				return -1;
			}
		}

		if(heapSizesArr[i]<=0){
			printf("Error: the size of heap %d should be positive.\n", i+1);
			return -1;
		}
	}
	return 1;
}

void printHeaps(int* heapSizesArr, int numberOfHeaps, int turn){
	int i;
	printf("In turn %d heap sizes are:", turn);
	for(i=0; i<numberOfHeaps; i++){
		printf(" h%d=%d", i+1, heapSizesArr[i]);
	}
	printf(".\n");
}
