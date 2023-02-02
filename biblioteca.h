#ifndef FUNC_H_
#define FUNC_H_
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>
#include<string.h>

//Structs


typedef struct{
	int inicial[3];
	int final[3];
	int tempo[3];
}Expediente;

typedef struct{
		char rua[50];
		int numero;
		char bairro[50];
	}Endereco;

typedef struct{
		int dia;
		int mes;
		int ano;
	}Aniversario;

typedef struct{
	char nome[50];
	char email[50];
	int telefone;
	Expediente horas;
	Endereco moradia;
	Aniversario niver;
}Registro;

//FUNÇÕES
void menu();
void entrada_dados();
void cabecalho();
void remover_ctt();
int buscar_ctt(char[]);
void mostrar_dados();
Expediente calc_expediente(Expediente exp);
void buscar_aniv();
void maior_exp();
void exib_aniv();
int retorna_maior(int[], int[]);
void salvar_dados();
void carregar_dados();

//VARIÁVEIS GLOBAIS
int qtd;
int aux_1;
int QUANTIDADE=0;
char buscar[50];
Registro Contatos[10];

#endif

