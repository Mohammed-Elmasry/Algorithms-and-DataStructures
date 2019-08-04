#include <stdio.h>
#include <stdlib.h>

//prototypes
void allocator(int** head, int n);

int main(void){
	int * ptr1 = NULL;
	int x = 5;
	ptr1 = &x;
	allocator(&ptr1, 8);
	printf("current value of original pointer is %d\n", *ptr1);
	return 0;
}


void allocator(int** head, int n){
	int * ptrNew = (int*) malloc(sizeof(int));
	if (ptrNew){
		*ptrNew = n;
		*head = ptrNew;
		printf("%d successfully inserted\n", n);
	} else {
		printf("%d not inserted, memory allocation failed!\n", n);
	}

}
 