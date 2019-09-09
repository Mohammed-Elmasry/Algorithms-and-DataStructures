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
void traverseTree(struct node * root);
struct node * initializeNode(int data);

int main(int argc, char * argv[]){
	// struct node * ptr = initializeNode(4);
	struct node *root = initializeNode(1);
	struct node *n2   = initializeNode(2);
	struct node *n3   = initializeNode(3);
	struct node *n4   = initializeNode(4);
	struct node *n5	  = initializeNode(5);
	struct node *n6   = initializeNode(6);
	struct node *n7   = initializeNode(7);

	root->left  = n2;
	root->right = n5;
	n2->left    = n3;
	n2->right   = n4;
	n5->left    = n6;
	n5->right   = n7;

	traverseTree(root);

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

void traverseTree(struct node * const root){
	if(root){
		printf("%d\n", root->data);
		traverseTree(root->left);
		traverseTree(root->right);
	}
}