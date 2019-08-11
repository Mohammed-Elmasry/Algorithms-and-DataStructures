#include <stdio.h>
#include <stdlib.h>

struct node {
	char data;
	struct node * pNext;
};

//prototypes
void printList(struct node* head);
void reverse(struct node ** head);
void destroyList(struct node** head);
int getLength(struct node * head);
int append(struct node** head, char value);
int delete(struct node** head, char value);
int add(struct node** head, char value);
int orderedInsert(struct node ** head, char value);
int insertAt(struct node** head, int index, char value);
struct node * find(struct node* head, char value);
void removeDuplicates(struct node ** head);

int main(void){

	struct node * pHead = NULL;
	
	orderedInsert(&pHead, 'C');
	orderedInsert(&pHead, 'C');
	orderedInsert(&pHead, 'Z');
	orderedInsert(&pHead, 'N');
	orderedInsert(&pHead, 'L');	
	printList(pHead);
	removeDuplicates(&pHead);
	printList(pHead);
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

void printList(struct node* head){
	while(head != NULL){
		printf("%c --> ", head->data);
		head = head->pNext;
	}
	printf(" NULL");
	printf("\n");
}

int delete(struct node** head, char value){
	int retval = 0;
	struct node* temp;
	struct node* ptrPrev = NULL;
	if(*head == NULL){
		printf("List is Empty!\n");
	} else {
		temp = *head;
		while(temp != NULL && temp->data != value){
			puts("loop access#");
			ptrPrev = temp;
			temp = temp->pNext;
		}
		if(temp != NULL){
			if(ptrPrev != NULL){
				ptrPrev->pNext = temp->pNext;
			} else {
				*head = temp->pNext;
			}				
			free(temp);
			retval = 1;
		} else {
			printf("Deletion failed, character %c not found!\n", value);
		}
	}
	return retval;
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
		int i = 0;
		while(i < index && ptr != NULL){
			i++;
			ptrPrev = ptr;
			ptr = ptr->pNext;
		}
		if(ptrPrev != NULL){
			ptrNew->pNext = ptr;
			ptrPrev->pNext = ptrNew;	
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

struct node * find(struct node* head, char value){
	struct node* ptr = head;
	while(ptr != NULL){
		if(ptr->data == value){
			return ptr;
		}
		ptr = ptr->pNext;
	}
	return ptr;	
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
	*head = NULL; // reset the head
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

int getLength(struct node * head){
	int retval = 0;
	while (head != NULL){
		retval++;
		head = head->pNext;
	}
	return retval;
}

void MTF(struct node ** head, struct node * ptr){

}

void removeDuplicates(struct node ** head){
	struct node * candidate = *head;
	struct node * ptrPrev = NULL; //candidate;
	struct node * ptrCurrent = NULL; // candidate->pNext;
	struct node * ptrNext = NULL; // ptrCurrent->pNext;
	
	while(candidate != NULL && candidate->pNext){
		ptrPrev = candidate;
		ptrCurrent = candidate->pNext;
		ptrNext = ptrCurrent->pNext;					
		// main condition
		while(ptrCurrent != NULL && ptrCurrent->pNext){
			if (candidate->data == ptrCurrent->data){
				ptrPrev->pNext = ptrNext;
				free(ptrCurrent);
				ptrCurrent = ptrNext;
				ptrNext = ptrCurrent->pNext;
			} else {
				ptrPrev = ptrCurrent;
				ptrCurrent = ptrNext;
				ptrNext = ptrCurrent->pNext;
			}
		}
		candidate = candidate->pNext;
	}

}