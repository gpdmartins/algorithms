#include <stdio.h>

int fib (int n){

	if(n==1 || n==0){
        return n;
	}
return fib(n-1)+ fib(n-2);
}

int fibonacci(int n){
  if(n==0){
    //  printf("%d ",0);
      return 0;
  }
  int x;
  x = fibonacci(n-1);
  printf("%d ",fib(n-1));
  return x;
}

	int main(){

		fibonacci(10);
		return 0;
	}
