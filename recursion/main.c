#include <stdio.h>
#include <stdlib.h>

//prototypes
int fibonacci(int start);
int factorial(int start);

int main(int argc, char * argv[]){
	int result = fibonacci(5);
	
	printf("your result is %d\n", result);
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