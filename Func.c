#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>
#include<string.h>
#include "biblioteca.h"



void cabecalho(){
	system("cls");
	printf("**********************\n");
	printf("AGENDA ELETR�NICA\n");
	printf("**********************\n\n");
}


// FUN��O MENU PRINCIPAL
void menu(){
	while(1){
	int opcao;
	cabecalho();
	printf("Bem vindo a Agenda de Contatos\n");
	printf("O que deseja fazer?\n");
	printf("1-Cadastar novo Contato\n");
	printf("2-Remover Contato \n");
	printf("3-Buscar Contato\n");
	printf("4-Exibir aniversariantes\n");
	printf("5-Buscar aniversariantes por data\n");
	printf("6-Exibir contato com mais horas de trabalho\n");
	printf("7-Imprimir todas as informa��es de todos os contatos\n");
	printf("8-Quantidade de contatos da agenda\n");
	printf("9-Salvar dados\n");
	printf("10-Carregar dados\n");
	printf("11-Sair\n");
	scanf("%d",&opcao);
	switch(opcao){
		case 1:
			entrada_dados();
			break;
		case 2:
			remover_ctt();
			break;
		case 3:
			printf("Qual nome deseja buscar?\n");
			fflush(stdin);
			gets(buscar);
			aux_1=buscar_ctt(buscar);
			if(aux_1==-1){
				printf("O contato n�o existe!!\n");
			}
			break;
		case 4:
			exib_aniv();
			break;
		case 5:
			buscar_aniv();
			break;
		case 6:
			maior_exp();
			break;
		case 7:
			mostrar_dados();
			break;
		case 8:
			system("cls");
			printf("A quantidade de Contatos na agenda � %d\n",QUANTIDADE);
			system("pause");
			break;
		case 9:
			salvar_dados();
			break;
		case 10:
			carregar_dados();
			break;
		case 11:
			exit(1);
			break;
		default:
			printf("Op��o Inv�lida!\n");
			break;
	}
}
}


// FUN��O ENTRADA DE DADOS
void entrada_dados(){
	int i;
	cabecalho();
	
	printf("Quantos contatos deseja adicionar?\n");
	scanf("%d",&qtd);
	qtd = QUANTIDADE + qtd;
	for(i = QUANTIDADE; i < qtd; i++){
		if(QUANTIDADE < 10){
			cabecalho();
			fflush(stdin);
			printf("Insira o Nome do Contato: ");
			gets(Contatos[i].nome);
			fflush(stdin);
			
			printf("Insira o E-mail do Contato: ");
			gets(Contatos[i].email);
			fflush(stdin);
			
			printf("Insira o hor�rio de in�cio do expediente:\nhh:mm:ss: ");
			scanf("%d %d %d",&Contatos[i].horas.inicial[0],&Contatos[i].horas.inicial[1],&Contatos[i].horas.inicial[2]);
			fflush(stdin);
			
			printf("Insira o hor�rio de t�rmino do expediente:\nhh:mm:ss: ");
			scanf("%d %d %d",&Contatos[i].horas.final[0],&Contatos[i].horas.final[1],&Contatos[i].horas.final[2]);
			fflush(stdin);
			
			Contatos[i].horas = calc_expediente(Contatos[i].horas);
			
			printf("Insira o n�mero de telefone do Contato: ");
			scanf("%d",&Contatos[i].telefone);
			fflush(stdin);
			
			printf("Insira o n�mero de endere�o do Contato: ");
			scanf("%d",&Contatos[i].moradia.numero);
			fflush(stdin);
			
			printf("Insira o nome do bairro do Contato: ");
			gets(Contatos[i].moradia.bairro);
			fflush(stdin);
			
			printf("Insira o nome da rua do Contato: ");
			gets(Contatos[i].moradia.rua);
			fflush(stdin);
			
			printf("Insira a data de nascimento do Contato:\ndd/mm/aaaa: ");
			scanf("%d %d %d",&Contatos[i].niver.dia,&Contatos[i].niver.mes,&Contatos[i].niver.ano);
			fflush(stdin);
			QUANTIDADE++;
		}
		else{
			printf("N�mero m�ximo de Contatos");
		}
	}
	system("pause");
}


