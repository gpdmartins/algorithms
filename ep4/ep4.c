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

void iniciaFila(Fila *f){
    f = mallocSafe(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}

int filaVazia(Fila *f){
    if (f->tamanho == 0)
        return 1;
    return 0;
}

void insereFila (int linha, int coluna, Fila *f){
    No *aux = mallocSafe(sizeof(No));
    
    aux->linha = linha;
    aux->coluna = coluna;
    aux->prox = NULL;
    if(f->inicio == NULL){
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
    No *morto;
    No *retorno = mallocSafe(sizeof(No));

    if(!filaVazia(f)){
    retorno->linha = (f->inicio)->linha;
    retorno->coluna = (f->inicio)->coluna;
    retorno->prox = (f->inicio)->prox;
    morto = f->inicio;
    f->inicio = f->inicio->prox;
    f->tamanho--;
    free(morto);
    return retorno;
    }
    return NULL;
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

        
        No *atual = mallocSafe(sizeof(No));
        Fila *f = mallocSafe(sizeof(Fila));
        
        
        iniciaFila(f);    
        insereFila(0,0,f);
                                           
        while(!filaVazia(f)){
            /*atual = mallocSafe(sizeof(No));*/
            
            atual = removeFila(f);

            if(atual->linha == m-1 && atual->coluna == n-1){
                printf("Distancia: %d\n", labirinto[m-1][n-1]);
                return labirinto[m-1][n-1];    
            }
            
            if(labirinto[atual->linha][atual->coluna+1] == 0 && (atual->coluna)+1 < n){
                
                    insereFila(atual->linha, (atual->coluna)+1, f);
                labirinto[atual->linha][atual->coluna+1] = labirinto[atual->linha][atual->coluna]+1;
                } /* direita */    
             
             if(labirinto[atual->linha][(atual->coluna)-1] == 0 && atual->coluna-1 >= 0){
                
                    insereFila(atual->linha, (atual->coluna)-1, f);
                labirinto[atual->linha][(atual->coluna)+1] = labirinto[atual->linha][atual->coluna]+1;
                }    /* esquerda */
             
             if(labirinto[(atual->linha)+1][atual->coluna] == 0 && atual->linha+1 < m){
                
                    insereFila((atual->linha)+1, atual->coluna, f);
                labirinto[(atual->linha)+1][atual->coluna] = labirinto[atual->linha][atual->coluna]+1;
                }    /* baixo */
             if(labirinto[(atual->linha)-1][atual->coluna] == 0 && (atual->linha) -1 >= 0){
                
                    insereFila((atual->linha)-1, atual->coluna, f);
                labirinto[(atual->linha)-1][atual->coluna] = labirinto[atual->linha][atual->coluna]+1;
                }    /* cima */   
        }    
         
        return -1;


    }



int main () {
int m , n ;

/* Declaracao dos labirintos */

int labirinto1 [3][3] = { {0 ,1 ,1} , {0 ,0 ,0} , {1 ,0 ,0}};
/* int labirinto2 [4][4] = { {0 ,0 ,1 ,1} , {1 ,0 ,0 ,0} ,
{1 ,0 ,1 ,0} , {1 ,0 ,0 ,0}};
int labirinto3 [5][6] = { {0 ,0 ,1 ,0 ,1 ,1} , {1 ,0 ,0 ,0 ,1 ,0} ,
{1 ,1 ,0 ,1 ,0 ,0} , {1 ,0 ,0 ,0 ,0 ,1} , {1 ,1 ,1 ,1 ,0 ,0}}; */
m = 3;
n = 3;
resolveLabirinto ( labirinto1 , m , n );

m = 4;
n = 4;
/* resolveLabirinto ( labirinto2 , m , n ) ; */
m = 5;
n = 6;
/* resolveLabirinto ( labirinto3 , m , n ) ; */
return 0;
}