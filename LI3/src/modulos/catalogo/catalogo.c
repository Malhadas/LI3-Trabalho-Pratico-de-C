#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogo.h"


struct catalogo {
	int total;
	int total_letra[26];
	Avl letras[26];
};

/*Funções privadas*************************************************************/


Apresentacao preenche (Travessia t, Apresentacao a) {
	char* elemento;	

	while(1){
		elemento = avl_t_next(t);

		if (elemento==NULL) break;

		a = recebe_elemento(elemento,a,strlen(elemento),SEM_ORDENACAO_INT,SEM_ORDENACAO_DOUBLE,SEM_ORDEM,0);
	}

	return a;
}


/*Critérios para libertar espaço alocado para elementos de um nodo da AVL*/
void libertar (void*item, void*parametros){
	free(item);
}


/*Critérios de comparação para os elementos nos nodos da AVL*/
int comparacao (const void*item1, const void*item2, void*parametros){
	return strcmp((char*)item1, (char*)item2);
}

/*******************/


/*Funções públicas*/

/*Incicalizacao do catálogo*/
Cat init_catalogo(){
	int i;
	Cat c = (Cat) malloc(sizeof(struct catalogo));

	c->total = 0;
	for (i=0;i<=25;i++) {
		c->total_letra[i] = 0;
		c->letras[i] = avl_create(comparacao,NULL,NULL); 
	}

	return c;
}


/*Inserir*/
Cat inserir(Cat c, char*str){

       /* 
	* Aloca-se espaço para uma nova String em vez de
	* ser usada a argumento para assim garantir
	* encapsulamento dos dados.
        */
	char*cod = (char*) malloc((sizeof(char))*(strlen(str)+1));
	strcpy(cod, str);
	(c->total)++;
	(c->total_letra[str[0]-'A'])++;
	avl_insert(c->letras[str[0]-'A'], cod); 

	return c; 
}


/*Libertar catálogo*/
void libertar_catalogo(Cat c){
	int i;

	/*Não existe catálogo para eliminar*/
	if (c==NULL) return;

	for(i=0;i<=25;i++)
		avl_destroy(c->letras[i], libertar);

	free(c);
}


/*Remover*/
Cat remover (Cat c, char*str){
	(c->total)--;
	(c->total_letra[str[0]-'A'])--;
	free(avl_delete(c->letras[str[0]-'A'],str));

	return c;
}


/*Procurar*/
int existe (Cat c, char*str){

	if (c!=NULL){
		if (avl_find(c->letras[str[0]-'A'], str)!=NULL)
			return OK;
	}

	return KO;
}


/*Total de elementos no catálogo*/
int num_elementos(Cat c){
	return c->total;
}


/*Total de elementos de uma letra*/
int num_elementos_letra(Cat c, char l){
	return c->total_letra[l-'A'];
}


Apresentacao preenche_apresentacao_catalogo(Cat c, char filtro){
	Apresentacao a = NULL;
	int i;
	Travessia t = (Travessia) malloc(sizeof(struct avl_traverser));

	if (filtro=='*') {
		a = init_apresentacao(c->total,0);
		for (i=0;i<=25;i++){
			avl_t_init (t, c->letras[i]);
			a = preenche (t,a);
		}

		free(t);
		return a;		
	}

	a = init_apresentacao(c->total_letra[filtro-'A'],0);
	avl_t_init (t, c->letras[filtro-'A']);
	a = preenche (t,a);

	free(t);

	return a;
}


void elimina_apresentacao_catalogo(Apresentacao a){
	elimina_apresentacao(a);
}

char* apresenta_elemento_catalogo(Apresentacao a, int pagina, int linha){
	return pede_elemento(a,pagina,linha);
}


int get_paginas_catalogo(Apresentacao a){
	return get_paginas(a);
}


int get_elem_por_pagina_catalogo(Apresentacao a){
	return get_elem_por_pagina(a);
}


int get_elem_total_catalogo(Apresentacao a){
	return get_elem_total(a);
}

char** get_pagina_catalogo(Apresentacao a, int pag){
	return get_pag(a,pag);
}

/**********************/


