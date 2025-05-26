#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char palavra[100];
    struct Node *prox;
}node;

node *pilha = NULL;

void empilha(){
    node *palavra = malloc(sizeof(node));
    printf("Digite a palavra a ser empilhada: ");
    scanf("%s", palavra->palavra);
    palavra->prox = pilha;
    pilha = palavra;
}

void desempilha(){
    if(pilha == NULL){
        printf("Pilha vazia!!\n");
        return;
    }
    node *next = pilha;
    pilha = pilha->prox;

    printf("%s\n", next->palavra);
    free(next);
}

int main(){
    int opcao;
    printf("Digite 1 para empilhar, 2 para desempilhar, 0 para sair: ");
    scanf("%d", &opcao);
    while(opcao){
        if(opcao == 1)
            empilha();
        else
            desempilha();
        
        printf("Digite 1 para empilhar, 2 para desempilhar, 0 para sair: ");
        scanf("%d", &opcao);
    }
    return 0;
}