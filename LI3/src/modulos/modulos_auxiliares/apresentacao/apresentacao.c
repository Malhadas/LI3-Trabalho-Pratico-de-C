#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "apresentacao.h"

#define INT    1
#define DOUBLE 2

typedef struct ordenacaoInt {
	int     num_elementos;
	int*    valores_para_ordenar;
	char**  elementos;
}*OrdenacaoInt;

typedef struct ordenacaoDouble {
	int      num_elementos;
	double* valores_para_ordenar;
	char**  elementos;
}*OrdenacaoDouble;

struct apresentacao{
	int  paginas;
	int elem_por_pagina;
	int elem_total;
	int pag_atual;
	int elem_atual;

	char ***elementos;

	OrdenacaoInt    ordInt;
	OrdenacaoDouble ordDouble;
};


/*Funcoes privadas*************************************************************/


void Merge(void* a, char** e, void* esq, char** esqc, int esqCount, void* dir, char** dirc, int dirCount, int tipo) {
	int i,j,k,h,t,m;

	i = 0; j = 0; k = 0; h = 0; t = 0; m = 0;

	while(i<esqCount && j<dirCount) {
		if (tipo==INT){
			if(((int*)esq)[i] < ((int*)dir)[j]){
				((int*)a)[k++]    = ((int*)esq)[i++];
				e[h++] = esqc[t++];
			}

			else {
				((int*)a)[k++] = ((int*)dir)[j++];
				e[h++] = dirc[m++];
			}
		}
		if (tipo==DOUBLE){
			if(((double*)esq)[i] < ((double*)dir)[j]){
				((double*)a)[k++]    = ((double*)esq)[i++];
				e[h++] = esqc[t++];
			}

			else {
				((double*)a)[k++] = ((double*)dir)[j++];
				e[h++] = dirc[m++];
			}
		}
	}

	while(i < esqCount) {
		if (tipo==INT)
			((int*)a)[k++] = ((int*)esq)[i++];
		if (tipo==DOUBLE)
			((double*)a)[k++] = ((double*)esq)[i++];
			
		e[h++] = esqc[t++];		
	}

	while(j < dirCount) {
		if (tipo==INT)
			((int*)a)[k++] = ((int*)dir)[j++];
		if (tipo==DOUBLE)
			((double*)a)[k++] = ((double*)dir)[j++];
			
		e[h++] = dirc[m++];
	}
}


void MergeSort(char** e, void *a,int n, int tipo) {
	int mid,i;
	void *esq, *dir;
	char **esqc, **dirc;

	if(n < 2) return; /*caso de paragem*/

	mid = n/2;

	if(tipo==INT) {
		esq  = (int*)malloc   (mid*      sizeof(int)); 
		dir  = (int*)malloc   ((n- mid)* sizeof(int)); 
	}
	else {
		esq  = (double*)malloc   (mid*      sizeof(double)); 
		dir  = (double*)malloc   ((n- mid)* sizeof(double)); 
	}	
	esqc = (char**)malloc (mid*      sizeof(char*)); 
	dirc = (char**)malloc ((n- mid)* sizeof(char*)); 
	
	for(i = 0;i<mid;i++) {
		if (tipo==INT)    ((int*)esq)[i]    = ((int*)a)[i];
		if (tipo==DOUBLE) ((double*)esq)[i] = ((double*)a)[i];
		esqc[i] = e[i];
		
	}

	for(i = mid;i<n;i++) {
		if (tipo==INT)    ((int*)dir)[i-mid]    = ((int*)a)[i];
		if (tipo==DOUBLE) ((double*)dir)[i-mid] = ((double*)a)[i];
		dirc[i-mid] = e[i];
	}

	MergeSort (esqc, esq, mid  , tipo);
	MergeSort (dirc, dir, n-mid, tipo);
	Merge     (a   , e  , esq  , esqc , mid, dir, dirc, n-mid, tipo);

        free (esq );
        free (dir );
	free (esqc);
	free (dirc);
}


