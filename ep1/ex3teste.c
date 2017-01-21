int fibonacci(int n){
    int i = 0;
    int j;
    for(;i<=n;i++)
        printf("%d ",fib(i));

}

int fib (int n){

	if(n==1 || n==0){
        return n;
	}
return fib(n-1)+ fib(n-2);
}

	int main(){

		fibonacci(4);
		return 0;
	}
