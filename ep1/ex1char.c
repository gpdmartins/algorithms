#include <string.h>
#include <stdio.h>
#include <locale.h>
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
		//printf("\220 pal\641ndromo\n");
		printf("É palíndromo\n");
	}
	else
	//printf("N\706o \202 pal\641ndromo\n");
	printf("Não é palíndromo\n");
	return 0;
}
int main(){
    palindromo("abacate");



return 0;
}
