#include <stdio.h>
#include <string.h>
void QuickSortNomes(char lista[][15], int comeco, int tam, int *trocas){
	int i, j, trocasQuick = 0;
	char pivo[15], aux[15];
	i = comeco;
	j = tam - 1;
	
	strcpy(pivo, lista[tam - 1]);
	
	while (i <= j){
		while (strcmp(lista[i], pivo) < 0 && i < tam){
			i++;
		}
		while (strcmp(lista[j], pivo) > 0 && j > comeco){
			j--;
		}
		if (i <= j){
			strcpy(aux, lista[i]);
			strcpy(lista[i], lista[j]);
			strcpy(lista[j], aux);
			i++;
			j--;
			trocasQuick += 1;
		}
	}
	if (j > comeco){
	QuickSortNomes(lista, comeco, j + 1, trocas);
	}
	if (i < tam){
	QuickSortNomes(lista, i, tam, trocas);
	}
	*trocas = trocasQuick;
}
int main(){
	
	int n, i, ntrocas;
	printf("Insira o numero de nomes da lista: ");
	scanf("%d", &n);
	
	char lista_nomes[n][15];
	
	printf("\nAgora digite abaixo os %d nomes da lista (maximo de 15 caracteres cada):\n", n);
	
	for(i = 0; i < n; i++){
		scanf("%s", &lista_nomes[i]);
	}
	
	QuickSortNomes(lista_nomes, 0, n, &ntrocas);
	
	printf("\nA lista inserida foi ordenana pelo o Algoritmo Quick Sort, cujo realizou %d troca", ntrocas);
	if(ntrocas > 1) printf("s");
	printf("\nA lista ordenada ficou:\n");
	
	for(i = 0; i < n; i++){
		printf("%d. %s\n", i + 1, lista_nomes[i]);
	}
	
	return 0;
}
