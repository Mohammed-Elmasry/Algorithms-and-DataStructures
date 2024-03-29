#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * pNext;
};

//prototypes
void swap(struct node ** head, struct node * p1, struct node * p2);
struct node * selectionSort(struct node ** head);
struct node * find(struct node* head, int value);
void printList(struct node* head);

int main(void){
	struct node * head = NULL;
	struct node n1;
	struct node n2;
	struct node n3;
	struct node n4;

	n1.data = 3;
	n2.data = 4;
	n3.data = 1;
	n4.data = 2;

	n1.pNext = &n2;
	n2.pNext = &n3;
	n3.pNext = &n4;
	n4.pNext = NULL;

	head = &n1;

	printList(head);
	selectionSort(&head);
	printList(head);
	return 0;
}

struct node * selectionSort(struct node ** head){
	struct node * ptrSwap; // marks the element to swap with minimum
	struct node * ptrCurrent; // current scanner pointer
	struct node * ptrMin; // pointer to minimum value

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
		ptrSwap = ptrMin->pNext;
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
			struct node * prevToRight = *head;
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
			struct node *prevLeft = *head;
			while(prevLeft->pNext != p1){
				prevLeft = prevLeft->pNext;
			}
			p1->pNext = p2->pNext;
			p2->pNext = p1;
			prevLeft->pNext = p2;
		} else { // the normal form of swap (p1 and p2 are in the middle)
			struct node * prevRight = *head;
			struct node * prevLeft = *head;
			struct node * afterLeft = p1->pNext;

			while(prevLeft->pNext != p1){
				prevLeft = prevLeft->pNext;
			}
			while(prevRight->pNext != p2){
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
		printf("%d --> ", head->data);
		head = head->pNext;
	}
	printf(" NULL");
	printf("\n");
}

struct node * find(struct node* head, int value){
	struct node* ptr = head;
	while(ptr != NULL){
		if(ptr->data == value){
			return ptr;
		}
		ptr = ptr->pNext;
	}
	return ptr;	
}