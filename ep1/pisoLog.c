#include <stdio.h>


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



int main() {
   printf("%d", pisoLog(40));
    return 0;
}