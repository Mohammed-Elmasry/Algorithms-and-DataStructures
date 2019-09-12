#include <stdio.h>
#include "headers/arraySelectionSort.h"
#include "headers/arrayList.h"

//prototype
int parent(int index);
void heapify(int * array, int size);
void insert(int * array, int element, int size);
int removeTopItem(int * array, unsigned int size);


int main(int argc, char * argv[]){

	int arr[6] = {7,2,5,10,9,3};

	// struct intArrayList list;
	// assignIntList(&list, arr, 6,6);
	puts("before anything...");
	// printArrayList(list);
	printArray(arr, 6);
	puts("\n\n\n");

	puts("after heapify....");
	heapify(arr, 6);
	printArray(arr, 6);
	// puts("after removal of top item...");
	// removeTopItem(list, 6);
	// printArrayList(list,6);
	return 0;
}

void heapify(int * array, int size){
	int tempParent = 0;
	int old_i = 0;
	for (int i = size - 1; i > 0; --i){
		old_i = i;
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
		i = old_i;
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

int removeTopItem(int * array, unsigned int size){
	int retval = -1;
	if(array){ //there is a tree to begin with
		retval = array[0];
		array[0] = array[size - 1];	
		heapify(array, size);
		array[size-1] = -1; 
	}
	return retval;
}