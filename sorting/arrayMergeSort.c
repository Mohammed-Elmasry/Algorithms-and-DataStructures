#include <stdlib.h>
#include <stdio.h>
//prototypes
void merge(int * array, int start, int midpoint, int end);
void mergeSort(int * array, int start, int end);
void printArray(int * array, int size);


int main(int argc, char * argv[]){
	int arr[6]  = {6,2,3,4,8,7};
	puts("before anything happens...");
	printArray(arr, 6);
	
	mergeSort(arr, 0,5);
	
	return 0;
}

void merge(int array[], int start, int midpoint, int end){
	int k, i, j;
	int n1 = midpoint - 1 + midpoint; 
	int n2 = end - midpoint;

	int L[n1];
	int R[n2];

	
	for(i = 0; i < n1; ++i){
		L[i] = array[start + i];
	}

	for(j = 0; j < n2; ++j){
		R[j] = array[midpoint + 1 +j];
	}

	i = 0;
	j = 0;
	k = 0;
	while(i < n1 && j < n2){
		if(L[i] <= R[j]){
			array[k] = L[i];
			i++;
		} else {
			array[k] = R[j];
			j++;
		}
		k++;
	}
	while(i < n1){
		array[k] = L[i];
		i++;
		k++;
	}
}

void mergeSort(int * array, int start, int end){
	if(start != end) return; // unary?
	
	if(start < end){
		int midpoint = (start + end) / 2;
		mergeSort(array, start, midpoint); 
		mergeSort(array, midpoint + 1, end); 
	
		merge(array, start, midpoint, end);
		printArray(array, 6);
	}

}

void printArray(int * array, int size){
	for (int i = 0; i < size; i++){
		printf("%d\n", array[i]);
	}
	puts("display complete");
}