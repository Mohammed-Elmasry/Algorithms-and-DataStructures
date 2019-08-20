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
int assignIntList(struct intArrayList * list, int * array, int arraySize, int arrayElementCount);
void printArrayList(struct intArrayList list);
int appendIntArrayList(struct intArrayList * list, int value);
void printArrayListElements(struct intArrayList list);
int * expandAndCopy(struct intArrayList list);
void swapRight(struct intArrayList * list, int index);
int insertIntoArrayList(struct intArrayList * list, unsigned int index, int value);


int main(void){
	int array[3] = {1,5,6};
	struct intArrayList list;	
	long unsigned int size = sizeof(array) / sizeof(int);
	
	assignIntList(&list, array, size, size);
	puts("before insertion...");
	printArrayList(list);

	insertIntoArrayList(&list, 0, 51);
	
	puts("after insertion");
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
	if(list != NULL){ // list is not empty
		if(list->count < list->length){ // there is still space
			list->arrayPtr[list->count] = value;
			list->count++;
		} else {
			int old_length = list->length;
			int old_count = list->count;
			int * temp = expandAndCopy(*list);
			temp[list->length] = value;
			free(list->arrayPtr);
			list->arrayPtr = temp;
			list->length = old_length * 2;
			list->count = ++old_count;
			retval = 1;
		}
	}
	return retval;
}

int * expandAndCopy(struct intArrayList list){
	int * temp = (int *) malloc(sizeof(int) * list.length * 2);
	if(temp != NULL){
		puts("Debug expandAndCopy memory allocation done(1)");
		memcpy(temp, list.arrayPtr, (sizeof(int) * list.length));
	} else {
		strerror(ENOMEM);
		return NULL;
	}	
	return temp;
}


//* note that this can increase the count of a list.
void swapRight(struct intArrayList * list, int index){
	puts("ATTENTION::....swap function fired");
	int i = list->length - 2;
	printf("current i is : %d\n", i);
	for (; i > index-1; --i){
		printf("current i is : %d\n", i);
		list->arrayPtr[i+1] = list->arrayPtr[i];
	}
	printf("current i is : %d\n", i);
}

int insertIntoArrayList(struct intArrayList * list, unsigned int index, int value){
	int retval = 0;
	if(list != NULL){
		if(list->count < list->length){
			swapRight(list, index);
			list->arrayPtr[index] = value;
			list->count++;
		} else {
			int * temp;
			int old_length = list->length;
			int old_count = list->count;
			temp = expandAndCopy(*list);
			list->length = old_length * 2;
			free(list->arrayPtr);
			list->arrayPtr = temp;
			puts("entering swapRight() function");
			swapRight(list, index);
			list->arrayPtr[index] = value;	
			list->count = ++old_count;
			retval = 1;
		}
	}
	return retval;
}