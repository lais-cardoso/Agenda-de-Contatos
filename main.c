#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>
#include<string.h>
#include "Func.c"


//FUNÇÃO MAIN

int main(){

setlocale(LC_ALL, "Portuguese");
while(1){
	cabecalho();
	menu();	
}
	
	system("PAUSE");
	return 0;
}


