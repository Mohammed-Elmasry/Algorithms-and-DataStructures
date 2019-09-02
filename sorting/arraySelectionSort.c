#include <stdio.h>
#include <stdlib.h>
#define SIZE 4


//prototypes
void printArray(int * array, unsigned int size);
void selectionSort(int * array, unsigned int size);
void swapIndex(int * array, unsigned int first, unsigned int second);


int main(int argc, char * argv[]){
	int arr[SIZE] = {1,3,2,4};
	puts("before sorting");
	printArray(arr, SIZE);
	selectionSort(arr, SIZE);
	puts("after sorting");
	printArray(arr, SIZE);
	return 0;
}

void selectionSort(int * array, unsigned int size){
	int min = 0;
	for (int i = 0; i < size; ++i){
		min = i;
		for(int j = i + 1; j < size; ++j){
			if(array[j] < array[main]){
				min = j;
			}
		}
		swapIndex(array, i, min);
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