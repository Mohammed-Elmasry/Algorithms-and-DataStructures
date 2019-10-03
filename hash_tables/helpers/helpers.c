// #include "../headers/structs/node.c"
#include <stdio.h>
#include "helper_headers.h"
#include "constants.c"
// system-wide constants definitions

/**
 * [printArray print array]
 * @param array [array to print]
 * @param size  [size of array to print]
 */
void printArray(int * array, int size){
	for(int i = 0; i < size; ++i){
		printf("%d\n", array[i]);
	}
	printf("Display complete..\n");
}
/**
 * [initializeArray initialize all entries within an array to EMPTY value]
 * @param array [array to initialize]
 * @param size  [size of array]
 */
void initializeArray(int * array, int size){
	for(int i = 0; i < size; ++i){
		array[i] = EMP;
	}
	printf("array initialized successfully!\n");
}

void printNode(struct node n){
	printf("key is %d and value is %s\n", n.key, n.val);
}