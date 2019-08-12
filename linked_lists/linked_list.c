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
void runnerRemoveDuplicates(struct node ** head);
struct node * getK(struct node * head, int k);
void deleteFromMiddle(struct node **head, struct node * target);

int main(void){

	struct node * pHead = NULL;
	
	append(&pHead, 'C');
	append(&pHead, 'C');
	append(&pHead, 'Z');
	append(&pHead, 'N');
	append(&pHead, 'S');	
	append(&pHead, 'P');	
	append(&pHead, 'Z');
	append(&pHead, 'L');	
	append(&pHead, 'L');	
	append(&pHead, 'T');
	append(&pHead, 'S');
	append(&pHead, 'H');
	append(&pHead, 'Q');
	append(&pHead, 'R');
	append(&pHead, 'T');

	printList(pHead);
	struct node * found = find(pHead, 'Z');
	deleteFromMiddle(&pHead, found);
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
			// code to handle first element
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
		while(candidate != NULL){
		struct node * ptrCurrent = NULL; // candidate->pNext;
		struct node * temp = NULL; // ptrCurrent->pNext;
		ptrCurrent = candidate; // you're starting with candidate anyway
		// main condition
		while(ptrCurrent != NULL && ptrCurrent->pNext){
			if (candidate->data == (ptrCurrent->pNext)->data){
				temp = (ptrCurrent->pNext)->pNext;
				free(ptrCurrent->pNext);
				ptrCurrent->pNext = temp;
			} else {
				ptrCurrent = ptrCurrent->pNext;
			}
		}
		candidate = candidate->pNext;
	}
}

void runnerRemoveDuplicates(struct node ** head){
	struct node * ptrCurrent = *head;
	while(ptrCurrent != NULL){
		struct node * runner = ptrCurrent;
		struct node * temp = NULL;
		while(runner->pNext){
			if((runner->pNext)->data == ptrCurrent->data){
				temp = (runner->pNext)->pNext;
				free(runner->pNext);
				runner->pNext = temp;
			} else {
				runner = runner->pNext;
			}
		}
		ptrCurrent = ptrCurrent->pNext;
	}
}

struct node * getK(struct node * head, int k){
	struct node * runner = head;
	struct node * current = head;

	for(int i = 0; i < k && runner != NULL; i++){
		runner = runner->pNext;
	}

	while(runner != NULL){
		runner = runner->pNext;
		current = current->pNext;
	}
	return current;
}

void deleteFromMiddle(struct node **head, struct node * target){
	struct node * current = *head;
	while(current != NULL && current->pNext != target){
		current = current->pNext;
	}
	current->pNext = target->pNext;
	free(target);
}