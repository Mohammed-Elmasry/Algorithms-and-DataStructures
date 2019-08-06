#include <stdio.h>
#include <stdlib.h>

//prototypes
int push(struct node** top, int value);

struct node{
	int data;
	struct node * pNext;
};


int main(void){

	return 0;
}

int push(struct node** top, int value){
	int retval = 0;
	struct node* ptrNew = (struct node*)malloc(sizeof(struct node));
	if(ptrNew){ // if allocated successfully
		ptrNew->data = value;
		ptrNew->pNext = *top; //whatever the top is looking at
		*top = ptrNew;
		retval = 1;
	} else {
		printf("%d not pushed, memory allocation failed!", value);
	}
	return retval;
}