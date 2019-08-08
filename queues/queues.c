#include <stdio.h>
#include <stdlib.h>

struct node {
	char data;
	struct node * pNext;
};

//prototypes
void printQueue(struct node ** head);
int enqueue(struct node** head, struct node** tail, char value);
char dequeue(struct node ** head, struct node ** tail);

int main(void){
	struct node *pHead = NULL;
	struct node *pTail = NULL;
	enqueue(&pHead, &pTail, 'C');
	enqueue(&pHead, &pTail, 'D');
	printQueue(&pHead);
	dequeue(&pHead, &pTail);
	printQueue(&pHead);
	dequeue(&pHead, &pTail);
	printQueue(&pHead);
	return 0;
}


int enqueue(struct node** head, struct node** tail, char value){
	int retval = 0;
	struct node * ptrNew = (struct node *) malloc(sizeof(struct node));
	if (ptrNew != NULL){
		ptrNew->data = value;
		ptrNew->pNext = NULL;

		if(*head == NULL){
			*head = ptrNew;
		} else {
			(*tail)->pNext = ptrNew;	
		}
		*tail = ptrNew; //the tail has to point to the newly added node anyway
		retval = 1;
	} else {
		printf("%c not inserted, memory allocation failed!\n", value);
	}
	return retval;
}

char dequeue(struct node ** head, struct node ** tail){
	char temp;
	struct node * ptr = (struct node *) malloc(sizeof(struct node));
	temp = (*head)->data;	
	ptr = *head;
	*head = (*head)->pNext;
	
	if(*head == NULL){
		*tail = NULL; //the queue is empty	
	} 

	free(ptr);
	return temp;
}

void printQueue(struct node ** head){
	struct node * ptrCurrent = *head;
	if (ptrCurrent == NULL){
		puts("Queue is empty!\n");
	} else {
		puts("The Queue is: ");
	
		while(ptrCurrent != NULL){
			printf("%c --> ", ptrCurrent->data);
			ptrCurrent = ptrCurrent->pNext;
		}
		puts(" NULL\n");
	}
}