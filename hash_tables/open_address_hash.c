#include <stdio.h>
#include "helpers/helper_headers.h"

int main(int argc, char * argv[]){
	int arr[10];
	printArray(arr, 10); 
	return 0;
}

//function definitions

int hash(int key, int size){
	return key % size;
}

