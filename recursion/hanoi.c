#include <stdio.h>
void tower(int n, char fromPeg, char toPeg, char auxPeg);

int main(int argc, char * argv[]){


	tower(3, 'A', 'B','C');
	return 0;
}


void tower(int n, char fromPeg, char toPeg, char auxPeg){
	
	if(n == 1){ //base case
		printf("Move peg 1 from %c to %c\n", fromPeg, toPeg);
		return;
	} else {
		tower(n-1, fromPeg, auxPeg, toPeg);
		printf("Move peg %d from %c to %c\n", n, fromPeg, toPeg);
		tower(n-1, auxPeg, toPeg, fromPeg);
	}
}