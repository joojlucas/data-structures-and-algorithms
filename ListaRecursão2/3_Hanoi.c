#include <stdio.h>
int descobrirtorre(int x, int y){
	if(x == 1){
		switch (y){
			case 2 : return 3;
			case 3 : return 2;
		}
	}
	else if(x == 2){
		switch (y){
			case 1 : return 3;
			case 3 : return 1;
		}
	}
	else if(x == 3){
		switch (y){
			case 2 : return 1;
			case 1 : return 2;
		}
	}
}
void hanoi(int n, int origem, int intermedio, int destino){
    if(n == 1)
        printf("Mova o disco de cima da torre %d para a torre %d\n", origem, destino);
    else{
        hanoi(n - 1, origem, destino, intermedio);
        printf("Mova o disco de cima da torre %d para a torre %d\n", origem, destino);
        hanoi(n - 1, intermedio, origem, destino);
    }
}
int main(){
	
	int nd, nt_atual, nt_seguinte;
	printf("Insira o numero de discos: ");
	scanf("%d", &nd);
	printf("\nInsira o numero da torre em que os discos se encontram (1, 2 ou 3): ");
	scanf("%d", &nt_atual);
	printf("\nInsira o numero da torre em que os discos se ficarao (1, 2 ou 3): ");
	scanf("%d", &nt_seguinte);
	printf("\n\n");
	
	if(nt_atual == nt_seguinte) {
		printf("\n\n\nNao e possivel mover os discos para a torre que ela ja se encontra ue...");
		return 0;
	}
	
	hanoi(nd, nt_atual, descobrirtorre(nt_atual, nt_seguinte), nt_seguinte);	
		
	return 0;
}
