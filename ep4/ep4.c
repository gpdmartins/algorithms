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

int filaVazia(Fila *f){
    if (f->fim == NULL)
        return 1;
    return 0;
}

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
    No *morto;
    retorno = f->inicio;
    morto = retorno;
    f->inicio = f->inicio->prox;
    f->tamanho--;
    free(morto);
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
  
/*int * distancias(int m, int n, int **labirinto, int c){
    Fila *f;
    int *d;
    int j;
    No *atual;
    d = mallocSafe(n*sizeof(int));
    for (j = 0; j < n; j++)
        d[j] = n;
    d[c] = 0;
    insereFila(0, 0, f);
    while(!filaVazia(f)){
        if
    }
}*/



int resolveLabirinto (int labirinto[LIN][COL], int m, int n){
        No *visitados = mallocSafe(n*m*sizeof(No));
        int i;
        No *atual;
        Fila *f;
        int fim;
        for (i = 0; i< n*m;i++){
            (visitados[i]).linha = -1;
            (visitados[i]).coluna = -1;
        }
        i=0;
        insereFila(0,0,f);
        while(!filaVazia(f)){
            
            atual = removeFila(f);

            if(atual->linha = m-1 && atual->coluna == n-1)
                return f->tamanho;    

            visitados[i].linha = atual->linha;
            visitados[i].coluna = atual->coluna;
            i++;
            labirinto[atual->linha][atual->coluna] = -1;
            while(labirinto[atual->linha][atual->coluna+1] != 1 && atual->coluna+1 < n){
                if(atual->linha == 0 && atual->coluna+1){
                    insereFila(atual->linha, atual->coluna+1, f);
                labirinto[atual->linha][atual->coluna+1] = 2;
                }    
             }
             while(labirinto[atual->linha+1][atual->coluna] != 1 && atual->linha+1 < m){
                if(atual->linha == 0 && atual->coluna+1)
                    insereFila(atual->linha, atual->coluna+1, f);
             }

            
        /* ir colocando o caminho 
        }


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