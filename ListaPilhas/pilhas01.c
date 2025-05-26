#include <stdio.h>
#include <stdlib.h>
int ultimo = -1;
char pilha[100][100];

void empilha(){
    printf("Digite a palavra a ser empilhada: ");
    scanf("%s", pilha[++ultimo]);
}

void desempilha(){
    if(-1 < ultimo){
        printf("%s\n", pilha[ultimo--]);
    }
    else
        printf("Pilha vazia!!\n");
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