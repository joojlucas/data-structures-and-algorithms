#include <stdio.h>
#include <math.h>
double calcula(double *a){
	int i;
	double j = 1;
	for(i = 1; i <= 10; i++){
		j = (j/2) + (*a/(j * 2));
	}
	return j;
}
int main(){
	
	double n, x;
	printf("Digite um valor: ");
	scanf("%lf", &n);
	printf("\n");
	
	printf("O valor da funcao e' %lf\nO valor de sqrt e' %lf", calcula(&n), sqrt(n));
	
	return 0;
}
