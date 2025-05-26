#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int id;
	char categoria[30];
	char titulo[100];
	char descricao[500];
	char dataIn [10];
	char horaIn[5];
	char dataFim [10];
	char horaFim[5];
	char endereco[100];
	int ingressosDisp;
	float precoIng;
} Evento;

typedef struct{
	int idParticipante;
	char nomeParticipante[75];
	char telParticipante[11];
	char emailParticipante[254];
	int ningressos;
	int ingressos[20];
} Participante;

FILE *eventos;
FILE *participantes;

void imprimeMenu(int n){
	switch(n){
		case 1:
			printf("\n\tDeseja acessar o sistema como:\n\n\t1. Organizador\n\t2. Participante\n\t3. Sair\n\n\t");
			break;
		case 2:
			printf("\t1. Inserir um novo evento\n\t2. Pesquisar eventos\n\t3. Atualizar dados de um evento\n\t4. Remover um evento\n\t5. Sair\n\n\t");
			break;
		case 3:
			printf("\t1. Cadastrar-se como participante\n\t2. Consultar cadastro\n\t3. Atualizar dados de cadastro\n\t4. Comprar ingresso\n");
			printf("\t5. Cancelar ingresso\n\t6. Pesquisar um ingresso\n\t7. Pesquisar algum evento\n\t8. Remover cadastro\n\t9. Sair\n\n\t");
			break;
	}
}

void mostraEvento(Evento ev){
	printf("\tNome do evento: %s\n", ev.titulo);
	printf("\tId do evento: %d", ev.id);
	printf("\tCategoria/tipo: %s\n", ev.categoria);
	printf("\tDescricao: %s\n", ev.descricao);
	printf("\tLocal: %s\n", ev.endereco);
	printf("\tInicio do evento: %s as %s\n", ev.dataIn, ev.horaIn);
	printf("\tFim do evento: %s as %s\n", ev.dataFim, ev.horaFim);
	printf("\tValor do ingresso: %d\n", ev.ingressosDisp);
	printf("\tIngressos disponiveis: %d\n\n", ev.ingressosDisp);
}

void mostraIngressos(Participante part){
	int i;
	Evento ev;
	printf("\tNome do participante: %s\n", part.nomeParticipante);
	if(part.ningressos){
		printf("\tIngressos comprados: \n");
		for(i = 0; i < part.ningressos; i++){
			rewind(eventos);
			while(fread(&ev, sizeof(Evento), 1, eventos))
				if(part.ingressos[i] == ev.id)
					printf("\t\tID %d  |  %s  |  Categoria do evento: %s  |  Data de inicio: %s\n", ev.id, ev.titulo, ev.categoria, ev.dataIn);
		}
	}
	printf("\n");
}
void insereEvento(){
	Evento ev;
	printf("\tInsira o id (numero com 6 digitos) do evento: ");
	scanf("%d", &ev.id);
	getchar();
	printf("\tInsira o Nome do evento: ");
	scanf("%[^\n]", ev.titulo);
	getchar();
	printf("\tInsira a categoria/tipo do evento: ");
	scanf("%[^\n]", ev.categoria);
	getchar();
	printf("\tInsira a descricao do evento (maximo de 500 caracteres): ");
	scanf("%[^\n]", ev.descricao);
	getchar();
	printf("\tInsira a data de inicio do evento: ");
	scanf("%[^\n]", ev.dataIn);
	getchar();
	printf("\tInsira a hora de inicio do evento: ");
	scanf("%[^\n]", ev.horaIn);
	getchar();
	printf("\tInsira a data de fim do evento: ");
	scanf("%[^\n]", ev.dataFim);
	getchar();
	printf("\tInsira a hora de fim do evento: ");
	scanf("%[^\n]", ev.horaFim);
	getchar();
	printf("\tInsira o endereco do local do evento: ");
	scanf("%[^\n]", ev.endereco);
	getchar();
	printf("\tInsira o valor do ingresso: ");
	scanf("%f", &ev.precoIng);
	printf("\tInsira o numero de ingressos disponiveis: ");
	scanf("%d", &ev.ingressosDisp);
	fwrite(&ev, sizeof(Evento), 1, eventos);
	printf("\n\n\tEvento cadastrado!\n\n");
}
void cadastroParticipante(){
	Participante part;
	getchar();
	printf("\tInsira seu nome completo: ");
	scanf("%[^\n]", part.nomeParticipante);
	getchar();
	printf("\tInsira seu email: ");
	scanf("%[^\n]", part.emailParticipante);
	getchar();
	printf("\tInsira seu numero de telefone: ");
	scanf("%[^\n]", part.telParticipante);
	getchar();
	printf("\tInsira seu id de participante (maximo 5 digitos): ");
	scanf("%d", &part.idParticipante);
	part.ningressos = 0;
	fwrite(&part, sizeof(Participante), 1, participantes);
	printf("\n\n\tParticipante cadastrado!\n\n");
}

