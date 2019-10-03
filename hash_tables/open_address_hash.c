#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "helpers/helper_headers.h"
// #include "helpers/constants.c"

int main(int argc, char * argv[]){
	int arr[100];
	puts("before initialization");
	printArray(arr, 10);
	
	puts("\n\n\n\nafter initialization");
	initializeArray(arr, 10);
	printArray(arr, 10); 
	
	
	return 0;
}

//function definitions

int hash(int key, int size){
	return key % size;
}

int insert(int * array, int item, int size){
	int add = 1;
	int pos = hash(item, size);

	while(array[pos + (int)pow(add,2)] != EMP && pos + (int)pow(add,2) <= size){
		add++;	
	}
	array[pos + (int)pow(add,2)] = item;
}