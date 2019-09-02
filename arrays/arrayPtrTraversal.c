#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
	int arr[3] = {1,2,3};
	int * ptr = arr;
	int * ptr2 = arr;
	printf("%d\n", ptr2[0]);
	ptr2 = ptr2 + 2;
	printf("%d\n", ptr2[0]);

	for (int i = 0; i < 3; ++i, ptr++){
		if(ptr[0] == ptr2[0]){
			puts("bingo got it");
			ptr = ptr2;
		}
	}
	ptr--;

	printf("first pointer is at %p\n and its value is %d\n", ptr, ptr[0]);
	printf("second pointer is at %p\n and its value is %d\n", ptr2, ptr2[0]);

	return 0;
}