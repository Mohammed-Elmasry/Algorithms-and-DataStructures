#include <stdio.h>
#include "headers/linked_lists.h"
#include "hash.h"

//prototypes

int main(int argc, char * argv[]){
	struct node * arr[10];
	puts("before initializeHash...");
	printArray(arr, 10);
	puts("\n\n\n");
	puts("after initializeHash...");
	initializeHash(arr, 10);
	printArray(arr, 10);

	return 0;
}
/**
 * [hash a value to map it to a bucket in hash table]
 * @param  input [value to hash]
 * @param  len   [length of hash into]
 * @return       [hash key]
 */
int hash(unsigned int input, int len){
	int retval = 0;
	retval = input % len;
	return retval;
}

/**
 * [insertPair inserts key values into hash table]
 * @param  array [array to insert into]
 * @param  value [value to insert]
 * @param  size  [size to hash unto]
 * @return       [integer denoting result of insertion process]
 */
int insertPair(int * array, int value, int size){
	int retval = 0;
	int key = hash(value, size);
	if(array[key] == 0){
 		struct node * temp = allocateNode(value);
		if(temp){
			array[key] = *temp;
			retval = 1;
		}
	} else {
		append(&(array[key].pNext), value);	
	}
	return retval;
	
}

void printArray(struct node * array, int size){
	for (int i = 0; i < size; ++i){
		printf("%p\n", array[i]);
	}
	puts("display complete..");
}

void initializeHash(int * array, int size){
	for (int i = 0; i < size; ++i){
		array[i] = NULL;
	}
}