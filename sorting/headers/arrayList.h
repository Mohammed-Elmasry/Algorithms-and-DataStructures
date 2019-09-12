//structures
#include "structs/arrayList.c"


//arraylist prototypes
int assignIntList(struct intArrayList * list, int * array, int arraySize, int arrayElementCount);
void printArrayList(struct intArrayList list);
int appendIntArrayList(struct intArrayList * list, int value);
void printArrayListElements(struct intArrayList list);
int * expandAndCopy(struct intArrayList list);
void swapRight(struct intArrayList * list, int index);
int insertIntoArrayList(struct intArrayList * list, unsigned int index, int value);
int * contractAndCopy(struct intArrayList list);
int pop(struct intArrayList * list);
void swapLeft(struct intArrayList * list, int index);
int removeFromArrayList(struct intArrayList * list, unsigned int index);
