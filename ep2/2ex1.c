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
    p->prox = morta->prox;
    free(morta);
        
}

void imprimeLista(){
    Pessoa *printa;
    if(inicio == NULL)
        printf("lista vazia!");
    else{
        
        for(printa=inicio; printa->prox != inicio; printa = printa->prox){
            printf("%d ", printa->posicao);

        }
        printf("%d ", printa->posicao);
            
    }
    printf("\n");
}

void resolveJosephus(int n, int m){
    int i, k, j;
        
    Pessoa *killer, *suicida;
    /*inserindo n pessoas*/
    for (i = 1; i <=n; i++)
        insereLista(i);
    imprimeLista();
    
    /*anda ate matar n-1*/
        
    killer = inicio;
    
    k=1;
    for(i = 0; i < n-1; i++){
        suicida = killer;
        for(j = 1; j < m;j++){
            killer = killer->prox; /*anda m vezes por morte*/
            
        }
        
        
        if(killer->prox == suicida){
            if(inicio==suicida->prox)
                inicio = (suicida->prox)->prox;
            removeLista(suicida);
            killer=suicida->prox;
            
        }else{
            if(inicio==killer->prox)
                inicio = (killer->prox)->prox;
            removeLista(killer);
            killer = killer->prox;
        }
        /*azarado = killer->prox;*/
        printf("%d - ", k);
        k++;
        imprimeLista();  
    }    

     imprimeLista();
}


int main(){
    resolveJosephus(41,1);
    
    return 0;
}

