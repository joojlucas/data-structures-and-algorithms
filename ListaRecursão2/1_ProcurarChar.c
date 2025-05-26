#include <stdio.h>
#include <string.h>
#define tamax 150

void findchar (char *a, char b, int c, int *d){
	if(*a){
		if(*a == b){
			printf("O caracter '%c' foi encontrado na posicao %d da string\n", b, c + 1);
			*d += 1;
		}
		findchar(a + 1, b, c + 1, d);
	}
}
int main(){
	
	char s[tamax], c;
	int cont, aux = 0;
	
	printf("Digite uma palavra ou uma frase: ");
	scanf("%[^\n]", &s);
	getchar();
	printf("\nDigite o caractere que deseja procurar: ");
	scanf("%c", &c);
	printf("\n");
	
	findchar(s, c, cont, &aux);
	if(aux == 0) printf("O caractere '%c' nao foi encontrado", c);
	
	return 0;
}
