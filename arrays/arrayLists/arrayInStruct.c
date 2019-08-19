#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

struct intArrayList {
	int * arrayPtr;
	int length;
	int count;
};

//prototypes
int assignIntList(struct intArrayList * list, int * array, int arraySize);
void printArrayList(struct intArrayList list);
int appendIntArrayList(struct intArrayList * list, int value);
void printArrayListElements(struct intArrayList list);


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
int assignIntList(struct intArrayList * list, int * array, int arraySize, int arrayElementCount){
	int retval = 0;
	list->arrayPtr = (int *) malloc(arraySize * sizeof(int));
	if(list->arrayPtr){
		memcpy(list->arrayPtr,array,sizeof(int) * arraySize);
		list->length = arraySize;
		list->count = arrayElementCount;
		retval = 1;
	} else {
		strerror(ENOMEM);
		retval = errno;
	}
	return retval;
}

void printArrayList(struct intArrayList list){
	for (int i = 0; i < list.length; ++i){	
		printf("%d ", list.arrayPtr[i]);
	}
	puts("display complete..");
	printf("length of arrayList is: %d\n", list.length);
}

void printArrayListElements(struct intArrayList list){
	for(int i = 0; i < list.count;++i){
		printf("%d ", list.arrayPtr[i]);
	}
	puts("display complete...");
	printf("count of elements is: %d\n", list.count);
}

int appendIntArrayList(struct intArrayList * list, int value){
	int retval = 0;
	if(list != NULL){ // list is empty
		int old_length = list->length;
		// free(list->arrayPtr);
		// free(list->arrayPtr);
		int * temp = (int *) malloc(sizeof(int) * list->length * 2);
		if(temp != NULL){
			puts("Debug appendIntArrayList memory allocation done(1)");
			memcpy(temp, list->arrayPtr, (sizeof(int) * list->length));
			temp[list->length] = value;
			free(list->arrayPtr);
			list->arrayPtr = temp;
			list->length = old_length * 2;
			retval = 1;
		} else {
			strerror(ENOMEM);
			retval = errno;
		}
	}
	return retval;
}