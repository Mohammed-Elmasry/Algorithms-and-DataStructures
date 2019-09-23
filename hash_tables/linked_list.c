#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/linked_lists.h"

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
		printf("%d --> ", head->data);
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

void deleteFromMid(struct node * target){
	struct node * temp = target->pNext;
	target->data = temp->data;
	target->pNext = temp->pNext;
	free(temp);
}

void partitionBefore(struct node **head, int target){
	struct node * current = *head;
	while(current->pNext){
		if((current->pNext)->data < target){
			struct node * temp = current->pNext;
			current->pNext = temp->pNext;
			temp->pNext = *head;
			*head = temp;
		} else {
			current = current->pNext;
		}
	}
}

int sumListsReversed(struct node * head1, struct node * head2){
	int sum = 0;
	int counter = 1;
	struct node * current1, *current2;
	current1 = head1, current2 = head2;
	struct node * newHead = NULL;
	while(current1 != NULL && current2 != NULL){
		sum = sum + (current1->data * counter) + (current2->data * counter);
		current1 = current1->pNext;
		current2 = current2->pNext;
		counter = counter * 10;
	}
	while(sum != 0){
		append(&newHead, sum % 10);
		sum = sum / 10;
	}
	printList(newHead);
	return 0;
}

int sumLists(struct node * head1, struct node * head2){
	int sum = 0;
	struct node * current1, *current2;
	current1 = head1, current2 = head2;
	struct node * newHead = NULL;
	while(current1 != NULL && current2 != NULL){
		sum = sum * 10 + current1->data + current2->data;
		current1 = current1->pNext;
		current2 = current2->pNext;
	}
	while(sum != 0){
		append(&newHead, sum % 10);
		sum = sum / 10;
	}
	puts("result reversed is: ");
	printList(newHead);
	return 0;
}

int isPalindrome(struct node * head){
	int retval = 0;
	int counter = 0;
	struct node * ptr = head;
	struct node * handler = NULL;
	struct node * newHead = NULL;
	while(ptr != NULL){
		handler = (struct node *) malloc(sizeof(struct node));
		if(handler){
			handler->data = ptr->data;
			handler->pNext = newHead;
			newHead = handler;
			counter++;
			ptr = ptr->pNext;
		} else {
			printf("Memory allocation failed\n");
			return -1;
		}
	}
	puts("until here.. we're ok");
	counter = counter / 2;
	handler = newHead;
	ptr = head;
	for (int i = 0; i < counter; i++){
		if(handler->data != ptr->data) {return retval;}
		ptr++;
		handler++;
	}
	retval = 1;
	return retval;
}

int isPalindromeWithStack(struct node * head){
	struct node * runner, * slow;
	slow = head;
	runner = head;

	// declare the stack
	struct node * stackTop = NULL;
	while(runner != NULL && runner->pNext){
		push(&stackTop ,slow->data);
		runner = (runner->pNext)->pNext;
		slow = slow->pNext;
	}

	if(runner != NULL){
		slow = slow->pNext;
	}
	while (slow != NULL){
		if(!(pop(&stackTop) == slow->data)){
			return 0;
		}
		slow = slow->pNext;		
	}
	return 1;
}

/*
	stack related functions ... usable in applications of other
	data structures and alogorithms
*/
int push(struct node** top, int value){
	int retval = 0;
	struct node* ptrNew = (struct node*) malloc(sizeof(struct node));
	if(ptrNew){ // if allocated successfully
		ptrNew->data = value;
		ptrNew->pNext = *top; //whatever the top is looking at
		*top = ptrNew;
		retval = 1;
	} else {
		printf("%d not pushed, memory allocation failed!\n", value);
	}
	return retval;
}


int pop(struct node** top){
	int retval = -1;
	struct node * pTemp = *top;
	*top = pTemp->pNext;
	retval = pTemp->data;
	free(pTemp);
	return retval;
}

void printStack(struct node* top){
	if (top == NULL){
		puts("The stack is empty!");
	} else {
		puts("The stack is: ");
		while(top != NULL){
			printf(" %d -->", top->data);
			top = top->pNext;
		}	
		printf(" NULL\n");
	}
}

struct node * isIntersected(struct node * head1, struct node * head2){
	struct node * ptr1, *ptr2;
	ptr1 = head1; ptr2 = head2;
	int length1 = 0, length2 = 0;

	while(ptr1 != NULL){
		length1++;
		ptr1 = ptr1->pNext;
	}

	while(ptr2 != NULL){
		length2++;
		ptr2 = ptr2->pNext;
	}
	
	if(!(ptr1 == ptr2)){
		return NULL;
	}
	ptr1 = head1; ptr2 = head2;

	if(length1 > length2){
		for(int i = 0; i < length1 - length2; i++){
			ptr1 = ptr1->pNext;
		}
	} else {
		for(int i = 0; i < length2 - length1; i++){
			ptr2 = ptr2->pNext;

		}
	}

	while(ptr1 != NULL && ptr2 != NULL){
		if(ptr1 == ptr2){
			return ptr1;
		}
		ptr1 = ptr1->pNext;
		ptr2 = ptr2->pNext;
	}
	return NULL;
}

struct node * allocateNode(int value){
	struct node * ptr = (struct node *)malloc(sizeof(struct node));
	if(ptr){
		return ptr;
	} else {
		strerror(errno);
		return NULL;
	}
}