#include <stdio.h>
#include <stdlib.h>

struct ArrayStack {
	int arr[5];
	int top;
};

//prototypes
int pop(struct ArrayStack * stack);
int push (struct ArrayStack * stack, int element);
void printStack(struct ArrayStack stack);


int main(void){
	struct  ArrayStack stack = {{}, 0};
	push(&stack, 3);
	push(&stack, 5);
	push(&stack, 1);
	push(&stack, 4);
	push(&stack, 2);

	int result = pop(&stack);
	result = pop(&stack);

	printf("result is %d\n", result);
	printStack(stack);
	return 0;
}

int push (struct ArrayStack * stack, int element){
	int retval = 0;
	if(stack->top <= 4){
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