#include <stdio.h>
#include <stdlib.h>

struct node {
	char data;
	struct node * pNext;
};

//prototypes
void printList(struct node* head);
int orderedInsert(struct node* head, char value);

int main(void){
	struct node *Head = NULL;
	orderedInsert(Head, 'C');
	printList(Head);
	return 0;
}

int orderedInsert(struct node* head, char value){
	int retval = 0;
	struct node* ptrNew = (struct node*) malloc(sizeof(struct node));
	if(ptrNew){
		ptrNew->data = value;
		ptrNew->pNext = NULL;
		
		struct node* ptrCounter = head;
		struct node* ptrLeft = NULL;
		
		while(ptrCounter != NULL && value > ptrCounter->data){
			ptrLeft = ptrCounter;
			ptrCounter = ptrCounter->pNext;
		}
		if(ptrLeft == NULL ){ //still first element
			ptrNew->pNext = head;
			head = ptrNew;
		} else {
			ptrLeft->pNext = ptrNew;
			ptrNew->pNext = ptrCounter;	
		}
		retval = 1;
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
	while(ptr != NULL){
		printf("%c --> ", ptr->data);
		ptr = ptr->pNext;
	}
	printf(" NULL");
	printf("\n");
}