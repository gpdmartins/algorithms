/*Nome: Jose Guilherme Pereira Dias Martins
**Curso: Topicos de Programação
**Curso de Verão 2017
*/
#include <stdio.h>
#include <string.h>
#include <locale.h>
//2.1
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
		printf("É palíndromo\n");
	}
	else
		printf("Não é palíndromo\n");
	return 0;
}
//2.2
int ult(char *str, int f){

	if(f==0){
        printf("%c", str[0]);

		return 0;
	}
	printf("%c", str[f]);
	//f--;


	return ult(str, --f);


}
int inversa(char *str){
	int f;
	f = strlen(str)-1;
	ult(str, f);

	return 0;
}
//2.3
int fib (int n){

	if(n==1 || n==0){
        return n;
	}
return fib(n-1)+ fib(n-2);
}

int fibonacci(int n){
  if(n==0){
    
      return 0;
  }
  int x;
  x = fibonacci(n-1);
  printf("%d ",fib(n-1));
  return x;
}
//2.4
int piso(int x, int n){

if (x==1||x==0){
    return n;
}
    
    return piso(x/2, ++n);
}
int pisoLog(int x)
{
    int n=0;
 
    return     piso(x, n);
}
