#include <stdio.h>
int mindc(int x, int y, int z){
	if(z > x){
		return 1;
	}
	if(x % z != 0 || y % z != 0){
		return mindc(x, y, z + 1);
	}
	else{
		return z;
	}
}
int main(){
	
	int a, b, aux, mdiv = 2;
	
	printf("Insira dois numeros inteiros abaixo:\n");
	scanf("%d%d", &a, &b);
	
	if(a >= b){
		aux = a;
		a = b;
		b = aux;
	}
	
	printf("o minimo divisor comum (maior que 1) dos numeros inseridos e' %d", mindc(a, b, mdiv));
	
	return 0;
}
