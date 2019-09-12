#include <stdio.h>
#include "headers/arraySelectionSort.h"
#include "headers/arrayList.h"

//prototype
int parent(int index);
void heapify(int * array, int size);
void insert(int * array, int element, int size);
int removeTopItem(struct intArrayList * arrayList, unsigned int size);
void heapSort(struct intArrayList * list);


int main(int argc, char * argv[]){

	// int arr[6] = {7,2,5,10,9,3};
	int arr[7] = {2,5,9,7,10,3,8};
	struct intArrayList list;
	assignIntList(&list, arr, 7,7);
	puts("before anything...");
	printArrayList(list);
	puts("\n\n\n");

	heapify(list.arrayPtr, 7);

	heapSort(&list);
	puts("after heap sorting...");
	printArrayListElements(list);
	return 0;
}
/**
 * [heapify a given array (create a max heap out of it)]
 * @param array [array to heapify]
 * @param size  [size of array]
 */
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

/**
 * [returns the parent index of a given index]
 * @param  index [index of which parent is requested]
 * @return       [integer denoting parent requested]
 */
int parent(int index){
	return (index-1)/2;
}

/**
 * [swap 2 indexes of an array together]
 * @param array  [array with indexes to be swapped]
 * @param first  [first index arg]
 * @param second [second index arg]
 */
void swapIndex(int * array, unsigned int first, unsigned int second){
	int temp = array[second];
	array[second] = array[first];
	array[first] = temp;
}

/**
 * [prints out the array elements]
 * @param array [array to be printed]
 * @param size  [size of array]
 */
void printArray(int * array, unsigned int size){
	for (int i =0; i < size; ++i){
		printf("%d\n", array[i]);
	}
	puts("display complete...");
}

/**
 * [heapify the tree starting from the last element and then stop]
 * @param array [array to heapify]
 * @param size  [size of array]
 */
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

/**
 * [inserts an element into an array with heapify_once in action]
 * @param array   [array to insert element into]
 * @param element [element to be inserted]
 * @param size    [size of the array]
 */
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

/**
 * [removes top item from the given arrayList]
 * @param  arrayList [pointer to intArrayList structure]
 * @param  size      [size of the given arrayList]
 * @return           [the top item]
 */
int removeTopItem(struct intArrayList * arrayList, unsigned int size){
	int retval = -1;
	if(arrayList->arrayPtr){ //there is a tree to begin with
		retval = arrayList->arrayPtr[0];
		removeFromArrayList(arrayList,0);		
		insertIntoArrayList(arrayList, 0, pop(arrayList));
		heapify(arrayList->arrayPtr, size);
	}
	return retval;
}

void heapSort(struct intArrayList * list){
	for(int size = list->count - 1; size > 0; --size){
		swapIndex(list->arrayPtr, 0, size);
		heapify(list->arrayPtr, size);
	}

}