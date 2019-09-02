#include <stdio.h>
#include <stdlib.h>


//prototypes
void printArray(int * array, unsigned int size);
void swapRight(int * array, int index, int count);
void insertionSort(int * array, unsigned int size);


int main(int argc, char * argv[]){
	int arr[5] = {2,5,3,4,1};
	printf("%d\n", arr[3]);
	puts("before swap...");
	printArray(arr, 5);
	swapRight(arr, 2, 2);
	arr[0] = 1;
	puts("after swap...");
	printArray(arr, 5);
	return 0;
}

void insertionSort(int * array, unsigned int size){
	for(int i = 1; i < size; ++i){
		for(int j = 0; j < i; --j){
			if(array[i] < array[j]){

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