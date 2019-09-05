#include <stdio.h>
#include "headers/arraySelectionSort.h"
//prototype
int parent(int index);
void heapify(int * array, int size);
void insert(int * array, int element, int size);


int main(int argc, char * argv[]){
	int arr[8] = {15,22,3,18,4,8,77,9};
	int array[8];

	insert(array, 15, 8);
	insert(array, 22, 8);
	insert(array, 3, 8);
	insert(array, 18, 8);
	insert(array, 4, 8);
	insert(array, 8, 8);
	insert(array, 77, 8);
	insert(array, 9, 8);

	puts("heap made on insertion...");
	printArray(array, 8);

	puts("heap made from an array...");
	heapify(arr, 8);
	printArray(arr,8);
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

void heapify_once(int * array, int size){
	int i = size;
	int tempParent = parent(i);
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

void insert(int * array, int element, int size){
	static int count = 0;
	if(count < size){
		array[count] = element;
		//heapify logic...
		heapify_once(array, count);
		count++;
	} else {
		puts("array out of bound!");
	}
}