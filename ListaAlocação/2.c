#include <stdio.h>
#include <stdlib.h>

int main(){
	
	printf("\n\nDigite a quantidade de colunas:");
	
	int nc, nl, i, j;
	
	scanf("%d", &nc);
	printf("\n\n\nDigite a quantidade de colunas:");
	scanf("%d", &nl);
	
	int **mat;
	
	mat = malloc(nl* sizeof(int *));
	
	for(i = 0; i < nl; i++){
		*(mat + i) = malloc(nc * sizeof(int));
	}
	
	printf("\n\nDigite abaixo cada elemento da matriz:\n");
	
	for(i = 0; i < nl; i++){
		for(j = 0; j < nc; j++){
			scanf("%d", (*(mat+i)+j));
		}
	}
	
	for(i = 0; i < nl; i++){
		free(*(mat + i));
	}
	
	free(mat);

	return 0;
}
