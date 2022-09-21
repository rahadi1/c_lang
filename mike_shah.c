/*
#include <stdio.h>

int main(){

 puts("Hello World\n");

	return 0;
}
*/

#include <stdio.h>
#include <assert.h>

void countdown(int n){

 assert(n >= 0 && "n was not greater than zero");
 if(n < 0){
 
  return;
 }

 printf("%d\n",n);
 return countdown(n-1);
}

int main(){

 countdown(10);
 return 0;
}
