#include <stdio.h>
#include "headers/linked_lists.h"
#include "hash.h"

//prototypes

int main(int argc, char * argv[]){
	struct node * arr[10];
	initializeHash(arr, 10);
	insertPair(arr, 6132654, "Name", 10);
	puts("before delete...");
	printArray(arr, 10);
	puts("\n\n\n");
	puts("after delete...");
	delete(&arr[4], 6132654);
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
int insertPair(struct node * array[], int key, char * value, int size){
	int retval = 0;
	int bucket = hash(key, size);
	if(array[bucket] == NULL){
 		struct node * temp = allocateNode(key, value);
		if(temp){
			temp->key = key;
			temp->val = value;
			array[bucket] = temp;
			retval = 1;
		}
	} else {
		orderedInsert(&(array[bucket]->pNext), key, value);	
	}
	return retval;
	
}

void printArray(struct node * array[], int size){
	for (int i = 0; i < size; ++i){
		printf("%p\n", array[i]);
	}
	puts("display complete..");
}

void initializeHash(struct node * array[], int size){
	for (int i = 0; i < size; ++i){
		array[i] = NULL;
	}
}