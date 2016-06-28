#ifndef Capsula_H
#define	Capsula_H

#define INT     0   /**usado na inserção de um inteiro****************/
#define DOUBLE  1  /**usado na inserção de um double*****************/
#define AMBOS   2 /**usado na inserção de um inteiro e de um double*/

/*
 * Este módulo tem como objetivo encapsular dados. Com isto pretende-se que se entenda que
 * em certos momentos há a necessidade que uma só função devolva não só um tipo de dados,
 * mas sim vários. Para que não se usem "baldes", ou seja, endereços como argumento que
 * serão modificados e posteriormente utilizados fora da função em questão, tomou-se a
 * opção de criar este módulo auxiliar de nome "capsula" onde se pode guardar um número
 * variável de inteiros e/ou doubles.
 */

typedef struct capsula *Capsula; /*Tipo opaco*/

/*Inicialização da capsula.*/
Capsula  init_capsula      ();

/*Eliminar espaço alocado para a capsula*/
void     libertar_capsula  (Capsula c);

/* Inserir elemento(s) na cápsula. 
 * O argumento tipo deve ser uma das seguintes 3 possibilidades: INT, DOUBLE, AMBOS.
 * Esse argumento irá indicar o que estamos a inserir, sendo que se for INT,
 * o argumento item2 deverá ser NULL e o item1 não. Se for DOUBLE, o argumento
 * item1 deverá ser NULL e o item2 não. Se for AMBOS, nenhum argumento deverá ser NULL*/
Capsula  insere_capsula    (Capsula c, int tipo, int *item1, double *item2);

/*Devolve o tipo da última inserção*/
int      tipo_capsula      (Capsula c);

/* Devolve um dos inteiros presentes na cápsula. O índice irá indicar qual pretendemos.
 * Sendo que índice zero corresponde ao primeiro inserido, 1 ao segundo e por aí adiante.*/
int      int_capsula       (Capsula c, int indice);

/* Devolve um dos doubles presentes na cápsula. O índice irá indicar qual pretendemos.
 * Sendo que índice zero corresponde ao primeiro inserido, 1 ao segundo e por aí adiante.*/
double   double_capsula    (Capsula c, int indice);

/*Devolve a quantidade de inteiros presentes na cápsula*/
int      q1_capsula        (Capsula c);

/*Devolve a quantidade de doubles presentes na cápsula*/
int      q2_capsula        (Capsula c);

#endif
