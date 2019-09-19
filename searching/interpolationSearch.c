#include <stdio.h>
unsigned int interpolationSearch(int * array, int value, int max);

int main(int argc, char * argv[]){
	int arr[11] = {0,23,45,66,77,81,98,102,137,201,276};
	int size = sizeof(arr) / sizeof(int);
	int result = interpolationSearch(arr, 66, size - 1);
	
	printf("result is %d\n", result);
	return 0;
}

unsigned int interpolationSearch(int * array, int value, int max){
	int retval = -1;
	int min = 0;
	while(min <= max){
		int mid = min - ((value - array[min]) / (array[max] - array[min])) * (max - min);
		if(array[mid] < value){
	 		min = mid + 1;
		} else if(array[mid] > value){
			max = mid - 1;
		} else {
			return mid;
		}
	}
	return retval;	
}