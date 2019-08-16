#include <stdio.h>
#include <stdlib.h>

struct arrayList{
	int array[4];
}typedef ArrayList;

// prototypes
void printList(ArrayList list, long unsigned int size);
void expandByOne();


int main(void){
	ArrayList list; 
	list.array[0] = 10;
	list.array[1] = 11;
	list.array[2] = 12;
	list.array[3] = 13;

	printList(list, 4);
	return 0;
}

void expandByOne(){


}

void printList(ArrayList list, long unsigned int size){
	for(int i = 0; i < size; ++i){
		printf("%d\n", list.array[i]);
	}
}