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
        nova->prox = inicio;
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

void removeLista(Pessoa *p){
    Pessoa *morta;
    morta= p->prox;
    if(p->prox == p || morta == NULL){
    /*    tem um so elemento ou lista vazia, nao matar*/
        return;
    }    
    else{
        while(morta != p->prox){
            morta = morta->prox;
        }
        p->prox =morta->prox;
        free(morta);
    
        
    }
}
void imprimeLista(){
    Pessoa *p = inicio;
    if(inicio != NULL){
        printf("%d ", p->posicao);
        
        for(p=p->prox;p->prox != inicio;p=p->prox){
            printf("%d ", p->posicao);
        }
            printf("\n");
    }
}
int main(){
    Pessoa *r= inicio;
    int i;
    for(i=1;i<=40;i++)
        insereLista(1);
      insereLista(2);
    imprimeLista();
   
   
    return 0;
}
