/*Nome: Jose Guilherme Pereira Dias Martins
**Curso: Topicos de Programação
**Curso de Verão 2017
*/

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
    if((*pilha)== NULL)
        novo->prox = NULL;
    else
        novo->prox = *pilha;
    *pilha = novo;
}
char desempilha (No **pilha){
    No *pop = *pilha;
    char retorno = pop->conteudo;
    *pilha = (*pilha)->prox;
    free(pop);
    /*printf("desempilhando: %c\n", retorno);*/
    return retorno;
}
void imprimePilha (No *pilha){
    while(pilha->prox != NULL){
        printf("%c", pilha->conteudo);
            pilha = pilha->prox;
    }
        printf("%c", pilha->conteudo);
    }

int bemFormada (char str[]){
    No *pilha = NULL;
    int i, tamanho;
    tamanho = strlen(str);

    for (i=0;i<tamanho;i++){
        switch (str[i]){
            
            case '(':{
            empilha(str[i], &pilha); break;}
            case ')':{
            if(pilha == NULL || desempilha(&pilha)!= '(') return 0; break;}
            case '[':{
            empilha(str[i], &pilha); break;}
            case ']':{
            if(pilha == NULL || desempilha(&pilha)!= '[') return 0; break;}
            case '{':{
            empilha(str[i], &pilha); break;}
            case '}':{
            if(pilha == NULL || desempilha(&pilha)!= '{') return 0; break;}
        }
    }
    if(pilha != NULL)
        return 0;
    
    return 1;


}

int main(void){
    char str[] = "{[()]}";
    No *pilha = NULL;
    int i =0;
    
    for(i=0;i<strlen(str);i++){
        empilha(str[i], &pilha);
    }    
    
    imprimePilha(pilha);
    printf("\n");
    printf("\n%d\n", bemFormada(str));
    return 0;
}



















