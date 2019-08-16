#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct arrayList{
// 	int * array;
// }typedef ArrayList;

// prototypes
// int * expandByOne(int array[], long unsigned int size, long unsigned int size, int element);
void printList(int list[], long unsigned int size);
int length(int array[], long unsigned int size);


int main(void){
	int array[5] = {1,2,4,6,2};
	int result = length(array, sizeof(array));
	printf("result is %d\n", result);
	// long unsigned int size = sizeof(array);
	// printList(array, 5);
	// expandByOne(array, size, 19);
	// long unsigned int length = size / sizeof(int);
	// puts("after expansion: ");
	// printList(array, 7);
	// int * newArray; 
	// expandByOne(array, length, 19);
	// printf("%d\n", newArray[0]);
	// puts("display complete...");
	return 0;
}

// int * expandByOne(int array[], int length, long unsigned int size, int element){
// 	int length = size / sizeof(int);
// 	int * ptr = (int *) malloc(sizeof(int) * (length + 1));
// 	memcpy(ptr, array, size);

// 	ptr[length+1] = element;
// 	return ptr;
// }

void printList(int list[], long unsigned int size){
	for(int i = 0; i < size; ++i){
		printf("%d\n", list[i]);
	}
}

int length(int array[], long unsigned int size){
	return size / sizeof(int);
}