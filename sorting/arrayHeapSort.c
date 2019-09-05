#include <stdio.h>

//prototype
int parent(int index);

int main(int argc, char * argv[]){
	int arr[7] = {15,22,3,18,4,8,77,9};
	printf("parent of 7 is %d\n", parent(7));
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
	return (i-1)/2;
}