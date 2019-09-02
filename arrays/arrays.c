#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//prototypes
int getMode(int * array, long unsigned int size);
char * replace(char * string, int size);

int main(void){
	char arr[] = "Mr John Smith";
	strtok(arr, " ");
	printf("%s\n", arr);
	strtok(NULL, " ");
	printf("%s\n", arr);
	printf("%d\n", (int) (7 / 2));
	return 0;
}

int getMode(int * array, long unsigned int size){
	int current_item_freq = 0;
	int best_item_freq = 0;
	int current_item = array[0];
	int best_item = 0;
	for (int i = 0; i < size; ++i){		
		if(array[i] != current_item || i == size-1){ // found new element
			if(current_item_freq > best_item_freq){
				best_item_freq = current_item_freq;
				best_item = current_item;	
			}
			current_item = array[i];
			current_item_freq = 0;
		}	
		current_item_freq++;
	}
	return best_item;
}

// char * replace(char * string, int size){
// 	char qs[] = "%20";
// 	int space_count = 0;
// 	for (int i = 0; i < size; ++i){
// 		if(string[i] == ' '){
// 			space_count++;
// 		}
// 	}
// 	size  = (size - space_count) + (space_count * 3);
// 	char * myString = (char *) malloc(size);
// 	for (int i = 0; i < size - 1; ++i){
// 		if(string[i] != ' '){
// 			strcat(myString, (char *) string[i]);
// 		} else {
// 			strcat(myString, qs);
// 		}
// 	}
// 	strcat(myString, '\0');
// 	return myString;
// }

/*
*** preparation
create a string = "%20"
1 count the number of spaces in the input string (X 3) (space-count)
2 count the number of non-space characters (char-count)
3 sum the number of characters (both variables).
4 allocate memory enough to account for all those letters.

5 concatinate the original parts of the string with "%20" respectively and eventually
append "\0" or last appending is using the strncat() to append "\0" automatically.

*/