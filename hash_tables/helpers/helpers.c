#include <stdio.h>
#include "helper_headers.h"

void printArray(int * array, int size){
	for(int i = 0; i < size; ++i){
		printf("%d\n", array[i]);
	}
	printf("Display complete..");
}
