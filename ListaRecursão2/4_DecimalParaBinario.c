#include <stdio.h>
void transforma (int a){
	int x;
	if(a / 2 != 0){
		x = a / 2;
		transforma(x);
		printf("%d", a % 2);
	}
	else{
		printf("%d", a % 2);
	}
}
int main(){
	
	int n;
	
	printf("Digite o numero decimal: ");
	scanf("%d", &n);
	printf("\n\nO numero %d em notacao binaria e': ", n);
	transforma(n);
	printf("\n");
	
	return 0;
}