void compraIngresso(){
	Participante part;
	int i, j, idpart;
	FILE *aux = fopen("aux", "a+b");
	printf("\tInsira o seu id de participante: ");
	scanf("%d", &idpart);
	rewind(participantes);
	while(fread(&part, sizeof(Participante), 1, participantes)){
		if(idpart == part.idParticipante){
			printf("\tInsira o id do evento cujo deseja participar: ");
			scanf("%d", &part.ingressos[part.ningressos]);
			i++;
			j++;
		}
		fwrite(&part, sizeof(Participante), 1, aux);
	}
	participantes = aux;
	remove("participantes");
	rename("aux", "participantes");
	if(!i)
		printf("\n\tParticipante nao encontrado!\nFaça o cadastro caso não poussa, ou tente o ID novamente\n\n\n");
	else{
		printf("Ingresso comprado!!");
		FILE *aux2 = fopen("aux2", "a+b");
		Evento ev;
		rewind(eventos);
	while(fread(&ev, sizeof(Evento), 1, eventos)){
		if(idpart == ev.id){
			ev.ingressosDisp += 1;
		}
		fwrite(&ev, sizeof(Evento), 1, aux2);
	}
	participantes = aux2;
	remove("eventos");
	rename("aux2", "eventos");
	}
}

void atualizaEvento(){
	int idev, j = 0, opcao;
	Evento ev;
	FILE *aux = fopen("aux", "a+b");
	printf("\tInsira o ID do evento: ");
	scanf("%d", &idev);
	rewind(eventos);
	while(fread(&ev, sizeof(Evento), 1, eventos)){
		if(ev.id == idev){
			mostraEvento(ev);
			printf("\t1. Atualizar o ID de evento\n\t2. Aualizar o nome do evento\n\t3. Atualizar a categoria do evento\n");
			printf("\t4. Atualizar o enedereco do local do evento\n\t5. Atualizar a data de inicio\n\t6. Atualizar a hora de inicio\n");
			printf("\t7. Atualizar a data de encerramento\n\t8. Atualizar a hora de encerramento\n\t9. Atualizar o numero de ingressos disponiveis\n\t10. Atualizar o valor do ingresso\n\t");
			scanf("%d", &opcao);
			switch(opcao){
				case 1:
					printf("\tInsira o novo ID do evento: ");
					scanf("%d", &ev.id);
					break;
				case 2:
					getchar();
					printf("\tInsira o novo nome/titulo do evento: ");
					scanf("%[^\n]", ev.titulo);
					break;
				case 3:
					getchar();
					printf("\tInsira a nova categoria do evento: ");
					scanf("%[^\n]", ev.categoria);
					break;
				case 4:
					getchar();
					printf("\tInsira o endereco do novo local do evento: ");
					scanf("%[^\n]", ev.endereco);
					break;
				case 5:
					getchar();
					printf("\tInsira a data de inicio do evento: ");
					scanf("%[^\n]", ev.dataIn);
					break;
				case 6:
					getchar();
					printf("\tInsira a nova hora de inicio do evento: ");
					scanf("%[^\n]", ev.horaIn);
					break;
				case 7:
					getchar();
					printf("\tInsira a nova data de encerramento do evento: ");
					scanf("%[^\n]", ev.dataFim);
					break;
				case 8: 
					getchar();
					printf("\tInsira a nova hora de encerramento do evento: ");
					scanf("%[^\n]", ev.horaFim);
					break;
				case 9:
					printf("\tInsira a nova quantidade de ingressos disponiveis para compra: ");
					scanf("%d", &ev.ingressosDisp);
					break;
				case 10:
					printf("\tInsira o novo valor do ingresso: ");
					scanf("%f", &ev.precoIng);
					break;
				}
			j = 1;
		}
		fwrite(&ev, sizeof(Evento), 1, aux);
	}
	if(!j)
		printf("\tEvento %d nao encontrado!\n\n", idev);
	else
		printf("\tEvento atualizado!\n\n");
	eventos = aux;
	remove("eventos");
	rename("aux", "eventos");
}
void atualizaCadastro(){
	int idpart, j, opcao;
	Participante part;
	FILE *aux = fopen("aux", "a+b");
	printf("\tInsira o ID de participante: ");
	scanf("%d", &idpart);
	rewind(participantes);
	while(fread(&part, sizeof(Participante), 1, participantes)){
		if(part.idParticipante == idpart){
			printf("\n\n\tNome do participante: %s", part.nomeParticipante);
			printf("\n\tEmail do participante: %s", part.emailParticipante);
			printf("\n\tNumero de telefone do participante: %s\n\n", part.telParticipante);
			printf("\t1. Atualizar o ID de participante\n\t2. Atualizar o nome do participante\n\t3. Atualizar o email do participante\n\t4. Atualizar o numero de telefone do participante\n\t");
			scanf("%d", &opcao);
			switch(opcao){
				case 1:
					printf("\tInsira o novo ID de participante: ");
					scanf("%d", &part.idParticipante);
					break;
				case 2:
					getchar();
					printf("\tInsira o novo nome do participante: ");
					scanf("%[^\n]", part.nomeParticipante);
					break;
				case 3:
					getchar();
					printf("\tInsira o novo email: ");
					scanf("%[^\n]", part.emailParticipante);
					break;
				case 4:
					getchar();
					printf("\tInsira o novo numero de telefone: ");
					scanf("%[^\n]", part.telParticipante);
					break;
			}
			j = 1;
		}
		fwrite(&part, sizeof(Participante), 1, aux);
	}
	if(!j)
		printf("\tParticipante %d nao encontrado!!\n\n", idpart);
	else
		printf("\n\n\tCadastro de participante atualizado!\n\n");
	participantes = aux;
	remove("participantes");
	rename("aux", "participantes");
}

