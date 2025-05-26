#include <stdio.h>
double raizq(double x, double y, int z){
	if(z < 10){
		y = (y / 2) + (x / (2 * y));
		raizq(x, y, z + 1);
	}
	else return y;
}
int main(){
	
	double n, resul = 1;
	int aux = 0;
	
	printf("Digite um numero: ");
	scanf("%lf", &n);
	printf("\n\nA raiz quadrada do numero %.2lf e' %.5lf\n\n", n, raizq(n, resul, aux));
	
	
	return 0;
}
