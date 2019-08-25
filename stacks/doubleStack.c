#include <stdio.h>
#include <stdlib.h>


struct DoubleStack {
	char arr[10];  // 0 to 4 , 5 to 9
	int topLeft;
	int topRight;
	int size;
};

// prototypes
int push (struct DoubleStack * stack, char c, char * flag);


int main(void){

	//initialization for the stack
	struct DoubleStack stack = {{},0,9,10};
	push(&stack, 'A', "left");
	push(&stack, 'P', "left");
	push(&stack, 'P', "left");
	push(&stack, 'L', "left");
	push(&stack, 'E', "left");
	push(&stack, 'A', "Right");
	push(&stack, 'A', "Right");
	push(&stack, 'A', "Right");
	push(&stack, 'A', "Right");
	push(&stack, 'A', "Right");
	push(&stack, 'A', "Right");

	printf("%c\n", stack.arr[0]);
	return 0;
}



int push (struct DoubleStack * stack, char c, char * flag){
	int retval = 0;
	if(flag == "left"){
		if(stack->topLeft < (stack->size) / 2){
			stack->arr[stack->topLeft] = c;
			stack->topLeft++;
			retval = 1;	
		} else {
			puts("top of stack reached!");
			retval = 0;
		}		
	} else {
		if(stack->topRight >= (stack->size) / 2){
			stack->arr[stack->topRight] = c;
			stack->topRight--;
			retval = 1;	
		} else {
			puts("right top of stack reached!");
			retval = 0;
		}
	}
	return retval;
}
