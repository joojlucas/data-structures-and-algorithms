#include <stdio.h>
double potencia (double ba, int ex){
	if(ex <= 1){
		return ba;
	}
	else{
		return (ba * potencia(ba, ex - 1));
	}
}
int main(){
	
	int exp;
	double b;
	
	printf("Digite a base e o expoente abaixo:\n");
	scanf("%lf %d", &b, &exp);
	printf("\nO resultado da potenica e': %.0lf", potencia(b, exp));
	
	return 0;
}
