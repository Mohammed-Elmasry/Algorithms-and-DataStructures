#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arrayList{
	int * array;
}typedef ArrayList;

// prototypes
void printList(ArrayList list, long unsigned int size);
void expandByOne(ArrayList *list, long unsigned int size, int element);


int main(void){
	ArrayList list; 
	int array[5] = {1,3,5,2,6};
	list.array = array;

	// expandByOne(&list, 4);
	expandByOne(&list, 5, 19);
	
	long unsigned int size = sizeof(list.array);
	printf("size of arrayList is %lu\n", size);
	printList(list, 5);
	return 0;
}

void expandByOne(ArrayList *list, long unsigned int size, int element){
	int * ptr = (int *) malloc(sizeof(int) * (size + 1));
	memcpy(ptr, list->array, size);

	ptr[size+1] = element;
	list->array = ptr;
}

void printList(ArrayList list, long unsigned int size){
	for(int i = 0; i < size; ++i){
		printf("%d\n", list.array[i]);
	}
}