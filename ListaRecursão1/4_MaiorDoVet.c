#include <stdio.h>
int big(int *p, int t, int posicao){
	int notorious;
	if(posicao == t){
		return p[t];
	}
	else{
		return ((p[posicao] >= (notorious = big(p, t, posicao + 1))) ? (p[posicao]) : (notorious));
	}
}
int main(){
	
	int tam, i;
	
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &tam);
	int vet[tam];
	
	for(i = 0; i < tam; i++){
		printf("Digite o elemento numero %d do vetor: ", i + 1);
		scanf("%d", &vet[i]);
	}
	
	printf("\nO maior elemnto do vetor e': %d", big(vet, tam - 1, 0));
	
	return 0;
}
