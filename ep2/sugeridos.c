#include <stdio.h>
#include <stdlib.h>

int busc (int x, int n, int v[]){
    if(n < 0) return 0;
    if (v[n-1] == x) return 1;
    else return busc(x, n-1, v);

}

int f (int *v, int n){
    int m;
    if (n==0) return 0;
    m = f (v, n-1);
    if (v[n-1] == 0) return m;
    v[m] = v[n-1];
    return m+1;
}

typedef struct lista Lista;
struct lista{
    int valor;
    Lista *prox;
};
void insere (int x, Lista *p){
    int *aux;
    aux = malloc(sizeof(Lista));
    if(p == NULL){
        p = aux;
        p->prox = NULL;
    }
    else{
        aux->prox = p;
        p = aux;
    }
}
void removeprox(Lista *p){ /* nao remove o primeiro!*/
    Lista *aux;
    aux = p->prox;
    p->prox = aux->prox;
    free (aux);
}
void *imprimeLista(Lista *p){
    if(p == NULL) return;
    printf("%d ", p->valor);
    imprimeLista(p->prox);
}

/*function to remove all elements containning x*/


void removeX (int x, Lista *p){
    Lista *aux = p;
    if(p->valor == x){ /* se for o primeiro, remove */
        aux = p;
        p = p->prox;
        free(aux);
        aux = p;
    }
    while(aux != NULL){ /* se x for um dos seguintes, e nao nulo, remove.*/
        if ((aux->prox)->valor == x){
            
            aux = aux->prox;
            p->prox =aux->prox;
            free (aux);
            aux = p;
        }
        else{
            p = p->prox;
            aux = p;
        }
    }
}


void concatenaListas (Lista **p, Lista **q){
    Lista *aux = *p;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = *q;
}

int main(){
int v[] = {1,2,3};

    printf("%d\n", f(v, 3));
    printf("%d %d %d", v[0], v[1], v[2]);
    return 0;
}
