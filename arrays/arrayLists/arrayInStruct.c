#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

struct intArrayList {
	int * arrayPtr; //array pointer
	int length; //taken memory size (regardless of number of elements)
	int count; //number of elements
};

//prototypes
int assignIntList(struct intArrayList * list, int * array, int arraySize, int arrayElementCount);
void printArrayList(struct intArrayList list);
int appendIntArrayList(struct intArrayList * list, int value);
void printArrayListElements(struct intArrayList list);
int * expandAndCopy(struct intArrayList list);
void swapRight(struct intArrayList * list, int index);
int insertIntoArrayList(struct intArrayList * list, unsigned int index, int value);
int * contractAndCopy(struct intArrayList list);
int pop(struct intArrayList * list);
void swapLeft(struct intArrayList * list, int index);
int removeFromArrayList(struct intArrayList * list, unsigned int index);


int main(void){
	int array[4] = {1,5,6,11};
	struct intArrayList list;	
	long unsigned int size = sizeof(array) / sizeof(int);
	
	
	assignIntList(&list, array, size, size);
	printArrayListElements(list);
	removeFromArrayList(&list, 0);

	printArrayListElements(list);
	removeFromArrayList(&list, 0);

	printArrayListElements(list);

	return 0;
}

/**
 * [initialize an intArrayList]
 * @param  list              [newly created struct intArrayList]
 * @param  array             [original array created by compiler]
 * @param  arraySize         [memory taken by compiler's array]
 * @param  arrayElementCount [number of elements in original compiler's array]
 * @return                   [integer denoting process outcome]
 */
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
/**
 * [prints arraylist allocated memory (contains elements outside of structure)]
 * @param list [list to be printed]
 */
void printArrayList(struct intArrayList list){
	for (int i = 0; i < list.length; ++i){	
		printf("%d ", list.arrayPtr[i]);
	}
	puts("display complete..");
	printf("length of arrayList is: %d\n", list.length);
}

/**
 * [prints arraylist elements within structure]
 * @param list [list to be printed]
 */
void printArrayListElements(struct intArrayList list){
	for(int i = 0; i < list.count;++i){
		printf("%d ", list.arrayPtr[i]);
	}
	puts("display complete...");
	printf("count of elements is: %d\n", list.count);
}

/**
 * [adds an element to the end of an arrayList]
 * @param  list  [list to be manipulated]
 * @param  value [value to be added]
 * @return       [integer denoting process outcome]
 */
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

/**
 * [expands a list by factor of 2 and copy data from original list to newly allocated list]
 * @param  list [original list to be expanded]
 * @return      [integer denoting process outcome]
 */
int * expandAndCopy(struct intArrayList list){
	int * temp = (int *) malloc(sizeof(int) * list.length * 2);
	if(temp != NULL){
		memcpy(temp, list.arrayPtr, (sizeof(int) * list.length));
	} else {
		strerror(ENOMEM);
		return NULL;
	}	
	return temp;
}


//* note that this can increase the count of a list.
/**
 * [swap the list to the right starting a certain index]
 * @param list  [list to be swapped to the right]
 * @param index [index starting from which the list will be swapped right]
 */
void swapRight(struct intArrayList * list, int index){
	int i = list->length - 2;
	for (; i > index-1; --i){
		list->arrayPtr[i+1] = list->arrayPtr[i];
	}
}
/**
 * [insert an element at a particular index of a list]
 * @param  list  [list to manupulate]
 * @param  index [index to insert element at]
 * @param  value [value of element to insert]
 * @return       [integer denoting process outcome]
 */
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
			swapRight(list, index);
			list->arrayPtr[index] = value;	
			list->count = ++old_count;
			retval = 1;
		}
	}
	return retval;
}

/**
 * [pops the value at the end of a list]
 * @param  list [list to get last item from]
 * @return      [the value of the last item popped]
 */
int pop(struct intArrayList * list){
	int retval = -1;
	if(list->arrayPtr != NULL){
		if(list->count-1 <= list->length/2){
			int * temp;
			retval = list->arrayPtr[list->count-1]; 
			temp = contractAndCopy(*list);
			free(list->arrayPtr);
			list->arrayPtr = temp;
			list->length = list->length / 2;
		} else {
			retval = list->arrayPtr[list->count-1];
			list->arrayPtr[list->count-1] = 0;
		}
		list->count--;
	}
	return retval;
}
/**
 * [shrinks the list to half]
 * @param  list [list to be shrinked]
 * @return      [integer denoting process outcome]
 */
int * contractAndCopy(struct intArrayList list){
	int * temp = (int *) malloc(sizeof(int) * list.length / 2);
	if(temp != NULL){
		memcpy(temp, list.arrayPtr, (sizeof(int) * list.length) / 2);
	} else {
		strerror(ENOMEM);
		return NULL;
	}	
	return temp;
}

/**
 * [remove element at certain index from list]
 * @param  list  [list to be manipulated]
 * @param  index [index at which element is removed]
 * @return       [integer denoting process outcome]
 */
int removeFromArrayList(struct intArrayList * list, unsigned int index){
	int retval = 0;
	if(list != NULL){
		if(list->count - 1 <= list->length / 2){
			int * temp;
			int old_length = list->length;
			int old_count = list->count;
			swapLeft(list, index);
			temp = contractAndCopy(*list);
			free(list->arrayPtr);
			list->arrayPtr = temp;
			list->length = old_length / 2;
			list->count = old_count - 1;
		} else {
			swapLeft(list, index);
			list->arrayPtr[list->count-1] = 0;
			list->count--;
		}
		retval = 1;
	}
	return retval;
}

/**
 * [swaps a list to the right at certain index]
 * @param list  [list to be swapped]
 * @param index [index at which list is swapped left]
 */
void swapLeft(struct intArrayList * list, int index){
	if(list != NULL){
		while(index < list->count - 1){
			list->arrayPtr[index] = list->arrayPtr[index + 1];
			index++;
		}	
	}
}