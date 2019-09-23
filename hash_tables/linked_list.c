#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/linked_lists.h"

void printList(struct node* head){
	while(head != NULL){
		printf("%d --> ", head->data);
		head = head->pNext;
	}
	printf(" NULL");
	printf("\n");
}

int delete(struct node** head, int key){
	int retval = 0;
	struct node* temp;
	struct node* ptrPrev = NULL;
	if(*head == NULL){
		printf("List is Empty!\n");
	} else {
		temp = *head;
		while(temp != NULL && temp->key != key){
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
			printf("Deletion failed, key %c not found!\n", key);
		}
	}
	return retval;
}

struct node * find(struct node* head, int key){
	struct node* ptr = head;
	while(ptr != NULL){
		if(ptr->key == key){
			return ptr;
		}
		ptr = ptr->pNext;
	}
	return ptr;	
}

int orderedInsert(struct node ** head, int key, char * value){
	int retval = 0;
	struct node * ptrNew = (struct node *)malloc(sizeof(struct node));
	if(ptrNew){
		ptrNew->key = key;
		ptrNew->val = value;
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
		printf("pair not inserted, memory allocation failed");
	}

	return retval;
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