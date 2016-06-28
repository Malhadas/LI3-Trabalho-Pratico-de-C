#include <stdio.h>
#include <stdlib.h>
#include "compra.h"
#include <string.h>


struct compra {
	int quant;
	int tipo;
	int filial;
	int mes;
	double preco;
	char*produto;
	char*cliente;
};


/*********Getters e Setters**********/
int quantidade_compra(Compra c){
	return c->quant;
}

int tipo_compra(Compra c){
	return c->tipo;
}

int filial_compra(Compra c){
	return c->filial;
}

int mes_compra(Compra c){
	return c->mes;
}

double preco_compra(Compra c){
	return c->preco;
}

char* produto_compra(Compra c){
	return c->produto;
}

char* cliente_compra(Compra c){
	return c->cliente;
}

Compra insere_preco_compra(Compra c, double preco){
	c->preco=preco;
	return c;
}

Compra insere_quantidade_compra(Compra c, int quant){
	c->quant=quant;
	return c;
}

Compra insere_tipo_compra(Compra c, int tipo){
	c->tipo=tipo;
	return c;
}

Compra insere_filial_compra(Compra c, int filial){
	c->filial=filial;
	return c;
}

Compra insere_mes_compra(Compra c, int mes){
	c->mes=mes;
	return c;
}

Compra insere_produto_compra(Compra c, char* prod){
	c->produto = prod; /*Não tem mal apenas igualar o apontador, pois em cada módulo será já alocado espaço para inserir a string para que se aponta, deste modo, seria redundante alocar memória aqui também, visto que apenas se pretende inserir em cada módulo e apagar esta compra logo de seguida. Seria redundante e menos eficiente.*/
	return c;
}

Compra insere_cliente_compra(Compra c, char* cli){
	c->cliente = cli; /*Não tem mal apenas igualar o apontador, pois em cada módulo será já alocado espaço para inserir a string para que se aponta, deste modo, seria redundante alocar memória aqui também, visto que apenas se pretende inserir em cada módulo e apagar esta compra logo de seguida. Seria redundante e menos eficiente.*/
	return c;
}
/************************************/


/********Funções privadas************/

int valida_formato_produto(char*s){
	int i;
	
	for(i=0;s[i]!='\0';i++){
		if (i==6) return KO;
		else if ((i==0||i==1)&&(!(s[i]>='A'&&s[i]<='Z'))) return KO;
		else if (!(s[i]>='0'&&s[i]<='9')) return KO;
	}
	
	return OK;
}

int valida_formato_cliente(char*s){
	int i;
	
	for(i=0;s[i]!='\0';i++){
		if (i==5) return KO;
		else if ((i==0)&&(!(s[i]>='A'&&s[i]<='Z'))) return KO;
		else if (!(s[i]>='0'&&s[i]<='9')) return KO;
	}
	
	return OK;
}


int preencher(Compra c, Cat clientes, Cat produtos, char*linha, int i){
	int    auxiliar;
	double auxiliar2;

	switch(i){
		case 0: /*validar cod produto*/
			if (existe(produtos, linha)==OK) {
				c = insere_produto_compra(c, linha);
				return OK;
			}			
			break;

		case 1:/*validar preço*/
			auxiliar2 = atof(linha);
			if ((auxiliar2>PRECO_MIN && auxiliar2<=PRECO_MAX) || strcmp(linha,"0") || strcmp(linha,"0.0")){
				c = insere_preco_compra(c, auxiliar2);
				return OK;
			}
			break;		

		case 2:/*validar quantidade*/
			auxiliar = atoi(linha);
			if (auxiliar>=QUANT_MIN && auxiliar<=QUANT_MAX){
				c = insere_quantidade_compra(c, auxiliar);
				return OK;
			}
			break;

		case 3:/*Validar regime*/
			if (strcmp(linha,"N")==0){
				c = insere_tipo_compra(c, REGIME_N);
				return OK;
			}

			else if (strcmp(linha,"P")==0) {
				c = insere_tipo_compra(c, REGIME_P);
				return OK;
			}

			break;

		case 4:/*Validar cod cliente*/
			if (existe(clientes, linha)==OK) { 
				c = insere_cliente_compra(c, linha);
				return OK;
			}
			break;

		case 5:/*validar mês*/
			auxiliar = atoi(linha);
			if (auxiliar>=1 && auxiliar<=N_MESES){
				c = insere_mes_compra(c, auxiliar);
				return OK;
			}
			break;


		case 6:/*validar filial*/
			auxiliar = atoi(linha);
			if (auxiliar>=1 && auxiliar<=N_FILIAIS){
				c = insere_filial_compra(c, auxiliar);			
				return OK;
			}			
			break;

	}

return KO;
}

/*********************************/


/*************Funções públicas********/
Compra init_compra(){

	Compra c = (Compra) malloc (sizeof (struct compra));

	c->quant   = 0;
	c->tipo    = 0;
	c->filial  = 0;
	c->preco   = 0;
	c->mes     = 0;
	c->produto = NULL;
	c->cliente = NULL;

	return c;
}


void limpa_compra(Compra c){
	
	if(!c) return;
	
	free(c);
}


Compra valida_compra (Compra c, char* linha, Cat clientes, Cat produtos){
	int i;

	linha = (strtok(linha," "));
	if(preencher(c, clientes, produtos, linha, 0)==KO) {
		limpa_compra(c);
		return NULL;
	}

	for(i=1;(linha=strtok(NULL," "))!=NULL;i++) {
		if(preencher(c, clientes, produtos, linha, i)==KO) {
			limpa_compra(c);
			return NULL;
		}
	}

	if (i==7) return c;
	else {
		limpa_compra(c);
		return NULL;
	}
}

