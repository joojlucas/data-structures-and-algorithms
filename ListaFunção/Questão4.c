#include <stdio.h>
#include <stdlib.h>
void preenche(int a, int **b){
	int i;
	
	*b = malloc(a * sizeof(int));
	
	for(i = 0; i < a; i++){
		printf("Digite o elemento %d do vetor: ", i + 1);
		scanf("%d", &(*b)[i]);
	}
}
int main(){
	
	int i, *v1, *v2, *v3, *v4, *v5;
	
	printf("digite o tamanho do vetor 1: ");
	scanf("%d", &i);
	preenche(i, &v1);
	printf("\ndigite o tamanho do vetor 2: ");
	scanf("%d", &i);
	preenche(i, &v2);
	printf("\ndigite o tamanho do vetor 3: ");
	scanf("%d", &i);
	preenche(i, &v3);
	printf("\ndigite o tamanho do vetor 4: ");
	scanf("%d", &i);
	preenche(i, &v4);
	printf("\ndigite o tamanho do vetor 5: ");
	scanf("%d", &i);
	preenche(i, &v5);
	
	free(v1);
	free(v2);
	free(v3);
	free(v4);
	free(v5);
	
	return 0;
}
