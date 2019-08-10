#include <stdio.h>
#include <stdlib.h>



struct node {
	char data;
	struct node * pNext;
	struct node * pPrev;
};

//prototypes
int swap(struct node * ptr);
int getLength(struct node * head);
int add(struct node** head, char value);
int append(struct node ** head, struct node** tail, char value);
int delete(struct node** head, struct node ** tail, char value);
int orderedInsert(struct node ** head, struct node ** tail, char value);
int insertAt(struct node** head, struct node ** tail, int index, char value);
void printList(struct node* head);
void destroyList(struct node** head, struct node ** tail);
struct node * find(struct node* head, char value);

int main(void){
	struct node * pHead = NULL;
	struct node * pTail = NULL;

	append(&pHead, &pTail, 'C');
	// printList(pHead);
	append(&pHead, &pTail, 'D');
	// append(&pHead, &pTail, 'H');
	append(&pHead, &pTail, 'G');
	append(&pHead, &pTail, 'E');
	// printList(pHead);
	// delete(&pHead, &pTail, 'A');
	// printList(pHead);
	insertAt(&pHead, &pTail, 0, 'H');
	// printf("length of list is %d\n", getLength(pHead));
	printList(pHead);
	orderedInsert(&pHead, &pTail, 'S');
	printList(pHead);
	struct node * found = find(pHead, 'H');
	swap(found);
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

	
int insertAt(struct node** head, struct node ** tail, int index, char value){
	int retval = 0;
	struct node* ptrNew=(struct node*)malloc(sizeof(struct node));
	if(ptrNew){
		ptrNew->data = value;
		struct node* ptr = *head;
		int i = 0;
		while(i < index && ptr != NULL){
			i++;
			ptr = ptr->pNext;
		}
		if(ptr != NULL && ptr->pPrev != NULL){ // not first place
			ptrNew->pNext = ptr;
			ptrNew->pPrev = ptr->pPrev;
			(ptr->pPrev)->pNext = ptrNew;
			ptr->pPrev = ptrNew;	
		} else { 
			if(ptr == NULL){ // last element
				ptrNew->pNext = ptr;
				(*tail)->pNext = ptrNew;
				ptrNew->pPrev = (*tail);
				*tail = ptrNew;	
			} else { // first element
				ptrNew->pNext = *head;
				*head = ptrNew;
			}
		}
		retval = 1;
	} else {
		printf("%c not inserted, memory allocation failed\n", value);
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
		ptr->pPrev = NULL;
		ptr->pNext = *head;
		*head = ptr;
	} else {
		printf("%c not inserted, memory allocation failed", value);
	}
	return retval;
}

void destroyList(struct node** head, struct node ** tail){
	struct node* ptr = *head;
	while(ptr != NULL){
		*head = ptr->pNext;
		free(ptr);
		ptr = *head; 
	}
	*head = NULL;
	*tail = NULL;
}

int orderedInsert(struct node ** head, struct node ** tail, char value){
	int retval = 0;
	struct node * ptrNew = (struct node *)malloc(sizeof(struct node));
	if(ptrNew){
		ptrNew->data = value;
	 	ptrNew->pNext = NULL;
	 	ptrNew->pPrev = NULL;
		struct node* ptrCurrent = *head; // pointing to first node
		while(ptrCurrent != NULL && ptrCurrent->data < value){
			ptrCurrent = ptrCurrent->pNext;
		}
		if(ptrCurrent != NULL){
			if(ptrCurrent->pPrev != NULL){
				ptrNew->pNext = ptrCurrent;
				(ptrCurrent->pPrev)->pNext = ptrNew;
			} else {
				ptrNew->pNext = ptrCurrent;
				*head = ptrNew;
			}	
		} else {
			ptrNew->pPrev = *tail;
			(*tail)->pNext = ptrNew;	
			*tail = ptrNew;
		}
		
		retval = 1;
	} else {
		printf("%c not inserted, memory allocation failed", value);
	}

	return retval;
}

int swap(struct node * ptr){
	int retval = 0;
	if(ptr->pNext && ptr->pPrev){ // not first element
		(ptr->pPrev)->pNext = ptr->pNext;
		(ptr->pNext)->pPrev = ptr->pPrev;
		ptr->pNext = ptr->pPrev;
		ptr->pPrev = (ptr->pPrev)->pPrev;
		((ptr->pPrev)->pNext)->pPrev = ptr;
		(ptr->pPrev)->pNext = ptr;
		retval = 1;
	} else {
		if(ptr->pPrev){ // if it's the last element
			(ptr->pPrev)->pNext = ptr->pNext;
			ptr->pNext = ptr->pPrev;
			ptr->pPrev = (ptr->pPrev)->pPrev;
			((ptr->pPrev)->pNext)->pPrev = ptr;
			(ptr->pPrev)->pNext = ptr;
			retval = 1;		
		} else {
			puts("cannot swap the first element, list not changed!");
		}
	}
	return retval;
}