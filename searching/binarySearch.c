#include <stdio.h>

//prototypes
unsigned int binarySearch(int * array, int value, int min, int max);
unsigned int binarySearchRecursive(int * array, int value, int min, int max);


int main(int argc, char * argv[]){
	int arr[11] = {0,23,45,66,77,81,98,102,137,201,276};
	int size = sizeof(arr) / sizeof(int);
	int result = binarySearch(arr, 137, 0, size - 1);
	
	printf("result is %d\n", result);
	return 0;
}


unsigned int binarySearch(int * array, int value, int min, int max){
	int retval = -1;
	int mid = 0;
	while (min <= max){
		mid = (min + max) / 2;
		if(array[mid] < value){
			min = mid + 1;
		} else if (array[mid] > value){
			max = mid - 1;
		} else {
			return mid;
		}
	}
	return retval;
}

unsigned int binarySearchRecursive(int * array, int value, int min, int max){
	int retval = -1;
	int mid = (min + max) / 2;
	if(min <= max){	
		if(array[mid] < value){
			binarySearchRecursive(array, value, min, mid - 1);
		} else if (array[mid] > value){
			binarySearchRecursive(array, value, mid + 1, max);
		} else {
			return mid;
		}
	}
	return retval;
}