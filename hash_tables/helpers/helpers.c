#include <stdio.h>
#include "helper_headers.h"
#include "../headers/structs/node.c"

const EMP = -2147483648;
const DEL = -2147483647;

void printArray(int * array, int size){
	for(int i = 0; i < size; ++i){
		printf("%d\n", array[i]);
	}
	printf("Display complete..\n");
}

void initializeArray(int * array, int size){
	for(int i = 0; i < size; ++i){
		array[i] = EMPTY;
	}
	printf("array initialized successfully!\n");
}