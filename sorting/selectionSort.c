#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * pNext;
};

//prototypes
void swap(struct node ** head, struct node * p1, struct node * p2);
struct node * selectionSort(struct node ** head);
void printList(struct node* head);

int main(void){
	struct node * head = NULL;
	struct node n1;
	struct node n2;

	n1.data = 3;
	n2.data = ;
	n1.pNext = n2;
	n2.pNext = NULL;
	head = &n1;


	return 0;
}

struct node * selectionSort(struct node ** head){
	struct node * ptrSwap;
	struct node * ptrCurrent;
	struct node * ptrMin;

	ptrSwap = *head;
	
	while(ptrSwap != NULL){
		ptrCurrent = ptrSwap;
		ptrMin = ptrSwap;
		while(ptrCurrent != NULL){
			if(ptrCurrent->data < ptrMin->data){
				ptrMin = ptrCurrent;
			}
			ptrCurrent = ptrCurrent->pNext;
		}
		swap(head, ptrSwap, ptrMin);
		ptrSwap = ptrSwap->pNext;
	}
}

void swap(struct node ** head, struct node * p1, struct node * p2){
	if(p1 == *head){ // p1 is first element
		if(p1->pNext == p2){	
			p1->pNext = p2->pNext;
			p2->pNext = *head;
		    *head = p2;
		} else {
			// case: nonconsecutive pointers and p1 is first element
			struct node * afterLeft = p1->pNext;
			struct node * prevToRight = NULL;
			while(prevToRight->pNext != p2){
				prevToRight = prevToRight->pNext;
			}
			p1->pNext = p2->pNext;
			p2->pNext = afterLeft;
			prevToRight->pNext = p1;
			*head = p2;
		}
	} else { // p1 is not first element
		// case: consecutive pointers and p1 is not first element
		if(p1->pNext == p2){
			struct node *prevLeft = NULL;
			while(prevLeft->pNext != p1){
				prevLeft = prevLeft->pNext;
			}
			p1->pNext = p2->pNext;
			p2->pNext = p1;
			prevLeft->pNext = p2;
		} else { // the normal form of swap (p1 and p2 are in the middle)
			struct node * prevRight = NULL;
			struct node * prevLeft = NULL;
			struct node * afterLeft = NULL;

			while(prevLeft->pNext != p1){
				prevLeft= prevLeft->pNext;
			}
			while(prevRight->pNext != p1){
				prevRight= prevRight->pNext;
			}
			p1->pNext = p2->pNext;
			p2->pNext = afterLeft;
			prevRight->pNext = p1;
			prevLeft->pNext = p2;		
		}
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