// FUN��O MOSTRAR DADOS
void mostrar_dados(){
	int i;
	system("cls");
		if(QUANTIDADE==0){
			printf("\nAinda n�o h� clientes cadastrados!!\n\n\n");
		}
		else{		
			for(i=0; i<QUANTIDADE; i++){
				printf("Nome: %s\n",Contatos[i].nome);
				printf("E-mail: %s\n",Contatos[i].email);
				printf("Telefone: %d\n",Contatos[i].telefone);
				printf("Anivers�rio: %d/%d/%d\n",Contatos[i].niver.dia,Contatos[i].niver.mes,Contatos[i].niver.ano);
				printf("O hor�rio de in�cio do expediente: %d:%d:%d\n",Contatos[i].horas.inicial[0],Contatos[i].horas.inicial[1],Contatos[i].horas.inicial[2]);
				printf("O hor�rio de t�rmino do expediente: %d:%d:%d\n",Contatos[i].horas.final[0],Contatos[i].horas.final[1],Contatos[i].horas.final[2]);
				printf("O expediente foi de %d:%d:%d\n",Contatos[i].horas.tempo[0],Contatos[i].horas.tempo[1],Contatos[i].horas.tempo[2]);
				printf("O n�mero do endere�o �: %d\n",Contatos[i].moradia.numero);
				printf("A rua do endere�o �: %s\n",Contatos[i].moradia.rua);
				printf("O bairro do endere�o �: %s\n",Contatos[i].moradia.bairro);
				printf("*************************************************\n");
			}
			}
	system("pause");
}


// FUN��O REMOVER CONTATO
void remover_ctt(){
	char remover[50];
	int aux,i;
	printf("Insira o nome do contato que ser� removido:\n");
	scanf("%s", remover);
	aux=buscar_ctt(remover);
	if(aux==-1){
		printf("O contato n�o existe!!\n");
	}
	else{
		for(i=aux;i<QUANTIDADE-1;i++){
			Contatos[i]=Contatos[i+1];
		}
		qtd--;
		QUANTIDADE--;
		printf("Removido com sucesso!!\n");
	}
	system("pause");
}


// FUN��O BUSCAR CONTATOS
int buscar_ctt(char nome[50]){
	system("cls");
	int i;
	if(QUANTIDADE==0){
		printf("\nAinda n�o h� contatos cadastrados!!\n");
		system("pause");
	}
	else{
	for(i=0;i<QUANTIDADE;i++){
		if(strcasecmp(nome,Contatos[i].nome)==0){
			printf("Nome: %s\n",Contatos[i].nome);
			printf("E-mail: %s\n",Contatos[i].email);
			printf("Telefone: %d\n",Contatos[i].telefone);
			printf("Anivers�rio: %d/%d/%d\n",Contatos[i].niver.dia,Contatos[i].niver.mes,Contatos[i].niver.ano);
			printf("O n�mero do endere�o �: %d\n",Contatos[i].moradia.numero);
			printf("A rua do endere�o �: %s\n",Contatos[i].moradia.rua);
			printf("O bairro do endere�o �: %s\n",Contatos[i].moradia.bairro);
			printf("O hor�rio de in�cio do expediente: %d:%d:%d\n",Contatos[i].horas.inicial[0],Contatos[i].horas.inicial[1],Contatos[i].horas.inicial[2]);
			printf("O hor�rio de t�rmino do expediente: %d:%d:%d\n",Contatos[i].horas.final[0],Contatos[i].horas.final[1],Contatos[i].horas.final[2]);
			printf("O expediente foi de %d:%d:%d\n",Contatos[i].horas.tempo[0],Contatos[i].horas.tempo[1],Contatos[i].horas.tempo[2]);
			system("pause");
			return i;
		}
	}

		
	}return -1;
}