Apresentacao ordena(Apresentacao a, int tipo, int ordem, int maximoAordenar){
	int i,r,j;

	if (tipo==INT)
		MergeSort((a->ordInt)->elementos, (a->ordInt)->valores_para_ordenar, (a->ordInt)->num_elementos, INT);

	if (tipo==DOUBLE)
		MergeSort((a->ordDouble)->elementos, (a->ordDouble)->valores_para_ordenar, (a->ordDouble)->num_elementos, DOUBLE);

	if (ordem==DESCENDENTE){
		for(r=a->elem_total-1, i=0; i<a->paginas && r>=(a->elem_total-1)-maximoAordenar;i++) {
			for(j=0;j<a->elem_por_pagina && r>=(a->elem_total-1)-maximoAordenar;j++,r--) {		
				if (tipo==INT)    a->elementos[i][j] = (a->ordInt)->elementos[r];
				if (tipo==DOUBLE) a->elementos[i][j] = (a->ordDouble)->elementos[r];
			}
		}
	}

	else{
		for(r=0, i=0; i<a->paginas && r<maximoAordenar;i++) {
			for(j=0;j<a->elem_por_pagina && r<maximoAordenar;j++,r++) {		
				if (tipo==INT)    a->elementos[i][j] = (a->ordInt)->elementos[r];
				if (tipo==DOUBLE) a->elementos[i][j] = (a->ordDouble)->elementos[r];
			}
		}
	}

	/*libertar memoria extra*/
	for(;i<a->paginas && r<a->elem_total;i++){
		if(a->elementos[i]) free(a->elementos[i]);
	}

	/*Atualizar contadores*/
	a->elem_total = maximoAordenar;

	if ((maximoAordenar%a->elem_por_pagina)>0)
		a->paginas = (maximoAordenar/(a->elem_por_pagina))+1;
	else    a->paginas = (maximoAordenar/(a->elem_por_pagina));

	return a;
}



Apresentacao recebe_elemento_para_ordenar_Int(Apresentacao a, char* elemento, int tamanho, int valor, int ordem, int maximoAordenar){
	if (!(a->ordInt)){
		a->ordInt = (OrdenacaoInt) malloc(sizeof(struct ordenacaoInt));
		(a->ordInt)->valores_para_ordenar = (int*) malloc((sizeof(int))*a->elem_total); 
		(a->ordInt)->elementos            = (char**) malloc((sizeof(char*))*a->elem_total);
		(a->ordInt)->num_elementos        = 0;
	}

	((a->ordInt)->valores_para_ordenar)[(a->ordInt)->num_elementos] = valor;
	((a->ordInt)->elementos)           [(a->ordInt)->num_elementos] = (char*) malloc((sizeof(char))*(tamanho+1));
	strcpy(((a->ordInt)->elementos)    [(a->ordInt)->num_elementos], elemento);
	(a->ordInt)->num_elementos++;

	if ((a->ordInt)->num_elementos == a->elem_total) {
		a = ordena(a,INT,ordem,maximoAordenar);
	}

	return a;
}


Apresentacao recebe_elemento_para_ordenar_Double(Apresentacao a, char* elemento, int tamanho, double valor, int ordem, int maximoAordenar){
	if (!(a->ordDouble)){
		a->ordDouble = (OrdenacaoDouble) malloc(sizeof(struct ordenacaoDouble));
		(a->ordDouble)->valores_para_ordenar = (double*) malloc((sizeof(double))*a->elem_total); 
		(a->ordDouble)->elementos            = (char**) malloc((sizeof(char*))*a->elem_total);
		(a->ordDouble)->num_elementos        = 0;
	}

	((a->ordDouble)->valores_para_ordenar)[(a->ordDouble)->num_elementos] = valor;
	((a->ordDouble)->elementos)           [(a->ordDouble)->num_elementos] = (char*) malloc((sizeof(char))*(tamanho+1));
	strcpy(((a->ordDouble)->elementos)    [(a->ordDouble)->num_elementos], elemento);
	(a->ordDouble)->num_elementos++;

	if ((a->ordDouble)->num_elementos == a->elem_total) {
		a = ordena(a,DOUBLE,ordem,maximoAordenar);
	}

	return a;
}

Apresentacao recebe_elemento_sem_ordenar(Apresentacao a, char* elemento, int tamanho){
	if ((a->pag_atual)  >= a->paginas) return a;
	if ((a->elem_atual) >= a->elem_por_pagina) {
		(a->pag_atual)++;
		(a->elem_atual)=0;
	}
		
	(a->elementos[a->pag_atual][a->elem_atual]) = (char*) malloc((sizeof(char))*(tamanho+1));
	strcpy(a->elementos[a->pag_atual][a->elem_atual], elemento);
	(a->elem_atual)++;
		
	return a;
}

/*Funcoes publicas*************************************************************/



/*Iniciar struct apresentacao*/

