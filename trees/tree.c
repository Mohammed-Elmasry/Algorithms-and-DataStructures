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
struct node * initializeNode(int data);
void preOrderTraverseTree(struct node * root);
void inOrderTraverseTree(struct node * const root);
void postOrderTraverseTree(struct node * const root);
int insertNode(struct node ** root, int value);
int treeInsertNode(struct node ** root, int value);

int main(int argc, char * argv[]){
	// struct node * ptr = initializeNode(4);
	struct node *root = NULL;

	treeInsertNode(&root, 5);
	treeInsertNode(&root, 4);
	treeInsertNode(&root, 6);
	treeInsertNode(&root, 22);
 	
	puts("preOrder...");
	preOrderTraverseTree(root);
	
	puts("inOrder...");
	inOrderTraverseTree(root);
	
	puts("postOrder...");
	postOrderTraverseTree(root);
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

int insertNode(struct node ** root, int value){
	int retval = 0; 
	//if there's no tree to begin with..
	if(*root == NULL){
		*root = (struct node *)malloc(sizeof(struct node));
		if(*root){
			(*root)->data = value;
			(*root)->left = NULL;
			(*root)->right = NULL;
			retval = 1;
		} else {
			printf("%s\n" ,strerror(ENOMEM));
		}
	} else {
		if(value < (*root)->data){
			insertNode(&((*root)->left), value);
		} else if(value > (*root)->data){
			insertNode(&((*root)->right), value);
		} else {
			printf("%s", "dup");
		}
	}
	return retval;
}


void preOrderTraverseTree(struct node * const root){
	if(root){
		printf("%d\n", root->data);
		preOrderTraverseTree(root->left);
		preOrderTraverseTree(root->right);
	}
}

void inOrderTraverseTree(struct node * const root){
	if(root){
		inOrderTraverseTree(root->left);
		printf("%d\n", root->data);
		inOrderTraverseTree(root->right);
	}

}

void postOrderTraverseTree(struct node * const root){
	if(root){
		postOrderTraverseTree(root->left);
		postOrderTraverseTree(root->right);
		printf("%d\n", root->data);
	}
}


int treeInsertNode(struct node ** root, int value){
	int retval = 0;
	//if there's no tree to begin with
	if(*root == NULL){
		*root = (struct node *)malloc(sizeof(struct node));
		if(*root){
			(*root)->data  = value;
			(*root)->left  = NULL;
			(*root)->right = NULL;
			retval = 1;
		} else {
			printf("%s\n", strerror(ENOMEM));
		}
	} else {
		if((*root)->left == NULL){
			treeInsertNode(&((*root)->left), value);
		}
		else if((*root)->right == NULL){
			treeInsertNode(&((*root)->right), value);
		} else {
			treeInsertNode(&((*root)->left), value);
		}
	}
	return retval;
}

