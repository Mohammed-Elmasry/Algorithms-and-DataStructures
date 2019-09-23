#include "structs/node.c"
//prototypes
struct node * allocateNode(int key, char * value);
int delete(struct node** head, int key);
struct node * find(struct node* head, int key);
int orderedInsert(struct node ** head, int key, char * value);
void printList(struct node* head);
