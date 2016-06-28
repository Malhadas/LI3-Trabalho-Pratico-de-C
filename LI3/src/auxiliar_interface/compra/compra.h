#ifndef Compra_H
#define	Compra_H
#include "../../modulos/catalogo/catalogo.h"
#include "../../tipos/tipos.h"

/* 
 * Este módulo tem o objetivo de auxiliar na validação de uma venda.
 */


#define PRECO_MAX 999.99 /*Maior preço possível de uma compra válida*/
#define PRECO_MIN   0.0 /*Menor peço possível de uma compra válida */

#define QUANT_MAX 200  /*Quantidade máxima de produto comprado por compra válida*/
#define QUANT_MIN   1 /*Quantidade mínima de produto comprado por compra válida*/

#define N_FILIAIS 3 /*Número máximo de filiais*/

#define N_MESES  12 /* Número máximo de meses 
		     * pode ser aumentado caso se queira guardar dados ao longo de vários anos
		     * pode ser diminuído para um espaço de tempo mais pequeno
                     */

#define REGIME_N 0  /*Valor inteiro atribuído ao regime de compra N*/
#define REGIME_P 1 /*Valor inteiro atribuido ao regime de compra P*/



typedef struct compra *Compra; /*Tipo opaco de compra*/


/*Modulo***********************************************************************/

/*Inicializa a compra com todos os campos a zero e o cliente e produto a NULL*/
Compra init_compra   ();

/*Elimina o espaço alocado para a compra*/
void   limpa_compra  (Compra c);

/* Recebe um compra inicializada e valida uma linha argumento do tipo COMPRA. 
 * Caso a linha não seja válida a compra é de imediato eliminada (o espaço 
 * alocado é libertado) e devolve-se NULL, caso a linha seja válida devolve-se
 * a compra com os dados validados guardados para posterior utilização.*/
Compra valida_compra (Compra c, COMPRA linha, Cat clientes, Cat produtos);

/******************************************************************************/

/*Getters**********************************************************************/

/*Obter quantidade da compra*/
int    quantidade_compra (Compra c);

/*Obter tipo da compra, N ou P*/
int    tipo_compra       (Compra c);

/*Obter filial da compra*/
int    filial_compra     (Compra c);

/*Obter mes da compra*/
int    mes_compra        (Compra c);

/*Obter preco da compra*/
double preco_compra      (Compra c);

/*Obter produto da compra*/
PRODUTO  produto_compra    (Compra c);

/*Obter cliente da compra*/
CLIENTE  cliente_compra    (Compra c);

/******************************************************************************/

/*Setters**********************************************************************/

/*inserir quantidade da compra*/
Compra insere_quantidade_compra (Compra c, int    quant);

/*Inserir tipo da compra*/
Compra insere_tipo_compra       (Compra c, int     tipo);

/*Inserir filial da compra*/
Compra insere_filial_compra     (Compra c, int   filial);

/*Inserir mes da compra*/
Compra insere_mes_compra        (Compra c, int      mes);

/*Inserir preco da compra*/
Compra insere_preco_compra      (Compra c, double preco);

/*Inserir produto da compra*/
Compra insere_produto_compra    (Compra c, PRODUTO   prod);

/*Inserir cliente da compra*/
Compra insere_cliente_compra    (Compra c, CLIENTE    cli);

/******************************************************************************/

#endif


