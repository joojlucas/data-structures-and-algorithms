#include <stdio.h>
void bubbleSort(int vetor[], int tam){
	int k, j, aux1, aux2, trocas = 0;
	for (k = tam - 1; k > 0; k--){
		for (j = 0, aux2 = 0; j < k; j++){
			if (vetor[j] > vetor[j + 1]){
				aux1 = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = aux1;
				trocas++;
				aux2++;
			}
		}
		if(aux2 == 0) break;
	}
	printf("\nBubble Sort - Movimentacoes realizadas: %d\n", trocas);
}
int main(){
	
	int tam;
	printf("Digite o tamanho do vetor para ser ordenado: ");
	scanf("%d", &tam);
	
	int vet[tam], i;
	for(i = 0; i < tam; i++){
		printf("Digite o valor do elemento %d do vetor: ", i+1);
		scanf("%d", &vet[i]);
	}
	
	bubbleSort(vet, tam);
	
	printf("\nO vetor ordenado ficou: ");
	for(i = 0; i < tam; i++){
		printf("%d ", vet[i]);
	}
	
	return 0;
}
