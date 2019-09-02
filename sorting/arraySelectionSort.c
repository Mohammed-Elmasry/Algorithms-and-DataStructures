#include <stdio.h>
#include <stdlib.h>
#define SIZE 4;


//prototypes
void swap(int * array, unsigned int first, unsigned int second);


int main(int argc, char * argv[]){
	int arr[SIZE] = {1,2,3,4};
	swap(arr, 0, 3)
	return 0;
}

void selectionSort(int * array, unsigned int size){
	int limit = 0;
	int max = 0;
	for (int i = 0; i < size - limit; i++){
		max = array[i];
		for(int j = i + 1; j < size - limit; j++){
			if(array[max] < array[j]){
				max = j;
			}
		}
		swap(array, size, max, j);
	}
}

void swap(int * array, int size ,unsigned int first, unsigned int second){
	
}