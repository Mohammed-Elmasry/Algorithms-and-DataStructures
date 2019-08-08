#include <stdio.h>
#include <stdlib.h>

struct node {
	char data;
	struct node * pNext;
};

//prototypes
void printQueue(struct node * head);
int enqueue(struct node** head, struct node** tail, char value);
int isEmpty(struct node * ptr);

int main(void){
	struct node *pHead, *pTail = NULL;
	enqueue(&pHead, &pTail, 'C');
	return 0;
}


int enqueue(struct node** head, struct node** tail, char value){
	int retval = 0;
	struct node * ptrNew = (struct node *)malloc(sizeof(struct node));
	if (ptrNew){
		ptrNew->data = value;
		ptrNew->pNext = NULL;

		if(isEmpty(*head)){
			(*head)->pNext = ptrNew;
		} else {
			(*tail)->pNext = ptrNew;	
		}
		*tail = ptrNew; //the tail has to point to the newly added node anyway
		retval = 1;
	} else {
		printf("%c not inserted, memory allocation failed!", value);
	}
	return retval;
}

void printQueue(struct node * head){
	if (head == NULL){
		puts("Queue is empty!\n");
	}

	while(head != NULL){
		printf("%c --> ", head->data);
		head = head->pNext;
	}
	puts(" NULL\n");
}

int isEmpty(struct node * ptr){
	return ptr == NULL;
}