void removeEvento(){
	int idev, j;
	Evento ev;
	FILE *aux = fopen("aux", "a+b");
	printf("\tInsira o id do evento: ");
	scanf("%d", &idev);
	rewind(eventos);
	while(fread(&ev, sizeof(Evento), 1, eventos)){
		if(ev.id != idev)
			fwrite(&ev, sizeof(Evento), 1, aux);
		else
			j = 1;
	}
	if(!j)
		printf("\n\tEvento nao encontrado!\n\n");
	else
		printf("\tEvento removido!\n\n");
	eventos = aux;
	remove("eventos");
	rename("aux", "eventos");
}

void removeParticipante(){
	int idpart, j;
	Participante part;
	FILE *aux = fopen("aux", "a+b");
	printf("\tInsira o ID do participante: ");
	scanf("%d", &idpart);
	rewind(participantes);
	while(fread(&part, sizeof(Participante), 1, participantes)){
		if(part.idParticipante != idpart)
			fwrite(&part, sizeof(Participante), 1, aux);
		else
			j = 1;
	}
	if(!j)
		printf("\tParticipante %d nao encontrado!\n\n", idpart);
	else
		printf("\tCadastro removido!\n\n");
	participantes = aux;
	remove("participantes");
	rename("aux", "participantes");
}

