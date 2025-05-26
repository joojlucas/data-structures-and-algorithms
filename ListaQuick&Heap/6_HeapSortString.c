#include <stdio.h>
#include <ctype.h>
void troca(char *a, char *b){
	int trocasHeap;
	char aux = *a;
	*a = *b;
	*b = aux;
	trocasHeap += 1;
}
void heapify(char str[], int n, int i){
	int max = i;
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;
	if (leftChild < n && tolower(str[leftChild]) < tolower(str[max]))
		max = leftChild;
	if (rightChild < n && tolower(str[rightChild]) < tolower(str[max]))
		max = rightChild;
	if (max != i){
		troca(&str[i], &str[max]);
		heapify(str, n, max);
	}
}
void heapSort(char str[], int tam){
	int i = tam / 2- 1;
	for (i; i >= 0; i--)
		heapify(str, tam, i);
	for (i = tam - 1; i >= 0; i--){
		troca(&str[0], &str[i]);
		heapify(str, i, 0);
	}
}
int main(){
	
	char str[24] = {"Ordenando com Heap Sort"};
	int i;
	
	heapSort(str, 24);
	
	printf("A ordenacao decresente dos caracteres da string fica: ");
	
	for(i = 0; i < 24; i++){
		printf("%c", str[i]);
	}
	
	printf("\n\n\n");
	
	return 0;
}
