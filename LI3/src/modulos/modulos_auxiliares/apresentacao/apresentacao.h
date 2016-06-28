#ifndef Apresentacao_H
#define	Apresentacao_H
#include "../../../tipos/tipos.h"

#define N_PAG 20 /*Número de elementos(linhas) por cada página da apresentação*/

/*Valores usados para ordenação (ou não ordenação) dos elementos inseridos para apresentação*/
#define SEM_ORDENACAO_INT    -1
#define SEM_ORDENACAO_DOUBLE -1
#define SEM_ORDEM            -1
#define ASCENDENTE            1
#define DESCENDENTE           2

typedef struct apresentacao* Apresentacao; /*Tipo opaco de apresentação*/

/* Inicializar a apresentação. Deve ser dado em argumento o total de elementos que apresentação irá incluir
 * Assim como um offset que se pretenda incluir para o número de elementos por página. Este offset irá
 * dividir o valor definido por N_PAG de modo a reduzir o número de páginas, se assim se pretender. Caso
 * o valor dado em argumento seja 1 ou menor, então o número de elementos por página não será modificado.*/
Apresentacao init_apresentacao(int total, int elem_pag_offset);

/* Inserir elemento(string). Deverá ser fornecido o tamanho da string a inserir (os elementos não precisam de ter todos os mesmo tamanho).
 * e deverão ser fornecidos dados sobre a ordenação. caso se pretenda ordenar as strings sobre uma determinada ordem de inteiros então
 * deve-se inserir os inteiros correspondentes a cada string aquando da sua inserção pelo argumento ordenacaoInt. o mesmo para uma ordenação
 * com doubles mas usando o argumento ordenacaoDouble. Quando não se pretender ordenação deve-se usar os valores definidos em cima:
 * SEM_ORDENACAO_INT e/ou SEM_ORDENACAO_DOUBLE. Pode ser dada uma ordem descendente ou ascendente à ordenação com o argumento ordem usando
 * ASCENDENTE, DESCENDENTE ou SEM_ORDEM quando não se pretende ordenar. O último argumento existe para os casos em que se pretende ordenar
 * mas apenas apresentar um certo número de elementos, esse certo número pode ser fornecido por este argumento, sendo que quando não se
 * pretende ordenar este argumento é ignorado podendo então ser enviado qualquer valor.
 * É conveniente indicar que a ordenação é realizada internamente com recurso ao algorítmo mergeSort.*/
Apresentacao recebe_elemento (ELEMENTO elemento, Apresentacao a, int tamanho, int ordenacaoInt, double ordenacaoDouble, int ordem, int maximoAordenar);

/*getters*/

/*Para uma determinada página e uma determinada linha obter o elemento respetivo. Caso não exista devolve NULL*/
char* pede_elemento       (Apresentacao a, int pagina, int linha);

/*Obter o número de páginas*/
int   get_paginas         (Apresentacao a);

/*Obter o número de elementos por página*/
int   get_elem_por_pagina (Apresentacao a);

/*Obter o número de elementos total inseridos*/
int   get_elem_total      (Apresentacao a);

/*Devolve uma página completa, sendo a página de número dado com o argumento pagina. Caso a página não exista é devolvido NULL*/
char** get_pag(Apresentacao a, int pagina);

/*******/

/*Eliminar apresentacao*/
void elimina_apresentacao(Apresentacao a);

#endif
