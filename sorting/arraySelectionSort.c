#include <stdio.h>
#include <stdlib.h>
#define SIZE 4


//prototypes
void printArray(int * array, unsigned int size);
void selectionSort(int * array, unsigned int size);
void swapIndex(int * array, unsigned int first, unsigned int second);


int main(int argc, char * argv[]){
	int arr[SIZE] = {1,2,3,4};
	puts("before swap");
	printArray(arr, SIZE);
	swapIndex(arr, 0, 3);
	puts("after swap");
	printArray(arr, SIZE);
	return 0;
}

void selectionSort(int * array, unsigned int size){
	int limit = 0;
	int max = 0;
	int last = 0;
	for (int i = 0; i < size - limit; i++){
		max = array[i];
		for(int j = i + 1; j < size - limit; j++){
			if(array[max] < array[j]){
				max = j;
				last = j;
			}
		}
		swapIndex(array, max, last);
		limit++;
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