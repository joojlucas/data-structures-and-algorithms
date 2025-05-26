#include <stdio.h>
void selectionSort(int *vetor, int *tam){
	int i, j, trocas = 0;
	int max, aux;
	for (i = *tam - 1; i > 0; i--){
		max = i;
		for (j = i - 1; j >= 0; j--){
			if (vetor[j] > vetor[max]){
				max = j;
				trocas++;
			}
		}
		aux = vetor[i];
		vetor[i] = vetor[max];
		vetor[max] = aux;
	}
	printf("Selection Sort - Movimentacoes realizadas: %d\n\n", trocas);
}
int main(){
	
	int tam, i;
	printf("Digite o tamanho do vetor para ser ordenado: ");
	scanf("%d", &tam);
	printf("\n");
	
	int vet[tam];
	for(i = 0; i < tam; i++){
		printf("Digite o elemento %d do vetor: ", i + 1);
		scanf("%d", &vet[i]);
		printf("\n");
	}
	
	printf("\n\n");
	
	selectionSort(&vet[0], &tam);
	
	printf("\nO vetor ficou ordenado da seguinte forma:\n");
	for(i = 0; i < tam; i++){
		printf("%d ", vet[i]);
	}
	printf("\n\n");
	
	return 0;
}
