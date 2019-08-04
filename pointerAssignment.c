#include <stdio.h>
#include <stdlib.h>

int main(void){
	int * ptr1, *ptr2;
	int x = 8;
	ptr2 = &x;
	printf("%d\n", *ptr1);
	ptr1 = ptr2;
	printf("%d\n", *ptr1);
	return 0;
}