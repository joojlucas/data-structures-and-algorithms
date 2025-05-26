#include <stdio.h>
void troca(int *n1, int *n2){
	int aux;
	aux = *n1;
	*n1 = *n2;
	*n2 = aux;
}
int main(){
	
	int a, b;
	
	printf("Digite o numero A: ");
	scanf("%d", &a);
	printf("Digite o numero B: ");
	scanf("%d", &b);
	troca(&a, &b);
	printf("O numero A era %d e agora e' %d\n", b, a);
	printf("O numero B era %d e agora e' %d\n\n", a, b);
	
	return 0;
}
