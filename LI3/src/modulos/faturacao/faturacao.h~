#ifndef Faturacao_H
#define	Faturacao_H
#include "../modulos_auxiliares/apresentacao/apresentacao.h"
#include "../modulos_auxiliares/capsula/capsula.h"
#include "../modulos_auxiliares/avl/avl.h" /*http://adtinfo.org/index.html*/
#include "../../tipos/tipos.h"

/*
 * Facturação Global: módulo de dados que irá conter as estruturas de dados
 * responsáveis pela resposta eficiente a questões quantitativas que relacionam
 * os produtos às suas vendas mensais, em modo Normal (N) ou em Promoção
 * (P), para cada um dos casos guardando o número de vendas e o valor total de
 * facturação de cada um destes tipos. Este módulo deve referenciar todos os
 * produtos, mesmo os que nunca foram vendidos.
 * Este módulo não contém qualquer referência a clientes, mas deve ser capaz de
 * distinguir os valores obtidos em cada filial; 
 */

#define N_FILIAIS 3 /*Número máximo de filiais*/
#define N_REGIMES 2 /*Número máximo de regimes*/
#define N_MESES  12 /* Número máximo de meses 
		     * pode ser aumentado caso se queira guardar dados ao longo de vários anos
		     * pode ser diminuído para um espaço de tempo mais pequeno
                     */

typedef struct faturacao *Faturacao; /*Tipo opaco de faturacao*/


/*Modulo***********************************************************************/

/*Inicializaçao da faturacao*/
Faturacao    init_faturacao            ();

/* Inserir compra na faturacao. Espera-se que os produtos estejam já todos inseridos
 * Modificando assim apenas os seus valores*/
Faturacao    inserir_compra_faturacao  (Faturacao f, PRODUTO cod, int mes, int tipo, int filial, int quant, float preco);

/*Inserir produto na faturacao sendo que todos os valores são inicializados a zero.*/
Faturacao    inserir_produto_faturacao (Faturacao f, PRODUTO cod);

/*Obter o número de produtos inseridos na faturacao*/
int          get_num_elementos         (Faturacao f);

/*Libertar o espaço alocado para a faturacao*/
void         libertar_faturacao        (Faturacao f);

/******************************************************************************/

/*Queries**********************************************************************/

/* Devolve uma cápsula com dados sobre o produto argumento, no mẽs argumento.
 * Caso o argumento filial seja NULL então os dados são globais, caso contrário
 * serão relativos á filial de número igual ao que esse argumento aponta.
 * A capsula contêm 4 inteiros e 2 doubles. sendo os inteiros (por ordem)
 * quantidade comprada em modo N, quantidade comprada em modo P, vendas em modo N,
 * vendas em modo P. Da mesma foram os doubles são (por ordem) faturacao em modo N,
 * faturacao em modo P. 
 * Consultar a API da capsula para entender como aceder a estes valores.*/
Capsula      total_dados_produto          (Faturacao f, int *filial, int mes, PRODUTO cod);

/* Devolve uma cápsula com dados globais da faturacao entre os meses argumento.
 * Sendo mes1 o primeiro e mes2 o segundo, [mes1..mes2]. A capsula contêm 2 
 * inteiros e 1 double. sendo os inteiros (por ordem) a quantidade global vendida
 * e o número de vendas global. Da mesma foram o double é a faturacao global.
 * Consultar a API da capsula para entender como aceder a estes valores.*/
Capsula      dados_globais_intervalo      (Faturacao f, int  mes1  , int mes2);

/*Devolve uma apresentacao que inclui os produtos nunca comprados.
* Caso o argumento filial seja NULL então os dados são globais, caso contrário
* serão relativos á filial de número igual ao que esse argumento aponta.*/
Apresentacao nunca_comprados              (Faturacao f, int *filial);

/*Obter o número de produtos que nunca foram comprados globalmente*/
int          get_num_nao_comprados_global (Faturacao f);

/******************************************************************************/

/*Apresentacao*****************************************************************/
/*Funções para utilização do modulo importado: apresentacao.*/

/* Obter o elemento da apresentação que está na pagina e na linha argumentos.
 * Devolve NULL se esse elemento não esxistir.*/
char*  apresenta_elemento_faturacao   (Apresentacao a, int pagina, int linha);

/*Obter a página argumento da apresentação. Devolve NULL se essa página não existir*/
char** get_pagina_faturacao           (Apresentacao a, int pagina);

/*Obter o número de elementos por página da apresentacao*/
int    get_elem_por_pagina_faturacao  (Apresentacao a);

/*Obter o numero de paginas da apresentacao*/
int    get_paginas_faturacao          (Apresentacao a);

/*Obter o número de elementos na apresentacao*/
int    get_elem_total_faturacao       (Apresentacao a);

/*Eliminar espaço alocado para a apresentacao*/
void   elimina_apresentacao_faturacao (Apresentacao a);

/******************************************************************************/

/*Capsula**********************************************************************/
/*Funcoes para utilizacao do modulo importado: capsula*/

/*Obter o inteiro do indice argumento presente na capsula*/
int     get_int_capsula_faturacao    (Capsula c, int indice);

/*Obter o double do indice argumento presente na capsula*/
double  get_double_capsula_faturacao (Capsula c, int indice);

/*Libertar espaço alocado para a capsula*/
void    libertar_capsula_faturacao   (Capsula c);

/*obter o tipo da última inserção na cápsula*/
int     get_tipo_capsula_faturacao   (Capsula c);

/*obter a quantidade de inteiros presente na capsula*/
int     get_q1_capsula_faturacao     (Capsula c);

/*obter a quantidade de doubles presente na capsula*/
int     get_q2_capsula_faturacao     (Capsula c);

/******************************************************************************/

#endif
