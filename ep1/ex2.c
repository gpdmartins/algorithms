#include <string.h>
#include <stdio.h>
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

int main()
{
    inversa("abacate");
    return 0;


}
