#include <stdio.h>
#include <stdlib.h>

struct node {
	char data;
	struct node * pNext;
};

//prototypes
struct node * delete(struct node** head, char value);
void printList(struct node** head);
void reverse(struct node ** head);
void destroyList(struct node** head);
int append(struct node** head, char value);
int insertAt(struct node** head, int index, char value);
int find(struct node** const head, char value);
int add(struct node** head, char value);
int orderedInsert(struct node ** head, char value);

int main(void){

	struct node * pHead = NULL;
	append(&pHead, 'C');
	append(&pHead, 'D');
	append(&pHead, 'H');
	insertAt(&pHead, 3, 'S');
	orderedInsert(&pHead, 'A');
	orderedInsert(&pHead, 'B');
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

int insertAt(struct node** head, int index, char value){
	int retval = 0;
	struct node* ptrNew=(struct node*)malloc(sizeof(struct node));
	if(ptrNew){
		ptrNew->data = value;
		struct node* ptr = *head;
		struct node* ptrPrev = NULL;
		int i = 1;
		while(i < index - 1 && ptr->pNext != NULL){
			i++;
			ptrPrev = ptr;
			ptr = ptr->pNext;
		}
		if(ptrPrev != NULL){
			ptrNew->pNext = ptr->pNext;
			ptr->pNext = ptrNew;	
		} else {
			ptrNew->pNext = *head;
			*head = ptrNew;
		}
		retval = 1;
	} else {
		printf("%c not inserted, memory allocation failed\n", value);
	}
	
	return retval;
}	

int find(struct node** const head, char value){
	int retval = -1;
	int i = 0;
	struct node* ptr = *head;
	struct node* ptrFound = NULL;
	while(ptr != NULL){
		if(ptr->data == value){
			return i;
		}
		ptr = ptr->pNext;
		i++;
	}
	
	return retval;
}


int add(struct node** head, char value){
	int retval = 0;
	struct node * ptr = (struct node*)malloc(sizeof(struct node));
	if(ptr){
		ptr->data = value;
		ptr->pNext = *head;
		*head = ptr;
	} else {
		printf("%c not inserted, memory allocation failed", value);
	}
	return retval;
}

void destroyList(struct node** head){
	struct node* ptr = *head;
	while(ptr != NULL){
		*head = ptr->pNext;
		free(ptr);
		ptr = *head; 
	}
}

int orderedInsert(struct node ** head, char value){
	int retval = 0;
	struct node * ptrNew = (struct node *)malloc(sizeof(struct node));
	if(ptrNew){
		ptrNew->data = value;
	 	ptrNew->pNext = NULL;
		struct node* ptrPrev = NULL;
		struct node* ptrCurrent = *head; //pointing to first node
		while(ptrCurrent->pNext != NULL && ptrCurrent->data < value){
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