#include <stdio.h>
void circ(int *raio, double *peri, double *area){
	float pi = 3.14159;
	*peri = *raio * 2 * pi;
	*area = (*raio * *raio) * pi;
}
int main(){
	
	int r;
	double p, a;
	
	printf("Digite o raio da circunferencia em centimetros: ");
	scanf("%d", &r);
	circ(&r, &p, &a);
	printf("\n\nO perimetro da circunferencia e' %.2lf cm\n", p);
	printf("A area da circunferencia e' %.2lf cm^2\n", a);
	
	
	return 0;
}
