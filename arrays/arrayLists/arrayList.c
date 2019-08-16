#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct arrayList{
// 	int * array;
// }typedef ArrayList;

// prototypes
void printList(int list[], long unsigned int size);
int length(int array[], long unsigned int size);
int * expandByOne(int array[], long unsigned int size, int element);


int main(void){
	int array[] = {1,2,4,6,2};
	// length(array, sizeof(array));
	
	int * newArray;
	newArray = expandByOne(array, sizeof(array), 19);
	printf("size is %lu\n",sizeof(newArray));
	for (int i = 0; i < 6; ++i){
		printf("element number %d is %d\n", i+1, newArray[i]);
	}
	puts("display complete...");
	return 0;
}

int * expandByOne(int array[], long unsigned int size, int element){
	int length = size / sizeof(int);
	int * ptr = (int *) malloc(size + sizeof(int));
	memcpy(ptr, array, size);

	ptr[length] = element;
	return ptr;
}

void printList(int list[], long unsigned int size){
	for(int i = 0; i < size; ++i){
		printf("%d\n", list[i]);
	}
}

int length(int array[], long unsigned int size){
	int result = size / sizeof(int);
	printf("result is %d\n", result);
	return result;
}