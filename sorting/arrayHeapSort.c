#include <stdio.h>
#include "headers/arraySelectionSort.h"
//prototype
int parent(int index);
void heapify(int * array, int size);

int main(int argc, char * argv[]){
	int arr[8] = {15,22,3,18,4,8,77,9};
	printf("parent of zero is %d\n", parent(0));
	puts("before heapify...");
	printArray(arr, 8);
	
	heapify(arr, 8);

	puts("after heapify...");
	printArray(arr, 8);

	return 0;
}

void heapify(int * array, int size){
	int tempParent = 0;
	for (int i = size - 1; i > 0; --i){
		tempParent = parent(i);
		while(i != 0){
			if(array[tempParent] < array[i]){
				swapIndex(array, parent(i), i);
				i = tempParent;
				tempParent = parent(i);
			} else {
				break;
			}
		}
	}
}

int parent(int index){
	return (index-1)/2;
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