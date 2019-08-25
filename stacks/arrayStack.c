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


int main(void){
	struct  ArrayStack stack = {{}, 0};

	int result;
	push(&stack, 18);
	result = hasNext(stack);
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

int hasNext(struct ArrayStack stack){
	return stack.top;
}