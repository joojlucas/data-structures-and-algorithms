#include <stdio.h>
int fibochubs(int t){
	if(t <= 1){
		retur1;
	}
	else{
		return (fibochubs(t - 1) + fibochubs(t - 2));
	}
}
int main(){
	
	int termo;
	
	printf("Digite o numero do termo do fibonacci: ");
	scanf("%d", &termo);
	printf("\nO valor do termo inserido e': %d", fibochubs(termo - 1));
	
	return 0;
}
