#include <stdio.h>

float y = 1; //Y declarado globalmente

float fator (float *a){  //fun��o para c�lculo do fatorial
	float i, aux = *a;
	for(i = *a - 1; i > 0; i--){
		aux = aux * i;
	}
	return aux;
}
float pont(float *a, float *b){  //fun��o para c�lculo de pot�ncia
	int i;
	float aux = *b;
	for(i = 1; i < *a; i++){
		aux = *b * aux;
	}
	return aux;
}
int main(){
	
	float x, i, j = 2;
	
	printf("Digite o valor de X: ");
	scanf("%f", &x);
	printf("\n\n");
	
	for(i = 1; i <= x; i++){
		y = y + ((i * pont(&j, &x))/ fator(&j));
		printf("o valor parcial numero %d de Y e' %f\n", i, y);
		j++;
	}
	printf("o valor final de Y e' %f\n", y);
	
	return 0;
}
