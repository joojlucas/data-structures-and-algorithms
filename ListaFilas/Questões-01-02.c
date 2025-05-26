#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Document{
    char nome[200];
    int tempo;
    struct Document *prox;
}doc;

typedef struct Descritor{
    doc *inicio;
    doc *final;
    int qtd;
}fila;

doc *criaDoc(){
    doc *dc = malloc(sizeof(doc));
    printf("Digite o nome do Documento: ");
    scanf("%[^\n]", dc->nome);
    getchar();
    printf("Digite o tempo para imprimir o Documento: ");
    scanf("%d", &(dc->tempo));
    getchar();
    dc->prox = NULL;
    return dc;
}

fila *criaFila(){
        fila *fi = malloc(sizeof(fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void liberaFila(fila *fi){
    if(fi != NULL){
        doc *dc;
        while(fi->inicio!=NULL){
            dc = fi->inicio;
            fi->inicio = fi->inicio->prox;
            printf("Imprimindo o documento \"%s\"\n", dc->nome);
            if(dc->tempo){
                printf("%d", dc->tempo);
                fflush(stdout);
                sleep(1);
            }
            for(int k = (dc->tempo) - 1; 0 < k; k--){
                printf(", %d", k);
                fflush(stdout);
                sleep(1);
            }
            free(dc);
            printf("\n");
        }
        free(fi);
    }
}

int insereFila(fila *fi, doc *dc){
    if(fi == NULL) return 0;
    if(dc == NULL) return 0;
    if(fi->final == NULL)
        fi->inicio = dc;
    else
        fi->final->prox = dc;
    fi->final = dc;
    fi->qtd++;
    return 1;
}

/*void enfila(){
    printf("Digite quantos documentos quer inserir: ");
    scanf("%d", &n);
    getchar();
    fila = malloc(n * sizeof(doc));
    for(int i = 0; i < n; i++){
        printf("Digite o nome do documento %d: ", i+1);
        scanf("%[^\n]", fila[i].nome);
        getchar();
        printf("Digite o tempo do documento %d: ", i+1);
        scanf("%d", &fila[i].tempo);
        getchar();
    }
}

void desenfila(){
    for(int i = 0; i < n; i++){
        printf("Imprimindo %s\n", fila[i].nome);
        for(int j = fila[i].tempo; 0 < j; j--){
            printf("%d\n", j);
            sleep(1);
        }
    }
    fila = NULL;
}*/

int main(){
    fila *fi;
    doc *dc;
    int op = 1;
    fi = criaFila();
    while(op){
        dc = criaDoc();
        if(! insereFila(fi, dc)){
            printf("Erro!!");
            exit(1);
        }
        printf("Digite 1 para inserir outro Documento\nDigite 0 para imprimir os documentos na fila\n");
        scanf("%d", &op);
        getchar();
    }
    liberaFila(fi);
    printf("Todos os documentos foram impressos!\n");
    return 0;
}