#include <stdio.h>

//prototype
int parent(int index);

int main(int argc, char * argv[]){
	int arr[8] = {15,22,3,18,4,8,77,9};

	return 0;
}

void heapify(int * array, int size){
	for (int i = size - 1; i > 0; --i){
		while(i != 0){
			if(parent(i) < array[i]){

			}
		}
	}
}

int parent(int index){
	return (index-1)/2;
}

void swapIndex(int * array, unsigned int first, unsigned int second){
	int temp = array[second];
	array[second] = array[first];
	array[first] = temp;
}
