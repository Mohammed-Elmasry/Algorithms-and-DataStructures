#include "structs/node.c"
//prototypes
void printList(struct node* head);
void reverse(struct node ** head);
void destroyList(struct node** head);
int getLength(struct node * head);
int append(struct node** head, char value);
int delete(struct node** head, char value);
int add(struct node** head, char value);
int orderedInsert(struct node ** head, char value);
int insertAt(struct node** head, int index, char value);
struct node * find(struct node* head, char value);
void removeDuplicates(struct node ** head);
void runnerRemoveDuplicates(struct node ** head);
struct node * getK(struct node * head, int k);
void deleteFromMiddle(struct node **head, struct node * target);
void deleteFromMid(struct node * target);
void partitionBefore(struct node **head, int target);
int sumLists(struct node * head1, struct node * head2);
int sumListsReversed(struct node * head1, struct node * head2);
int isPalindrome(struct node * head);
int isPalindromeWithStack(struct node * head);
int pop(struct node** top);
int push(struct node** top, int value);
void printStack(struct node* top);
struct node * isIntersected(struct node * head1, struct node * head2);
