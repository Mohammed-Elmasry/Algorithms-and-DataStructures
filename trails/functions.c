#include <stdio.h>

float plus (float x, float y){
   return x + y;
}

float minus (float x, float y){
   return x - y;
}

float multi (float x, float y){
   return x * y;
}

float divide(float x, float y){
    if(y != 0){
	return x / y;
    } else {
      puts("division by zero is not permissable");
      return 0;
    }
}
