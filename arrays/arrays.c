#include <stdio.h>
#include <stdlib.h>


//prototypes
int getMode(int * array, long unsigned int size);

int main(void){
	int myArray[] = {2,2,3,5,5,5,5, 4,4,4,4,4,4,4,4};
	long unsigned int size = sizeof(myArray) / sizeof(int);
	printf("array size is %lu\n", size);
	int best = getMode(myArray, size);
	printf("your best item is %d\n", best);
	return 0;
}

int getMode(int * array, long unsigned int size){
	int current_item_freq = 0;
	int best_item_freq = 0;
	int current_item = array[0];
	int best_item = 0;
	for (int i = 0; i < size; ++i){		
		if(array[i] != current_item || i == size-1){ // found new element
			if(current_item_freq > best_item_freq){
				best_item_freq = current_item_freq;
				best_item = current_item;	
			}
			current_item = array[i];
			current_item_freq = 0;
		}	
		current_item_freq++;
	}
	return best_item;
}