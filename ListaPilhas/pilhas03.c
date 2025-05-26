#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int ntombo;
    struct Node *prox;
}node;

node *pilha = NULL;

void empilha(node *tombo){
    tombo->prox = pilha;
    pilha = tombo;
}

int desempilha(){
    node *aux = pilha;
    if(pilha == NULL) return 0;
    pilha = pilha->prox;
    printf("%d\n", aux->ntombo);
    free(aux);
    return 1;
}

int removeTombo(int n){
    if(pilha->ntombo == n){
        desempilha();
        return 1;
    }
    node *ant = pilha;
    node *at = pilha->prox;
    while(at != NULL){
        if(at->ntombo == n){
            ant->prox = at->prox;
            free(at);
            return 1;
        }
        else{
            at = at->prox;
            ant = ant->prox;
        }
    }
    return 0;
}

int main(){
    int n, i = 1;
    printf("Digite os numeros dos tombos(-1 para parar): ");
    scanf("%d", &n);
    while(n != -1){
        node *p = malloc(sizeof(node));
        p->ntombo = n;
        empilha(p);
        scanf("%d", &n);
    }
    while(i){
        printf("Digite o numero do tombo que sera removido: ");
        scanf("%d", &n);
        if(!(removeTombo(n))){
            printf("Tomobo inexistente!!\n");
        }
        else{
            i = 0;
        }
    }
    while(desempilha()){};
}