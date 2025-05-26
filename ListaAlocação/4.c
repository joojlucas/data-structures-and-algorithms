#include <stdio.h>
#include <stdlib.h>
void troca(int *a, int *b){
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}
int main(){
	
	int *n1, *n2;
	
	n1 = malloc(1 * sizeof(int));
	n2 = malloc(1 * sizeof(int));
	
	printf("Digites o valor A:\n");
	scanf("%d", n1);
	printf("Digites o valor B:\n");
	scanf("%d", n2);
	troca(n1, n2);
	
	printf("O valor A e' %d\nO valor B e' %d\n", *n1, *n2);
	
	free(n1);
	free(n2);
	
	return 0;
}