Apresentacao init_apresentacao(int total, int elem_pag_offset){
	int i;
	Apresentacao a = (Apresentacao) malloc(sizeof(struct apresentacao));

	if(elem_pag_offset<=0) a->elem_por_pagina = N_PAG;
	else                   a->elem_por_pagina = N_PAG/elem_pag_offset;

	if ((total%a->elem_por_pagina)>0)
		a->paginas = (total/(a->elem_por_pagina))+1;
	else    a->paginas = (total/(a->elem_por_pagina));

	a->pag_atual  = 0;
	a->elem_atual = 0;
	a->elem_total = total;
	a->elementos  = (char***) malloc ((sizeof(char**))*(a->paginas));

	for (i=0;i<a->paginas;i++)
		a->elementos[i] = (char**) malloc((sizeof(char*))*a->elem_por_pagina);

	a->ordInt    = NULL;
	a->ordDouble = NULL;

	return a;
}

/*Eliminar memória alocada*/
void elimina_apresentacao(Apresentacao a){
	int i,j,r;


	if (a->ordInt) { /*Caso em que se ordenaram Int*/
		if ((a->ordInt)->valores_para_ordenar) {
			free((a->ordInt)->valores_para_ordenar);
			
			for(i=0;i<(a->ordInt)->num_elementos;i++) {
				if(((a->ordInt)->elementos[i]))
					free(((a->ordInt)->elementos[i]));
			}
	
			if((a->ordInt)->elementos)
				free((a->ordInt)->elementos);
		}
		free(a->ordInt);

		for (i=0;i<a->paginas;i++)
			if(a->elementos[i]) free(a->elementos[i]);

		if (a->elementos) free(a->elementos);

		if(a) free(a);

		return;
	}	



	if (a->ordDouble){ /*Caso em que se ordenaram Double*/
		if ((a->ordDouble)->valores_para_ordenar) {
			if((a->ordDouble)->valores_para_ordenar)
				free((a->ordDouble)->valores_para_ordenar);
			
			for(i=0;i<(a->ordDouble)->num_elementos;i++) {
				if(((a->ordDouble)->elementos[i]))
					free(((a->ordDouble)->elementos[i]));
			}
	
			if((a->ordDouble)->elementos)
				free((a->ordDouble)->elementos);
		}
		free(a->ordDouble);

		for (i=0;i<a->paginas;i++)
			if(a->elementos[i]) free(a->elementos[i]);

		if (a->elementos) free(a->elementos);

		if(a) free(a);

		return;
	}



	/*Caso em que não se ordenou*/
	for(r=0,i=0; i<a->paginas && r<a->elem_total;i++) {
		for(j=0;j<a->elem_por_pagina && r<a->elem_total;j++,r++) {
			if(a->elementos[i][j])			
				free(a->elementos[i][j]);
		}
	}

	for(i=0;i<a->paginas;i++) {
		if(a->elementos[i])
			free(a->elementos[i]);
	}

	if (a->elementos) free(a->elementos);

	free(a);
}

/*Guarda elemento na estrutura de apresentacao*/
Apresentacao recebe_elemento (char* elemento, Apresentacao a, int tamanho, int ordenacaoInt, double ordenacaoDouble, int ordem, int maximoAordenar){

	if (ordenacaoInt == SEM_ORDENACAO_INT && ordenacaoDouble == SEM_ORDENACAO_DOUBLE)
		a = recebe_elemento_sem_ordenar(a,elemento,tamanho);

	if (ordenacaoInt != SEM_ORDENACAO_INT && ordenacaoDouble == SEM_ORDENACAO_DOUBLE)
		a = recebe_elemento_para_ordenar_Int(a,elemento,tamanho,ordenacaoInt,ordem,maximoAordenar);

	if (ordenacaoInt == SEM_ORDENACAO_INT && ordenacaoDouble != SEM_ORDENACAO_DOUBLE)
		a = recebe_elemento_para_ordenar_Double(a,elemento,tamanho,ordenacaoDouble,ordem,maximoAordenar);

	return a;
}

/*Pede elemento de determinada pagina e determinada coluna da estrutura apresentacao*/
char* pede_elemento (Apresentacao a, int pagina, int linha){
	if (((pagina-1)*(a->elem_por_pagina) + linha) > (a->elem_total)) return NULL;
	return a->elementos[pagina-1][linha-1];
}


int get_paginas(Apresentacao a){
	return a->paginas;
}


int get_elem_por_pagina(Apresentacao a){
	return a->elem_por_pagina;
}


int get_elem_total(Apresentacao a){
	return a->elem_total;
}

char** get_pag(Apresentacao a, int pagina){
	if (pagina > a->paginas) return NULL;
	return a->elementos[pagina-1];
}

