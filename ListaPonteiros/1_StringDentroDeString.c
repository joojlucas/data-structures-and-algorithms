#include <stdio.h>
#include <string.h>
#define tamax 150
int inorout(char *a, char *b){
	
	int i, j, k, l, vet[ strlen(a) ];
	int ok;
	
	if( strlen(b) > strlen(a) ){
        return -1;
    }
    if( strcmp(b, a) == 0 ){
        return 0;
    }

    for(i = 0; i <= strlen(a) - strlen(b); i++){
        if(a[i] == b[0]){
            for(j = 0; j < strlen(b); j++) vet[j]=0;
            
            k = i;
            
            for(j = 0; j < strlen(b); j++){
                if(b[j] == a[k]){
                    vet[j]=1;
                    k++;
                }
            }
            ok = 1;
            for(j = 0; j < strlen(b); j++){
                if(vet[j] == 0){
                    ok = -1;
                }
            }

            if( ok > 0 ){
                return i;
            }
        }
    }
	return -1;
}
int main(){
	
	char str1[tamax], str2[tamax];
	int i;
	
	printf("Digite a primeira string: ");
	scanf("%[^\n]", &str1);
	getchar();
	printf("Digite a segunda string: ");
	scanf("%[^\n]", &str2);
	getchar();
	if(inorout(&str1[0], &str2[0]) >= 0){
		printf("\n\nA string 2 esta dentro da string 1!\nA posicao de memoria que se encontra o inicio da string 2 na string 1 e': %d\n\n", inorout(&str1[0], &str2[0]));
	}
	else printf("\nA segunda string nao se encontra dentro da primeira\n\n");
	
	return 0;
}
