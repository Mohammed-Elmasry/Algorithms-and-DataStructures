#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

struct intArrayList {
	int * arrayPtr;
	int length;
};

//prototypes
void assignIntList(struct intArrayList * list, int * array, int arraySize);
void printArrayList(struct intArrayList list);
int appendIntArrayList(struct intArrayList * list, int value);


int main(void){
	int array[5] = {1,5,6,9,11};
	struct intArrayList list;	
	list.arrayPtr = array;
	long unsigned int size = sizeof(array) / sizeof(int);
	puts("before assignment...");
	printf("%d\n", list.length);

	assignIntList(&list, array, size);
	puts("after assignment...");
	printArrayList(list);
	printf("\n\n\n");
	puts("THEN....");

	appendIntArrayList(&list, 19);
	printArrayList(list);
	printf("\n\n\n\n");
	puts("AND....");
	appendIntArrayList(&list, 19);
	printArrayList(list);
	return 0;
}

void assignIntList(struct intArrayList * list, int * array, int arraySize){
	list->arrayPtr = array;
	list->length = arraySize;
}

void printArrayList(struct intArrayList list){
	for (int i = 0; i < list.length; ++i){	
		printf("%d ", list.arrayPtr[i]);
	}
	puts("display complete..");
	printf("length of arrayList is: %d\n", list.length);
}

int appendIntArrayList(struct intArrayList * list, int value){
	int retval = 0;
	if(list != NULL){ // list is empty
		int * temp = list->arrayPtr;
		int old_length = list->length;
		// free(list->arrayPtr);
		list->arrayPtr = (int *) malloc(sizeof(int) * list->length * 2);
		if(list->arrayPtr != NULL){
			puts("Debug appendIntArrayList memory allocation done(1)");
			memcpy(list->arrayPtr, temp, (sizeof(int) * list->length));
			list->arrayPtr[list->length] = value;
			list->length = old_length * 2;
			retval = 1;
		} else {
			strerror(ENOMEM);
			retval = errno;
		}
	}
	return retval;
}