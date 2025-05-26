#include <stdio.h>
#include <stdlib.h>
typedef struct sebas{
	struct sebas *next;
} lista; 
void aloca (int n, lista* pont){
	int i = 0;
	while (i < n){
		pont->next = malloc(sizeof(lista) * 1);
		pont = (pont->next);
		i++;
	}
}
void libera(lista* pointer){
	if(pointer->next){
		libera(pointer->next);
	}
	free(pointer);
}
int checar(int n, lista* p){
	int i = 1;
	while(p->next){
		p = (p->next);
		i++;
	}
	if (i = n) return 1;
	else return 0;
}
int main(){
	
	int num;
	printf("Digite o numeros e elementos da lista: ");
	scanf("%d", &num);
	
	lista *aux;
	
	aux = malloc(sizeof(lista) * 1);
	aloca(num, aux);
	
	if(checar(num, aux) == 1){
		printf("\nAlocacao concluida com sucesso\n");
	}
	else printf("/nFalha na alocacao\n");
	
	libera(aux);
	
	return 0;
}
