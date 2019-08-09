#include <stdio.h>
#include <stdlib.h>



struct node {
	char data;
	struct node * pNext;
	struct node * pPrev;
};

//prototypes
int append(struct node ** head, struct node** tail, char value);
int delete(struct node** head, struct node ** tail, char value);
void printList(struct node* head);


int main(void){
	struct node * pHead = NULL;
	struct node * pTail = NULL;

	append(&pHead, &pTail, 'C');
	printList(pHead);
	append(&pHead, &pTail, 'D');
	append(&pHead, &pTail, 'F');
	append(&pHead, &pTail, 'G');
	append(&pHead, &pTail, 'E');
	printList(pHead);
	delete(&pHead, &pTail, 'A');
	printList(pHead);

	return 0;
}


int append(struct node ** head, struct node** tail, char value){
	int retval = 0;
	struct node* ptrNew = (struct node*) malloc(sizeof(struct node));
	if(ptrNew != NULL){
		ptrNew->data = value;
		ptrNew->pNext = NULL;
		ptrNew->pPrev = NULL;

		if(*head == NULL){ // empty list
			*head = ptrNew;
		} else { // list is not empty
			(*tail)->pNext = ptrNew;
			ptrNew->pPrev = (*tail);
		}
		*tail = ptrNew;
		retval = 1;
	} else {
		printf("%c not inserted, memory allocation failed!", value);
		retval = 0;
	}
}

void printList(struct node* head){
	while(head != NULL){
		printf("%c <--> ", head->data);
		head = head->pNext;
	}
	printf(" NULL");
	printf("\n");
}

int delete(struct node** head, struct node ** tail, char value){
	int retval = 0;
	struct node* temp;
	if(*head == NULL){
		printf("List is Empty!\n");
	} else {
		temp = *head;
		while(temp != NULL && temp->data != value){
			temp = temp->pNext;
		}
		if(temp != NULL){
			if(temp->pPrev != NULL){
				if(temp->pNext != NULL){
					(temp->pPrev)->pNext = temp->pNext;
					(temp->pNext)->pPrev = temp->pPrev;	
				} // last node in list
					(temp->pPrev)->pNext = temp->pNext;
					*tail = temp->pPrev;
			} else {
				*head = temp->pNext;
				(*head)->pPrev = temp->pPrev;
			}				
			free(temp);
			retval = 1;
		} else {
			printf("Deletion failed, character %c not found!\n", value);
		}
	}
	return retval;
}
