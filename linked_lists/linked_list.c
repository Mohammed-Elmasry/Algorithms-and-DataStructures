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
void deleteFromMid(struct node * target);
void partitionBefore(struct node **head, int target);
int sumLists(struct node * head1, struct node * head2);
int sumListsReversed(struct node * head1, struct node * head2);

int main(void){

	struct node * pHead = NULL;
	
	// append(&pHead, 'C');
	// append(&pHead, 'C');
	// append(&pHead, 'Z');
	// append(&pHead, 'A');
	// append(&pHead, 'N');
	// append(&pHead, 'S');	
	// append(&pHead, 'P');	
	// append(&pHead, 'Z');
	// append(&pHead, 'L');	
	// append(&pHead, 'L');	
	// append(&pHead, 'S');
	// append(&pHead, 'H');
	// append(&pHead, 'Q');
	// append(&pHead, 'R');
	// append(&pHead, 'T');

	struct node n1, n2, n3, n4, n5, n6;
	struct node * pHead2 = NULL;
	n1.data = 3;
	n2.data = 7;
	n3.data = 5;
	n4.data = 1;
	n5.data = 2;
	n6.data = 7;

	n1.pNext = &n2;
	n2.pNext = &n3;
	n3.pNext = NULL;
	n4.pNext = &n5;
	n5.pNext = &n6;
	n6.pNext = NULL;

	pHead = &n1;
	pHead2 = &n4; 

	printList(pHead);
	// partitionBefore(&pHead, 5);
	int sum = sumLists(pHead, pHead2);
	printList(pHead2);
	printf("%d is the sum\n", sum);
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