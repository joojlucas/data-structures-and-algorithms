#include <stdio.h>
#include <stdlib.h>
typedef struct sebas{
	struct sebas *next;
	int j;
} lista; 
void aloca (int n, lista* pont){
	int i = 0;
	while (i < n){
		pont->next = malloc(sizeof(lista) * 1);
		pont->j = i + 1;
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
void remover(int n, lista* pointer){
	int i = 0;
	lista* atual;
	lista* anterior;
	if(pointer->j == n){
		atual = pointer;
		pointer = pointer->next;
		free(atual);
		return;
	}
	atual = pointer->next;
	anterior = pointer;
	while(i < 20){
		if(atual->j == n){
			anterior->next = atual->next;
			free(atual);
		}
		i++;
	}
}
int main(){
	
	int num;
	printf("Digite o valor que deseja remover da lista (1 a 20): ");
	scanf("%d", &num);
	
	lista *aux;
	
	aux = malloc(sizeof(lista) * 1);
	aloca(20, aux);
	
	remover(num, aux);
	
	
	libera(aux);
	
	return 0;
}
