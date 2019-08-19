#include <stdio.h>
#include <stdlib.h>

struct intArrayList {
	int * arrayPtr;
	int length;
};

//prototypes
void assignIntList(struct intArrayList * list, int * array, int arraySize);

int main(void){
	int array[5] = {1,5,6,9,11};
	struct intArrayList list;	
	list.arrayPtr = array;
	long unsigned int size = sizeof(array) / sizeof(int);
	puts("before assignment...");
	printf("%d\n", list.length);

	assignIntList(&list, array, size);
	puts("after assignment...");
	printf("%d\n", list.length);
	return 0;
}

void assignIntList(struct intArrayList * list, int * array, int arraySize){
	list->arrayPtr = array;
	list->length = arraySize;
}

// void printArrayList(struct intArrayList list){
// 	printf("%p\n", intArrayList.arrayPtr);
// 	printf("%d\n", intArrayList.length);
// }