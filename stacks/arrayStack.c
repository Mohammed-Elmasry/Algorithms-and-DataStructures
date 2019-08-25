#include <stdio.h>
#include <stdlib.h>

struct ArrayStack {
	int arr[5];
	int top;
};

//prototypes
int pop(struct ArrayStack * stack);
int hasNext(struct ArrayStack stack);
void printStack(struct ArrayStack stack);
int push (struct ArrayStack * stack, int element);
void transferStack(struct ArrayStack * source, struct ArrayStack * destination);
void stackInsertionSort(struct ArrayStack * stack);


int main(void){
	struct ArrayStack stack = {{}, 0};
	int result;
	push(&stack, 5);
	push(&stack, 2);
	push(&stack, 1);
	push(&stack, 4);

	stackInsertionSort(&stack);

	printStack(stack);
	return 0;
}

int push (struct ArrayStack * stack, int element){
	int retval = 0;
	if(stack->top < 5){
		stack->arr[stack->top] = element;
		stack->top++;
		retval = 1;
	} else {
		puts("end of stack reached!");
	}
	return retval;
}

void printStack(struct ArrayStack stack){
	for (int i = 0; i < stack.top; i++){
		printf("%d\n", stack.arr[i]);
	}
	printf("current stack top is %d\n", stack.top);
}	

int pop(struct ArrayStack * stack){
	int retval = -1; 
	if(stack->top > 0){	
		retval = stack->arr[stack->top - 1];
		stack->top--;
	} else {
		puts("stack is empty!");
	}
	return retval;
}

int hasNext(struct ArrayStack stack){
	return stack.top;
}

void transferStack(struct ArrayStack * source, struct ArrayStack * destination){
	while(hasNext(*source)){
		push(destination, pop(source));
	}
}

void stackInsertionSort(struct ArrayStack * stack){
	struct ArrayStack array = {{}, 0};
	int temp;
	for (int i = stack->top; i > 0; i--){
		temp = pop(stack);
		transferStack(stack, &array);
		for(int x = array.top; x > 0; x--){
			int current = pop(&array);
			if(temp < current){
				push(stack, temp);
				push(stack, current);
				transferStack(&array, stack);
			} else {
				push(stack, current);
			}
		}
	}
}