#include <stdio.h>
#include <stdlib.h>

void lermat(int *ncol, int *nlin, int ***matriz){
	int i, j;
	printf("Digite o numero de colunas da matriz:");
	scanf("%d", ncol);
	printf("\n\nDigite o numero de linhas da matriz:");
	scanf("%d", nlin);
	printf("\n\n");
	printf("Digite cada elemento da matriz abaixo:\n");
	
	*matriz = malloc(*ncol * sizeof(int *));
	for(i = 0; i < *nlin; i++) *(*matriz+i) = malloc(*nlin * sizeof(int));
	
	for(i = 0; i < *nlin; i++){
		for(j = 0; j < *ncol; j++){
			scanf("%d", &(*matriz)[i][j]);
		}
	}
}
void imprimat(int *ncol, int *nlin, int ***matriz){
	int i, j;
	for(i = 0; i < *nlin; i++){
		for(j = 0; j < *ncol; j++){
			printf("%d ", (*matriz)[i][j]);
		}
		printf("\n");
	}
}	
int main(){
	int nc, nl, **mat, i;
	
	lermat(&nc, &nl, &mat);
	imprimat(&nc, &nl, &mat);
	
	for(i = 0; i < nl; i++){
		free(*(mat + i));
	}
	
	free (mat);
	
	return 0;
}	