// FUN��O CALCULAR EXPEDIENTE
Expediente calc_expediente(Expediente exp){
	int aux=0;
	if(exp.final[0]<exp.inicial[0]){
		aux = (24 - (exp.inicial[0] - exp.final[0]))*3600 + (exp.final[1] + exp.inicial[1])*60 + exp.final[2] + exp.inicial[2];
	}
	else{
		aux = ((exp.final[0]*3600) + (exp.final[1]*60) + exp.final[2]) - ((exp.inicial[0]*3600) + (exp.inicial[1]*60) + exp.inicial[2]);		
	}
	
	exp.tempo[0] = aux/3600;
	exp.tempo[1] = (aux%3600)/60;
	exp.tempo[2] = (aux%3600)%60;
	
	return exp;
}


// FUN��O EXIBIR ANIVERSARIANTE POR DATA
void buscar_aniv(){
	system("cls");
	int i,data,mes;
	printf("Qual a data e mes que deseja buscar?\n");
	scanf("%d %d",&data,&mes);
	for(i=0;i<qtd;i++){
		if(Contatos[i].niver.dia==data && Contatos[i].niver.mes==mes){
			printf("%s � aniversariante!!\n",Contatos[i].nome);
			printf("PARAB�NS!!!\n");
			
		}
		
	}
system("pause");
}


// FUN��O DE BUSCAR MAIOR EXPEDIENTE
void maior_exp(){
	system("cls");
	char nome_maior[50];
	int exp[3]={0,0,0},i,aux;
	for(i=0;i<10;i++){
		aux=retorna_maior(Contatos[i].horas.tempo,exp);
		if(aux==1){
			exp[0]=Contatos[i].horas.tempo[0];
			exp[1]=Contatos[i].horas.tempo[1];
			exp[2]=Contatos[i].horas.tempo[2];
			strcpy(nome_maior,Contatos[i].nome);
		}
	}
	printf("O contato com mais horas trabalho � %s com %d:%d:%d de trabalho\n",nome_maior,exp[0],exp[1],exp[2]);
system("pause");
}


// FUN��O EXIBIR ANIVERSARIANTE
void exib_aniv(){
	system("cls");
	int i,mes;
	printf("Qual o m�s que deseja exibir?\n");
	scanf("%d",&mes);
	for(i=0;i<qtd;i++){
		if(Contatos[i].niver.mes==mes){
			printf("%s � aniversariante do m�s!!\n",Contatos[i].nome);
			printf("PARAB�NS!!!\n");

		}
		
	}
system("pause");
}
	


// FUN��O PRA VER MAIOR EXPEDIENTE
int retorna_maior(int prim[], int segu[]){
	int seg_prim, seg_segu;
	seg_prim=(prim[0]*3600)+(prim[1]*60)+(prim[2]);
	seg_segu=(segu[0]*3600)+(segu[1]*60)+(segu[2]);
	if(seg_segu<seg_prim){
		return 1;
	}
	else{
		return 0;
	}
}


// FUN��O PARA SALVAR OS DADOS
void salvar_dados(){
	int i;
	system("cls");

 	if(QUANTIDADE==0){
		printf("\nAinda n�o h� contatos cadastrados para salvar!!\n");
	}
	else{
 		 FILE *arquivo=fopen("agenda.bin","wb");
		if(arquivo==NULL){
			printf("\nERRO AO ABRIR ARQUIVO\n");
			system("pause");
		}
		else{
			for(i=0;i<QUANTIDADE;i++){		
			fwrite(&Contatos,sizeof(Registro),1,arquivo);
		}
		}fclose(arquivo);
		}
		printf("\n\nARQUIVOS SALVOS COM SUCESSO!!\n\n");
		system("pause");
	}

	

	
//FUN��O CARREGAR DADOS
void carregar_dados(){
	system("cls");
	FILE *arquivo=fopen("agenda.bin","rb");	
	if(arquivo==NULL){
		printf("\nERRO AO ABRIR ARQUIVO!\n\n");
		system("pause");
	}
	else{
		while(fread(&Contatos,sizeof(Registro),1,arquivo)==1){
			QUANTIDADE++;
	}
		fread(&Contatos,sizeof(Registro),1,arquivo);
		printf("\nCARREGADO ARQUIVO COM SUCESSO!!\n\n");
		system("pause");
		menu();
		}fclose(arquivo);
}

