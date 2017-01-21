#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa Pessoa;
struct pessoa{
    int posicao;
    Pessoa *prox;
};
 Pessoa *inicio = NULL;
void *mallocSafe (int nbytes){
    void *ptr;
    ptr = malloc(nbytes);
    if (ptr == NULL){
        printf("Erro, malloc devolveu NULL!\n");
        exit(EXIT_FAILURE);
        }
    return ptr;
}

void insereLista (int x){
    Pessoa *nova, *p;
    nova = mallocSafe(sizeof(Pessoa));
    nova->posicao = x;
    if (inicio == NULL){
        inicio = nova;
        nova->prox = nova;
    }
    else{
        p = inicio;
        /*adicionar por ultimo. verificar se estou mexendo no ponteiro inicio.*/
        while(p->prox != inicio)
            p = p->prox;
        nova->prox = inicio;
        p->prox = nova;
    }


}

int main(){
/*    Pessoa *inicio;
    inicio = NULL;
*/
    return 0;
}
