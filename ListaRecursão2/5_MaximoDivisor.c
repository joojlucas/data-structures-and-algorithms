#include <stdio.h>
int maxdc(int x, int y, int z){
	if(x % z != 0 || y % z != 0){
		return maxdc(x, y, z - 1);
	}
	else{
		return z;
	}
}
int main(){
	int a, b, aux, mdiv;
	
	printf("Insira dois numeros inteiros abaixo:\n");
	scanf("%d%d", &a, &b);
	
	if(a >= b){
		aux = a;
		a = b;
		b = aux;
	}
	
	mdiv = a;
	
	printf("o maximo divisor comum de %d e %d e' %d", a, b, maxdc(a, b, mdiv));
	
	return 0;
}
