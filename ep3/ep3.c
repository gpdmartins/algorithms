#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *mallocSafe (int nbytes){
    void *ptr;
    ptr = malloc(nbytes);
    if (ptr == NULL){
        printf("Erro, malloc NULL\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}


typedef struct no No;
struct no {
    char conteudo;
    No *prox;
};

void empilha (char conteudo, No **pilha){
    
    No *novo = mallocSafe(sizeof(No));
    novo->conteudo = conteudo;
    novo->prox = *pilha;
    *pilha = novo;
}
char desempilha (No **pilha){
    No *pop = *pilha;
    char retorno = pop->conteudo;
    *pilha = (*pilha)->prox;
    free(pop);
    return retorno;
}
void imprimePilha (No *pilha){
    if(pilha != NULL)
        printf("%c ", pilha->conteudo);
        imprimePilha (pilha->prox);
}
int bemFormada (char str[]){
    No *colchete, *chave, *parentese;
    int i, tamanho;
    tamanho = strlen(str);

    for (i=0;i<tamanho;i++){
        switch (str[i]){
            case '(':
                empilha (str[i], &parentese);
            break;
            case ')':
                if(desempilha (&parentese) != '(') return 0;
            break;
            case '[':
                empilha (str[i], &colchete);
            break;
            case ']':
                if (desempilha (&colchete) != ']') return 0;
            break;
            case '{':
                empilha(str[i], &chave);
            break;
            case '}':
                if (desempilha (&chave) != '{') return 0;
        }
    }
    return 1;


}





















