#include <stdio.h>
double fator (double *a){  //fun��o para c�lculo do fatorial
	double i, aux = *a;
	for(i = *a - 1; i > 0; i--){
		aux = aux * i;
	}
	return aux;
}
double somatorio (double *a){ //fun��o para c�lculo do somat�rio
	double aux = 0, i;
	for(i = 1; i <= *a; i++){
		aux = aux + 1/fator(&i);
	}
	return aux;
}
int main(){
	
	double n;
	printf("Digite um valor: ");
	scanf("%lf", &n);
	printf("\nO resultado do somatorio e': %lf", somatorio(&n));
	
	return 0;
}
