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
int * reduceByOne(int array[], long unsigned int size, int index);

int main(void){
	int array[] = {1,2,4,6,2};
	// length(array, sizeof(array));
	
	int * newArray;
	newArray = array;
	printf("%lu\n", sizeof(*newArray));
	// newArray = reduceByOne(array, sizeof(array), 3);
	// newArray = expandByOne(array, sizeof(array), 19);
	// printf("size is %lu\n",sizeof(newArray));
	// for (int i = 0; i < 4; ++i){
		// printf("element number %d is %d\n", i+1, newArray[i]);
	// }
	// puts("display complete...");
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