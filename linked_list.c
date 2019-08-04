#include <stdio.h>
#include <stdlib.h>

struct node {
	char data;
	struct node * pNext;
};

//prototypes
void printList(struct node* head);

int main(void){
	struct node node1, node2;
	node1.data = 'C';
	node2.data = 'H';
	node2.pNext = NULL;
	node1.pNext = &node2;
	struct node *Head = NULL;
	Head = &node1;
	printList(Head);
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
			if(ptrLeft == NULL && value < ptrCounter->data){ //still first element
				ptrNew->pNext = head;
				head = ptrNew;
			}
			ptrNew->pNext = ptrLeft->pNext;
			ptrLeft->pNext = ptrNew;
		}	
	} else {
		puts("memory allocation failed");
		retval = 0;
	}
	
	return retval;
}

void printList(struct node* head){
	struct node * ptr;
	ptr = head;
	while(ptr->pNext != NULL){
		printf("%c -->", ptr->data);
	}
}