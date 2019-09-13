#include <stdlib.h>
#include <stdio.h>
#include "headers/arrayList.h"
#include "headers/arraySelectionSort.h"

//prototypes
void quickSort(struct intArrayList * list, int start, int end);
int partition(struct intArrayList * list, int start, int end);


int main(int argc, char * argv[]){
	
	// int array[6] = {5,9,1,10,2,6};
	int array[] = {10, 80, 30, 90, 40, 50, 70};
	struct intArrayList list;
	assignIntList(&list, array, 6,6);
	puts("list before sort...");
	printArrayListElements(list);

	// int i = partition(&list, 0, list.count);
	
	quickSort(&list, 0, list.count);
	puts("\n\n\nlist after sorting..");
	printArrayListElements(list);


	// printf("pivot is at: %d\n", partition(&list, 0, i));
	printArrayListElements(list);
	return 0;
}

int partition(struct intArrayList * list, int start, int end){
	int pivot = list->arrayPtr[end];
	int i = start - 1, j = start;
	while(j <= end - 1){
		if(list->arrayPtr[j] < pivot){
			i++;
			swapIndex(list->arrayPtr, i, j);
		}
		j++;
	}
	i++;
	swapIndex(list->arrayPtr, i, j);
	return i;
}

void quickSort(struct intArrayList * list, int start, int end){
	if(start < end){
		int middle = partition(list, start, end);
		quickSort(list, start, middle - 1);
		quickSort(list, middle + 1, end);
	}	
}

// void swapIndex(struct intArrayList * list, unsigned int index1, unsigned int index2){
// 	int temp = index1;
// 	list->arrayPtr[index1] = list->arrayPtr[index2];
// 	list->arrayPtr[index2] = list->arrayPtr[temp];
// }