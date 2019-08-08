#include <stdio.h>
#include <stdlib.h>




struct node {
	int data;
	struct node * pNext;
};

//prototypes
int push(struct node** top, int value);
void printStack(struct node* top);
int pop(struct node** top);

int main(void){
	struct node * pTop = NULL;
	push(&pTop, 3);
	push(&pTop, 8);
	push(&pTop, 11);
	pop(&pTop);
	pop(&pTop);
	pop(&pTop);
	printStack(pTop);
	return 0;
}

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


int pop(struct node** top){
	int retval = -1;
	struct node * pTemp = *top;
	*top = pTemp->pNext;
	retval = pTemp->data;
	free(pTemp);
	return retval;
}

