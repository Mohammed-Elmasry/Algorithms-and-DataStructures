#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
	char data;
	struct node * pNext;
};

int main(void){

	return 0;
}

int orderedInsert(struct node* head, char value){
	int retval = 0;
	struct node* ptrNew = (struct node*) malloc(sizeof(struct node));
	if(ptrNew){
		ptrNew->data = value;
		ptrNew->pNext = NULL;
		if(head == NULL){ //if list empty 
			head = ptrNew;
			retval = 1;
		} else { //if list not empty
			struct node* ptrCounter = head;
			struct node* ptrLeft = NULL;
			while(ptrCounter->pNext != NULL && value > ptrCounter->data){
				ptrLeft = ptrCounter;
				ptrCounter = ptrCounter->pNext;
			}
		}	
	} else {
		puts("memory allocation failed");
		retval = 0;
	}
	

	return retval;
}