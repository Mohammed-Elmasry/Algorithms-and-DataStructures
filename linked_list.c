#include <stdio.h>
#include <stdlib.h>

struct node {
	char data;
	struct node * pNext;
};

//prototypes
void printList(struct node** head);
int append(struct node** head, char value);
struct node * delete(struct node** head, char value);
void reverse(struct node ** head);

int main(void){

	struct node * pHead = NULL;
	append(&pHead, 'C');
	append(&pHead, 'D');
	append(&pHead, 'H');
	reverse(&pHead);
	printList(&pHead);
	return 0;
}

int append(struct node** head, char value){
	int retval = 0;
	struct node* ptrNew = (struct node*) malloc(sizeof(struct node));
	if(ptrNew != NULL){
		ptrNew->data = value;
		ptrNew->pNext = NULL;

		struct node* ptrCurrent = *head;
		struct node* ptrPrev = NULL;
		while(ptrCurrent != NULL){
			ptrPrev = ptrCurrent;
			ptrCurrent = ptrCurrent->pNext;
		}
		if(ptrPrev == NULL){
			*head = ptrNew;
		} else {
			ptrPrev->pNext = ptrNew;
		}
		retval = 1;
	} else {
		printf("%c not inserted, memory allocation failed!", value);
		retval = 0;
	}

	return retval;
}


void printList(struct node** head){
	struct node * ptr;
	ptr = *head;
	while(ptr != NULL){
		printf("%c --> ", ptr->data);
		ptr = ptr->pNext;
	}
	printf(" NULL");
	printf("\n");
}

struct node * delete(struct node** head, char value){
	struct node* temp;
	struct node* ptrPrev = NULL;
	temp = *head;
	while(temp->data != value){
		ptrPrev = temp;
		temp = temp->pNext;
	}
	ptrPrev->pNext = temp->pNext;
	return temp;
}

void reverse(struct node ** head){
	struct node* ptrCurrent = *head;
	struct node* ptrPrev = NULL;
	struct node* ptrNext = NULL;

	while(ptrCurrent != NULL){
		ptrNext = ptrCurrent->pNext;
		ptrCurrent->pNext = ptrPrev;
		ptrPrev = ptrCurrent;
		ptrCurrent = ptrNext;
	}
	*head = ptrPrev;
}