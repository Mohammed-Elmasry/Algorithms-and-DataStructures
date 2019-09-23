#include "structs/node.c"
//prototypes
int delete(struct node** head, char value);
int orderedInsert(struct node ** head, char value);
struct node * find(struct node* head, char value);
struct node * allocateNode(int value);
