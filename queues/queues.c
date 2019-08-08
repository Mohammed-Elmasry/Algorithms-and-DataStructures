#include <stdio.h>
#include <stdlib.h>

struct node {
	char data;
	struct node * pNext;
};

//prototypes

int main(void){
	struct node *pHead, *pTail = NULL;

	return 0;
}


int enqueue(struct node** head, struct node** tail, char value){
	int retval = 0;
	struct node * ptrNew = (struct node *)malloc(sizeof(struct node));
	if (ptrNew){
		ptrNew->data = value;
		ptrNew->pNext = (*tail)->pNext;
		(*tail)->pNext = ptrNew;
		*tail = ptrNew;
	} else {
		printf("%c not inserted, memory allocation failed!", value);
	}
	return retval;
}