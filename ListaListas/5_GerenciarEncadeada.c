#include <stdio.h>
typedef struct Cell{
    int num;
    struct Cell *prox;
}; cell

int main(){
    int n;
    int op;
    cell *p = malloc(sizeof(cell));
    cell *o = p;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &(o->num));
        o->prox = malloc(sizeof(cell));
        o = o->prox;
    }
    printf("(1) para inserir\n(2) para remover\n(3) para sair\n");
    scanf("%d", &op);
    while(op != 3){
        if(op == 1){
            insere(p);
        }
        else
            remove(p);
        scanf("%d", &op);
    }
    return 0;
}

void insere(cell *p){
    int opcao;
    cell *aux;
    printf("quer inserir pelo valor ou posicao?(1)(2)\n");
    scanf("%d", &opcao);
    if(opcao == 1){
        int v;
        printf("digite o valor");
        scanf("%d", &v);
        while(p->prox->valor < v) p = p->prox;
        aux = p->prox;
        p->prox = malloc(sizeof(cell);
        p->prox->num = v;
        p->prox->prox = aux;
    }
    else{
        int i, j, v;
        printf("digite a posicao e o valor");
        scanf("%d%d", &j, &v);
        for(i = 0; i < j; i++){
            p = p->prox;
        }
        aux = p->prox;
        p->prox = malloc(sizeof(cell));
        p->prox->num = v;
        p->prox->prox = aux;
    }
}

void remove(cell *p){
    int opcao;
    cell *aux;
    printf("quer remover pelo valor ou posicao?(1)(2)\n");
    scanf("%d", &opcao);
    if(opcao == 1){
        int v;
        printf("digite o valor");
        scanf("%d", &v);
        while(p->prox->valor < v) p = p->prox;
        aux = p->prox;
        p->prox = malloc(sizeof(cell);
        p->prox->num = v;
        p->prox->prox = aux;
    }
    else{
        int i, j, v;
        printf("digite a posicao e o valor");
        scanf("%d%d", &j, &v);
        for(i = 0; i < j; i++){
            p = p->prox;
        }
        aux = p->prox;
        p->prox = malloc(sizeof(cell));
        p->prox->num = v;
        p->prox->prox = aux;
    }
}
