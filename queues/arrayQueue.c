#include <stdio.h>
#include <stdlib.h>

struct Queue {
	int arr[6] = {};
	int head;
};

//prototypes
int dequeue(struct Queue * que);
int enqueue(struct Queue * que, int element);
void printQueue(struct queue que, unsigned int size);
void initializeQueue(struct Queue * que, unsigned int size);


int main(int argc, char argv[]){
	struct Queue q = {{}, 5};
	return 0;
}

int enqueue(struct Queue * que, int element){

}

int dequeue(struct Queue * que){

}

void initializeQueue(struct Queue * que, unsigned int size){
	que->arr = {};
	que->head = size - 1;
}

void printQueue(struct queue que, unsigned int size){
	for (int i = que.head; i < size - 1; ++i){
		printf("%d ", que.arr[i]);
	}
	puts("display complete...");
}