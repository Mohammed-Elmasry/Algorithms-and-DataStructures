#include <stdio.h>
#include <stdlib.h>

struct Queue {
	int arr[6];
	int head;
};

//prototypes
int dequeue(struct Queue * que);
void swapLeft(struct Queue * que, unsigned int size);
void printQueue(struct Queue que, unsigned int size);
void initializeQueue(struct Queue * que, unsigned int size);
int enqueue(struct Queue * que, int element, unsigned int size);


int main(int argc, char * argv[]){
	struct Queue q;
	int length = sizeof(q.arr) / sizeof(int);
	initializeQueue(&q, length);

	enqueue(&q, 5, length);
	enqueue(&q, 19, length);
	enqueue(&q, 8, length);
	enqueue(&q, 3, length);
	enqueue(&q, 2, length);
	enqueue(&q, 1, length);
	enqueue(&q, 0, length);

	printQueue(q, length);
	return 0;
}

int enqueue(struct Queue * que, int element, unsigned int size){
	int retval = 0;
	//first check if enqueue is possible...
	if(que->head > 0){
		swapLeft(que, size);
		que->head--;
		que->arr[size - 1] = element;
		retval = 1;
	} else {
		puts("enqueue failed, no space to insert item!");
	}
	return retval;
}

int dequeue(struct Queue * que){
	int retval = 0;

	return retval;
}

void initializeQueue(struct Queue * que, unsigned int size){
	que->head = size;
}

void printQueue(struct Queue que, unsigned int size){
	for (int i = que.head; i < size; ++i){
		printf("%d \n", que.arr[i]);
	}
	puts("display complete...");
}

void swapLeft(struct Queue * que, unsigned int size){
	if(que->head > 0){
		for(int i = que->head; i < size; i++){
			que->arr[i-1] = que->arr[i];
		}
	}
}