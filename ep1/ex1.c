#include <string.h>
#include <stdio.h>
int igual(char *n, int i, int f){
	if(i>=f)
	return 1;

	if(n[i]==n[f]){
		return igual(n,i+1,f-1);
	}
	return 0;
}
int palindromo (char *n){
	if (igual(n, 0,strlen(n)-1)){
		printf("E palindromo");
	}
	else
		printf("nao eh palindromo");
	return 0;
}


int main(){
    palindromo("abacate");



return 0;
}
