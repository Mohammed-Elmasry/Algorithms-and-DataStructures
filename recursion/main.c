#include <stdio.h>
#include <stdlib.h>

//prototypes
int fibonacci(int start);
int factorial(int start);
int factorial_nonrecursive(int start);
int sum(int array[], int size);
int sum_recursive(int array[], int size, int i);

int main(int argc, char * argv[]){
	int array[5] = {1,2,3,4,5};
	// int result = sum(array, 5);
	int result = sum_recursive(array, 5, 0);

	printf("result is %d\n", result);
	// int result = factorial_nonrecursive(5);
	// int result2 = factorial(5);
	// if(result2 == result){
	// 	printf("same!\n");
	// } else {
	// 	printf("different\n");
	// }
	return 0;
}


int factorial(int start){
	int retval = 1;
	//base case
	if(start == 0){
		return retval;
	} else {
		retval = start * factorial(start-1);
	}
	return retval;
}

int fibonacci(int start){
	if(start == 1){
		return 1;
	} else if (start == 0){
		return 0;
	} else {
		return (fibonacci(start - 1) + fibonacci(start - 2));
	}
}

int factorial_nonrecursive(int start){
	int retval = 1;
	while(start > 0){
		retval = retval * start;
		start--;
	}
	return retval;
}


int sum(int array[], int size){
	int total = 0;
	for (int i = 0; i < size; i++){
		total = total + array[i];
	}
	return total;
}


int sum_recursive(int array[], int size, int i){
	int total = 0;
	if(i == (size - 1)){
		return array[i];
	} else {
		return total + array[i] + sum_recursive(array, size, i+1);
	}
	return total;
}