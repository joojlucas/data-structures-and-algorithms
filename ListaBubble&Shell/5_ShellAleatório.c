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
            while (j > h-1 && valor >= vet[j - h]) {
                vet[j] = vet[j - h];
                j = j - h;
            }
            vet[j] = valor;
        }
        h = h / 3;
    }
}
int main(){
	
	int i, vet[100];
	
	for(i = 0; i < 100; i++){
		vet[i] = (rand() % 1000);
	}
	
	shellSort(vet, 100);
	
	printf("\nO vetor ordenado por ShellSort ficou: ");
	for(i = 0; i < 100; i++){
		printf("%d", vet[i]);
		if(i < 99) printf(", ");
		else printf(".");
	}
	printf("\n-\n-\n-\n-\n-");
	
	return 0;
}
