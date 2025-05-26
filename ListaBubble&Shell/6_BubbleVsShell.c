#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void shellSort(int *vet, int tam){
	int i, j, valor;
 
    int h = 1;
    while(h < tam) {
        h = 3*h+1;
    }
    while (h > 0) {
        for(i = h; i < tam; i++) {
            valor = vet[i];
            j = i;
            while (j > h-1 && valor >= vet[j - h]) {
                vet[j] = vet[j - h];
                j = j - h;
            }
            vet[j] = valor;
        }
        h = h / 3;
    }
}
void bubbleSort(int *vet, int tam){
	int k, j, aux;
    for (k = 1; k < tam; k++) {
        for (j = 0; j < tam - 1; j++){
            if (vet[j] > vet[j + 1]){
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
}
int main(){
	
	int v1[5000], v2[5000], i;
	clock_t t1, t2;
	
	for(i = 0; i < 5000; i++){
		v1[i] = (rand() % 5000);
	}
	
	for (i = 1; i < 5000; i++){
    	v2[i] = v1[i];
	}
	t1 = clock();
	bubbleSort(v2, 5000);
	t1 = clock() - t1;
	printf("Tempo de execucao do Bubble Sort: %lf segundos\n", ((double)t1)/(CLOCKS_PER_SEC));
	
	for (i = 1; i < 5000; i++){
    	v2[i] = v1[i];
	}
	t2 = clock();
	shellSort(v2, 5000);
	t2 = clock() - t2;
	printf("Tempo de execucao do Shell Sort: %lf segundos\n", ((double)t2)/(CLOCKS_PER_SEC));
	
	return 0;
}
