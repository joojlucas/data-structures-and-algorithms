#include <stdio.h>
#include <stdlib.h>
#define Y 2	//definição do tamanho da altura da matriz (quant. de linhas)
#define X 2	//definição do tamanho da largura da matriz (quant. de colunas)
int main(int argc, char *argv[])	
{
	int **A;	//declarção de um ponteiro de ponteiro (matriz)
	int i, j;	//declaração de variaveis auxiliares
	A = (int **)malloc(Y * sizeof(int *));		//alocação dinamica de memoria para os ponteiros de cada linha da matriz
	for (i = 0; i < Y; i++)		//Loop do numero de colunas
		A[i] = (int *)malloc(X * sizeof(int));		//alocação dinamica de cada elemento (inteiro) de cada coluna da matriz
	for (i = 0; i < Y; i++)		//loop para numero de linhas
		for (j = 0; j < X; j++)		//loop para numero de colunas
			A[i][j] = i + j;	//atribuição de valor para cada elemento da matriz (de forma que A[i][j] seja sempre igual a A[j][i])
	for (i = 0; i < Y; i++)		//loop para numero de linhas
		for (j = 0; j < X; j++)		//loop para numero de colunas
			printf("%d \t", A[i][j]);	//Impressao de cada elemento da matriz
	free(A[i]);		//Liberação de memoria das "linhas" da matriz
	free(A);		//Liberção de memoria das colunas da matriz
	
	return 0;
 }		//O programa acima cria, aloca dinamicamente, e iprime uma matriz simétrica
