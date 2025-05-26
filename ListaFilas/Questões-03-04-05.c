#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct Aluno{
    long long int ra;
    struct Aluno *prox;
    struct Aluno *final;
}aluno;

typedef struct Fila{
    aluno *inicio;
    int qtd;
}fila;

aluno *criaAluno(){
    long long int i;
    aluno *al = malloc(sizeof(aluno));
    printf("Digite o ra do aluno: ");
    scanf("%lld", &i);
    al->ra = i;
    al->prox = NULL;
    al->final = NULL;
    return al;
}

fila *criaFila(){
    fila *fi = malloc(sizeof(fila));
    if(fi != NULL){
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void liberaFila(fila *fi){
    if(fi != NULL){
        aluno *al;
        while(fi->inicio!=NULL){
            al = fi->inicio;
            fi->inicio = fi->inicio->prox;
            printf("Atendendo aluno %lld\n", al->ra);
            sleep(2);
            free(al);
        }
        free(fi);
    }

}

int insereFila(fila *fi, aluno *al){
    if(fi == NULL) return 0;
    if(al == NULL) return 0;
    if(fi->qtd == 0)
        fi->inicio = al;
    else
        fi->inicio->final->prox = al;
    fi->inicio->final = al;
    fi->qtd++;
    return 1;
}


int main(){
    fila *fi;
    aluno *al;
    int i = 1;
    fi = criaFila();
    while(i){
        al = criaAluno();
        if(! insereFila(fi, al)){
            printf("Erro!!");
            exit(1);
        }
        printf("Digite 1 para inserir outro aluno\nDigite 0 para atender os alunos na fila\n");
        scanf("%d", &i);
    }
    liberaFila(fi);
    printf("Todos os alunos atendidos!\n");
    return 0;
}