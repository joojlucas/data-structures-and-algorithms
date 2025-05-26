#include <stdio.h>
void shellSort(int *vet, int tam) {
    int i, j, valor;
 
    int h = 1;
    while(h < tam) {
        h = 3*h+1;
    }
    while (h > 0) {
        for(i = h; i < tam; i++) {
            valor = vet[i];
            j = i;
            while (j > h-1 && valor <= vet[j - h]) {
                vet[j] = vet[j - h];
                j = j - h;
            }
            vet[j] = valor;
        }
        h = h/3;
    }
}
int main(){
	
	int i, A[10] = {12, 42, 1, 6, 56, 23, 52, 9, 5, 24};
	
	shellSort(A, 10);
	
	printf("\nO vetor A ordenado por ShellSort com gap 3 ficou: ");
	for(i = 0; i < 10; i++){
		printf("%d ", A[i]);
	}
	printf("\n-\n-\n-\n-\n-");
	
	return 0;
}
