#ifndef Catalogo_H
#define	Catalogo_H
#include "../modulos_auxiliares/apresentacao/apresentacao.h"
#include "../modulos_auxiliares/avl/avl.h" /*http://adtinfo.org/index.html*/
#include "../../tipos/tipos.h"

#define OK 1 /*Situação de sucesso*/
#define KO 0 /*Situação de insucesso*/

typedef struct catalogo *Cat; /*Tipo opaco para catalogo*/

/*Modulo***********************************************************************/

/*Inicializar o catalogo*/
Cat  init_catalogo       ();

/*Inserir elemento no catalogo. Pode ser uma string com qualquer tamanho*/
Cat  inserir             (Cat c, ELEMENTO str);

/*Remover elemento do catalogo.*/
Cat  remover             (Cat c, ELEMENTO str);

/*Verificar a existência de um elementos no catalogo*/
int  existe              (Cat c, ELEMENTO str);

/*Obter o número de elementos que comecem pela letra argumento*/
int  num_elementos_letra (Cat c, char l );

/*Obter o número de elementos total inserido no catalogo*/
int  num_elementos       (Cat c);

/*eliminar espaço alocado para o catalogo*/
void libertar_catalogo   (Cat c);

/******************************************************************************/

/*Queries**********************************************************************/

/* preenche apresentacao com todos os elementos que obdecem ao filtro.
 * Se o filtro for o caracter * então todos os elementos do catalogo
 * são inseridos na apresentação. Caso o filtro seja uma letra então
 * apenas os elementos que comecem por essa mesma letra serão inseridos*/
Apresentacao preenche_apresentacao_catalogo (Cat c, char filtro);

/******************************************************************************/

/*Apresentacao*****************************************************************/
/*Funções para utilização do modulo importado: apresentacao.*/

/* Obter o elemento da apresentação que está na pagina e na linha argumentos.
 * Devolve NULL se esse elemento não esxistir.*/
char*  apresenta_elemento_catalogo   (Apresentacao a, int pagina, int linha);

/*Obter a página argumento da apresentação. Devolve NULL se essa página não existir*/
char** get_pagina_catalogo           (Apresentacao a, int pagina);

/*Obter o número de elementos por página da apresentacao*/
int    get_elem_por_pagina_catalogo  (Apresentacao a);

/*Obter o numero de paginas da apresentacao*/
int    get_paginas_catalogo          (Apresentacao a);

/*Obter o número de elementos na apresentacao*/
int    get_elem_total_catalogo       (Apresentacao a);

/*Eliminar espaço alocado para a apresentacao*/
void   elimina_apresentacao_catalogo (Apresentacao a);

/******************************************************************************/
#endif
