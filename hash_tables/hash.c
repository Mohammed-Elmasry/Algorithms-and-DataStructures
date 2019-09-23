#include <stdio.h>
#include "headers/linked_lists.h"
#include "hash.h"

//prototypes

int main(int argc, char * argv[]){
	int arr[10] = {};
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
// int insertPair(int * array, int value, int size){
// 	int key = hash(value, size);
// 	if(array[key])
// }

void printArray(int * array, int size){
	for (int i = 0; i < size; ++i){
		printf("%d\n", array[i]);
	}
	puts("display complete..");
}

void initializeHash(int * array){
	array = {};
}