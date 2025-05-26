#include <stdio.h>
void mostravet(int vetor[], int tam){
	int i;
	for (i = 0; i < tam; i++) printf("%d ", vetor[i]);
}
void insertionSort(int *vetor, int tam){
	int i, j, tmp, trocas = 0;
	for (i = 1; i < tam; i++){
		j = i;
		while (j > 0 && vetor[j - 1] < vetor[j]){
			tmp = vetor[j];
			vetor[j] = vetor[j - 1];
			vetor[j - 1] = tmp;
			j--;
			trocas += 1;
		}
	}
	printf("Insertion Sort - Movimentacoes realizadas:%d\n\n", trocas);
}
int main(){
	int arra[6];
	arra[0] = 31;
	arra[1] = 41;
	arra[2] = 59;
	arra[3] = 26;
	arra[4] = 41;
	arra[5] = 58;
	insertionSort(&arra[0], 6);
	printf("o arranjo A ordenado decrescentemente fica: ");
	mostravet(arra, 6);
	printf("\n\n");
}
