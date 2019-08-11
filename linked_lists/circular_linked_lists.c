#include <stdio.h>
#include <stdlib.h>


struct node {
	char data;
	struct node * pNext;
};
//prototypes
void printList(struct node * head);
void flattenList(struct node * head);

int main(void){
	struct node * pHead;
	struct node n1, n2, n3;
	n1.data = 'A';
	n2.data = 'B';
	n3.data = 'C';

	n1.pNext = &n2;
	n2.pNext = &n3;
	n3.pNext = &n1;
	pHead = &n1;
	printList(pHead);
	flattenList(pHead);
	printList(pHead);
	return 0;
}

void printList(struct node * head){
	int i = 0;
	while(head != NULL && i < 6){
		i++;
		printf("%c --> ", head->data);
		head = head->pNext;
	}
	puts(" Null ");
}

void flattenList(struct node * head){
	struct node * marker = head;
	while(marker!= NULL && marker->pNext){
		if(marker->pNext == head){
			marker->pNext = NULL;
		}
		marker = marker->pNext;
	}
}