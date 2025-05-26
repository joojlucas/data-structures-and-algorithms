#include <stdio.h>
void imprimedata(int *d, int *m, int *a){
	if(*m == 1) printf("%d de janeiro de %d", *d, *a);
	else if(*m == 2) printf("%d de Fevereiro de %d", *d, *a);
	else if(*m == 3) printf("%d de Marco de %d", *d, *a);
	else if(*m == 4) printf("%d de Abril de %d", *d, *a);
	else if(*m == 5) printf("%d de Maio de %d", *d, *a);
	else if(*m == 6) printf("%d de Junho de %d", *d, *a);
	else if(*m == 7) printf("%d de Julho de %d", *d, *a);
	else if(*m == 8) printf("%d de Agosto de %d", *d, *a);
	else if(*m == 9) printf("%d de Setembro de %d", *d, *a);
	else if(*m == 10) printf("%d de Outubro de %d", *d, *a);
	else if(*m == 11) printf("%d de Novembro de %d", *d, *a);
	else if(*m == 12) printf("%d de Dezembro de %d", *d, *a);
	else printf("Numero de mes invalido!!\n");
}
int main(){
	int dia, mes, ano;
	
	printf("Digite abaixo o dia, mes e ano respectivamente:\n");
	scanf("%d%d%d", &dia, &mes, &ano);
	imprimedata(&dia, &mes, &ano);
	
	return 0;
}
