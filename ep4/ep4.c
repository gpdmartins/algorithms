#include <stdio.h>
#include <stdlib.h>

#define LIN 3
#define COL 3

void *mallocSafe(int nbytes){
    void *ptr;
    ptr = malloc(nbytes);
    if(ptr == NULL){
        printf("Erro, malloc NULL\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

typedef struct no No;
struct no{
    int linha;
    int coluna;
    No *prox;
};

typedef struct fila Fila;
struct fila{
    No *inicio;
    No *fim;
    int tamanho;
};

void insereFila (int linha, int coluna, Fila *f){
    No *aux = mallocSafe(sizeof(No));
    if (f == NULL){
    f = mallocSafe(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
    }
    aux->linha = linha;
    aux->coluna = coluna;
    aux->prox = NULL;
    if(f->fim == NULL){
        f->inicio = aux;
        f->fim = aux;
    }
    else{
        (f->fim)->prox = aux;
        f->fim = (f->fim)->prox;
    }
    f->tamanho++;
}

No *removeFila (Fila *f){
    No *retorno;
    retorno = f->inicio;
    f->inicio = f->inicio->prox;
    f->tamanho--;
    return retorno;
}
void imprimeFila (Fila *f){
    No *aux = f->inicio;
    int i;
    for(i = 0; i < f->tamanho;i++){
        printf("(%d , %d) ", aux->linha, aux->coluna);
        aux = aux->prox;
    }
    if (i> 0)
        printf("\n");
}
int resolveLabirinto (int labirinto[LIN][COL], int m, int n){
    int *atual = labirinto[0][0];
    int *passo;
    
}

int main(){
    Fila *f = mallocSafe(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
    insereFila(0, 0, f);
    insereFila(1, 2, f);
    insereFila(1, 3, f);
    
            /*printf("(%d , %d) ", (f->inicio)->linha, (f->inicio)->coluna);*/
    imprimeFila(f);
    removeFila(f);
    imprimeFila(f);
    removeFila(f);
    imprimeFila(f);
    removeFila(f);
    imprimeFila(f);
    return 0;
}