#include <stdio.h>
#include "headers/linked_lists.h"
#include "hash.h"

//prototypes

int main(int argc, char * argv[]){
	int result = hash(13513254, 7);
	printf("%d\n", result);
	return 0;
}

int hash(unsigned int input, int len){
	int retval = 0;
	retval = input % len;
	return retval;
	
}
