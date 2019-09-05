#include <stdio.h>
#include "headers/arraySelectionSort.h"

//prototypes:
void bubbleSort(int * array, int size);


int main(int argc, char * argv[]){
	int arr[7] = {5,7,3,2,6,1,4};
	puts("before sorting...");
	printArray(arr, 7);

	bubbleSort(arr, 7);

	puts("after sorting...");
	printArray(arr, 7);

	return 0;
}


void bubbleSort(int * array, int size){
	int limit = 0;
	int bulk = size;
	while(bulk != 0){
		for(int i = 0; i < size - (limit + 1); ++i){
			if(array[i] > array[i+1]){
				swapIndex(array, i, i+1);
			}
		}
		limit++;
		bulk--;
	}
}

void swapIndex(int * array, unsigned int first, unsigned int second){
	int temp = array[second];
	array[second] = array[first];
	array[first] = temp;
}

void printArray(int * array, unsigned int size){
	for (int i =0; i < size; ++i){
		printf("%d\n", array[i]);
	}
	puts("display complete...");
}