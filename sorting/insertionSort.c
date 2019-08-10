#include <stdio.h>
#include <stdlib.h>

struct node {
	char data;
	struct node * pNext;
};

//prototypes
void printList(struct node* head);
int orderedInsert(struct node ** head, char value);
struct node * insertionSort(struct node * head);

int main(void){
	struct node * pHead = NULL;
	struct node n1;
	struct node n2;
	n1.data = 'H';
	n2.data = 'C';
	n1.pNext = &n2;
	n2.pNext = NULL;

	pHead = &n1;

	printList(pHead);
	struct node * sortedList = insertionSort(pHead);
	printList(sortedList);
	return 0;
}


void printList(struct node* head){
	while(head != NULL){
		printf("%c --> ", head->data);
		head = head->pNext;
	}
	printf(" NULL");
	printf("\n");
}


struct node * insertionSort(struct node * head){
	struct node * newHead = NULL; // top of new list
	struct node * ptrCurrent = NULL;

	while(head != NULL){
		orderedInsert(&newHead, head->data);
		head = head->pNext;
	}
	return newHead;
}

int orderedInsert(struct node ** head, char value){
	int retval = 0;
	struct node * ptrNew = (struct node *)malloc(sizeof(struct node));
	if(ptrNew){
		ptrNew->data = value;
	 	ptrNew->pNext = NULL;
		struct node* ptrPrev = NULL;
		struct node* ptrCurrent = *head; //pointing to first node
		while(ptrCurrent != NULL && ptrCurrent->data < value){
			ptrPrev = ptrCurrent;
			ptrCurrent = ptrCurrent->pNext;
		}
		if(ptrPrev != NULL){
			ptrNew->pNext = ptrCurrent;
			ptrPrev->pNext = ptrNew;
		} else {
			ptrNew->pNext = ptrCurrent;
			*head = ptrNew;
		}
		retval = 1;
	} else {
		printf("%c not inserted, memory allocation failed", value);
	}

	return retval;
}