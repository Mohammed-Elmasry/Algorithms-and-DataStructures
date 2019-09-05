#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * right;
	struct node * left;
};

//prototypes
void displayNode(struct node n);
void traverseTree(struct node root);
struct node * initializeNode(int data);

int main(int argc, char * argv[]){
	struct node * ptr = initializeNode(4);
	struct node root = *initializeNode(7);
	traverseTree(root);
	// displayNode(*ptr);
	return 0;
}

struct node * initializeNode(int data){
	struct node * ptr = (struct node *) malloc(sizeof(struct node));
	if(ptr){
		ptr->data  = data;
		ptr->right = NULL;
		ptr->left  = NULL;
		return ptr;
	} else {
		return (struct node *) strerror(ENOMEM);
	}
}

void displayNode(struct node n){
	printf("data member is : %d\n", n.data);
	printf("right child is %p\n", n.right);
	printf("left child is %p\n", n.left);
}

void traverseTree(struct node root){
	printf("%d\n", root.data);
	if(root.left){
		traverseTree(*(root.left));
	}
	if(root.right){
		traverseTree(*(root.right));
	}

}