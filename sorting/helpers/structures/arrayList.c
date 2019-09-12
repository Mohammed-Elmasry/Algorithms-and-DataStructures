#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct arrayList{
	int * array;
}typedef ArrayList;

// prototypes
void printList(int list[], long unsigned int size);
int length(int array[], long unsigned int size);
int * expandByOne(int array[], long unsigned int size, int element);
int * reduceByOne(int array[], long unsigned int size, int index);

/** adds a new element to the arrayList
    returns an integer denoting success or failure of insertion operation*/
int * expandByOne(int array[], long unsigned int size, int element){
	int length = size / sizeof(int);
	int * ptr = (int *) malloc(size + sizeof(int));
	memcpy(ptr, array, size);

	ptr[length] = element;
	return ptr;
}
/** prints a display of the given array based on provided size in integer */
void printList(int list[], long unsigned int size){
	for(int i = 0; i < size; ++i){
		printf("%d\n", list[i]);
	}
}
/** returns the length of a given array based on its size in bits */
int length(int array[], long unsigned int size){
	int result = size / sizeof(int);
	printf("result is %d\n", result);
	return result;
}
/** [removes a certain element at the given index and handles the size of resulting array]
	[returns a pointer to the newly created structure] */
int * reduceByOne(int array[], long unsigned int size, int index){
	
	int * newArray = (int *)malloc(size - sizeof(int));
	int length1 = size / sizeof(int);
	int length2 = length1 - 1;
	int index1 = 0;
	int index2 = 0;
	while(index1 < length1 && index2 < length2){
		if(index1 != index){
			newArray[index2] = array[index1];
			index1++;
			index2++;
		} else {
			index1++;
		}
	}
	return newArray;
}