void cancelaIngresso(){
	int idpart, idev, i, j, k;
	Participante part;
	FILE *aux = fopen("aux", "a+b");
	printf("\tInsira o ID de participante: ");
	scanf("%d", &idpart);
	rewind(participantes);
	while(fread(&part, sizeof(Participante), 1, participantes)){
		if(part.idParticipante != idpart){
			printf("\tInsira o id do Evento: ");
			scanf("%d", &idev);
			for(i = 0; i < part.ningressos; i++){
				if(part.ingressos[i] != idev)
					fwrite(&part, sizeof(Participante), 1, aux);
					k++;
			}
			j++;
		}
	}
	participantes = aux;
	remove("participantes");
	rename("aux", "participantes");
	if(!j)
		printf("\n\tParticipante nao encontrado!\n\n");
	else  if(!k)
		printf("\n\tEvento nao encontrado\n\n");
	else if(k){
		printf("\tIngresso Cancelado!\n\n");
		FILE *aux2 = fopen("aux2", "a+b");
		Evento ev;
		rewind(eventos);
	while(fread(&ev, sizeof(Evento), 1, eventos)){
		if(idpart == ev.id){
			ev.ingressosDisp -= 1;
		}
		fwrite(&ev, sizeof(Evento), 1, aux2);
	}
	participantes = aux2;
	remove("eventos");
	rename("aux2", "eventos");
	}
}

void pesquisaParticipante(){
	int idpart, j = 0;
	Participante part;
	printf("\tInsira o ID do participante: ");
	scanf("%d", &idpart);
	rewind(participantes);
	while(fread(&part, sizeof(Participante), 1, participantes)){
		if(idpart == part.idParticipante){
			printf("\tEmail do participante: %s\n", part.emailParticipante);
			printf("\tNumero de telefone do participante: %s\n", part.telParticipante);
			mostraIngressos(part);
			j = 1;
		}
	}
	if(!j)
		printf("\tParticipante %d nao encontrado!\n\n", idpart);
}

void pesquisaEvento(){
	int idev, j = 0;
	Evento ev;
	printf("\tInsira o ID do evento: ");
	scanf("%d", &idev);
	rewind(eventos);
	while(fread(&ev, sizeof(Evento), 1, eventos)){
		if(idev == ev.id){
			mostraEvento(ev);
			j = 1;
		}
	}
	if(!j)
		printf("\tEvento %d nao encontrado!\n\n", idev);
}

void pesquisaIngressos(){
	int idpart, j = 0;
	Participante part;
	printf("\tInsira o ID de participante: ");
	scanf("%d", &idpart);
	rewind(participantes);
	while(fread(&part, sizeof(Participante), 1, participantes)){
		if(idpart == part.idParticipante){
			mostraIngressos(part);
			j = 1;
		}
	}
	if(!j)
		printf("\tParticipante %d nao encontrado!\n\n", idpart);
}

void menu_Organizador(){
	int opcao;
	imprimeMenu(2);
	scanf("%d", &opcao);
	switch(opcao){
		case 1:
			insereEvento();
			break;
		case 2: 
			pesquisaEvento();
			break;
		case 3:
			atualizaEvento();
			break;
		case 4:
			removeEvento();
			break;
		case 5:
			return;
			break;
	}
}

void menu_Participante(){
	int opcao;
	imprimeMenu(3);
	scanf("%d", &opcao);
	switch(opcao){
		case 1:
			cadastroParticipante();
			break;
		case 2:
			pesquisaParticipante();
			break;
		case 3:
			atualizaCadastro();
			break;
		case 4: 
			compraIngresso();
			break;
		case 5:
			cancelaIngresso();
			break;
		case 6:
			pesquisaIngressos();
			break;
		case 7:
			pesquisaEvento();
			break;
		case 8:
			removeParticipante();
			break;
		case 9:
			return;
			break;
	}
}
int main(){
	int opcao;
	eventos = fopen("eventos", "a+b");
	participantes = fopen("participantes", "a+b");
	while(1){
		imprimeMenu(1);
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				menu_Organizador();
				break;
			case 2:
				menu_Participante();
				break;
			case 3:
				return 0;
				break;
			default:
				printf("\n\topcao invalida!!\n\n");
				break;
		}
	}
	return 0;
}
