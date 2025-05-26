#include <stdio.h>
#include <stdlib.h>

int main(){
	
	printf("\n\nDigite a quantidade de elementos do vetor:");
	
	int n, i;
	
	scanf("%d", &n);
	printf("\n\n");

	int *a;
	
	a = malloc(n * sizeof(int));
	
	printf("\n\nDigite abaixo cada elemento do vetor:\n");
	
	for(i = 0; i < n; i++){
		scanf("%d", (a+i));
	}
	
	free(a);
	
	return 0;
}
