#include <math.h>
int palindromo(int n)
{
    if(pal(n)==n)

        printf("\220 pal\641ndromo\n");

    else
        printf("N\706o \202 pal\641ndromo\n");
}

int pal(int n){
 if(n>9){
    int y = log10(n);
    return (n%10)*pow(10,y) + pal(n/10);
}
return n;
}




int main(){
    palindromo(123321);
return 0;
}
