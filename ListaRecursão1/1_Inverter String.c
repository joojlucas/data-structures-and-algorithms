#include <stdio.h>
#include <string.h>
#define tamax 150

void inverte (char *a){
	if(*a){
		inverte(a + 1);
		putchar(*a);
	}
	printf("o char eh %c\n", *a);
}
int main(){
	
	char s[tamax];
	
	printf("Digite a palavra ou frase para ser invertida: ");
	scanf("%[^\n]", &s);
	printf("\nA palavra ou frase invertida e': ");
	inverte(s);
	
	return 0;
}
