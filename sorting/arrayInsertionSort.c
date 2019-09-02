#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

//prototypes
void printArray(int * array, unsigned int size);
void swapRight(int * array, int index, int count);
void insertionSort(int * array, unsigned int size);


int main(int argc, char * argv[]){
	int arr[SIZE] = {2,3,8,6,1,5};
	puts("before swap...");
	printArray(arr, SIZE);
	insertionSort(arr, SIZE);
	puts("after swap...");
	printArray(arr, SIZE);
	return 0;
}

void insertionSort(int * array, unsigned int size){
	int temp = 0;
	for(int i = 1; i < size; ++i){
		for(int j = 0; j < i; ++j){
			if(array[i] <= array[j]){
				temp = array[i];
				swapRight(array, i, i-j);
				array[j] = temp;
			}
		}
	}	
}

void swapRight(int * array, int index, int count){
	while(count != 0){
		array[index] = array[index-1];
		index--;
		count--;
	}
}

void printArray(int * array, unsigned int size){
	for (int i =0; i < size; ++i){
		printf("%d\n", array[i]);
	}
	puts("display complete...");
}