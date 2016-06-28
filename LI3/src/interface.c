#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "modulos/catalogo/catalogo.h"
#include "modulos/faturacao/faturacao.h"
#include "modulos/gestao/gestao.h"
#include "auxiliar_interface/compra/compra.h"
#include <ctype.h>

#define OK 1
#define KO 0

#define CATALOGO  1
#define FATURACAO 2
#define GESTAO    3

#define BUFFER_GENERICO  32
#define BUFFER_CATALOGO  64
#define BUFFER_VENDAS   128


void ajuda (const int tipo){
	switch(tipo) {

		case 0: 
			/*Logótipo*/
	printf("\n");
	printf("\n      ________________________________________________________");
	printf("\n     /                                                        \\");                                                             
	printf("\n     |   _____            __       __            _            |");
	printf("\n     |  / ____|           \\ \\     / /           | |           |");
	printf("\n     | | |  __  ___ _ __ __\\ \\   / /__ _ __   __| | __ _ ___  |");
	printf("\n     | | | |_ |/ _ \\ '__/ _ \\ \\_/ / _ \\ '_ \\ / _` |/ _` / __| |");
	printf("\n     | | |__| |  __/ | |  __/\\   /  __/ | | | (_| | (_| \\__ \\ |");
	printf("\n     |  \\_____|\\___|_|  \\___| \\_/ \\___|_| |_|\\__,_|\\__,_|___/ |");
	printf("\n     |                                                        |");
	printf("\n     |                 Prima Enter para continuar             |");
	printf("\n     |                 --------------------------             |");
	printf("\n     | LI3 2015/2016                                Grupo: 80 |");
	printf("\n     \\________________________________________________________/");
	printf("\n");
	printf("\n");
	getchar();

	/*    _____            __   ^   __            _           
	 *   / ____|           \ \  |  / /           | |          
         *  | |  __  ___ _ __ __\ \   / /__ _ __   __| | __ _ ___ 
         *  | | |_ |/ _ \ '__/ _ \ \_/ / _ \ '_ \ / _` |/ _` / __|
         *  | |__| |  __/ | |  __/\   /  __/ | | | (_| | (_| \__ \  font: Big
         *   \_____|\___|_|  \___| \_/ \___|_| |_|\__,_|\__,_|___/
         */                                             
                                                      
			break;

                                                      
		case 8:
			/*Texto de saída*/
	printf("\n      _______________________VOLTE SEMPRE_______________________");
	printf("\n     /                            |                             \\");
	printf("\n     |        A sair..            |           2015/2016         |");
	printf("\n     |____________________________|_____________________________|");
	printf("\n     |  Grupo 80                  |        Docentes             |");
	printf("\n     |                            |                             |");
 	printf("\n     |  - Daniel Malhadas A72293  |   - Fernando Martins        |");
	printf("\n     |  - Joel   Morais   A70841  |   - Vitor    Fonte          |");
	printf("\n     |  - Rui    Miranda  A75488  |                             |");
	printf("\n     |____________________________|_____________________________|");
	printf("\n     |                                                          |");
	printf("\n     |         Obrigado por utilizar o nosso GereVendas!        |");
	printf("\n     |                                                          |");
	printf("\n     |                 Prima Enter para terminar                |");
	printf("\n     |                 -------------------------                |");
	printf("\n     |                                                          |");
	printf("\n     \\__________________________________________________________/");
	printf("\n");
	getchar();
			break;

                                                                                                                  
		case 1:
			/*Menu principal*/
	printf("\n      ______________MENU PRINCIPAL____________");
	printf("\n     /                                        \\");
	printf("\n     | Menu principal:                        |");
	printf("\n     |-----------------                       |");
	printf("\n     |                      GereVendas - LI3  |");
	printf("\n     |                                        |");
	printf("\n     | Escreva a letra 'h' para consultar     |");
	printf("\n     | as instruções.                         |");
	printf("\n     |                                        |");
	printf("\n     \\________________________________________/");
	printf("\n");
			break;

		case 5:
			/*Instruções Menu principal*/
	printf("\n      _____________MENU PRINCIPAL_____________");
	printf("\n     /                                        \\");
	printf("\n     | Instruções:                            |");
	printf("\n     |-------------                           |");
	printf("\n     |                      GereVendas - LI3  |");
	printf("\n     |                                        |");
	printf("\n     | 1 - Escreva 'l' para ver uma lista     |");
	printf("\n     |     de funcionalidades que pode        |");
	printf("\n     |     executar.                          |");
	printf("\n     |                                        |");
	printf("\n     | 2 - Escreva 'h' para ver de novo       |");
	printf("\n     |     esta página de instruções.         |");
	printf("\n     |                                        |");
	printf("\n     | 3 - Escreva 't' para ver de novo       |");
	printf("\n     |     o logótipo do projeto.             |");
	printf("\n     |                                        |");
	printf("\n     | 4 - Escreva 'a' para ver a página      |");
	printf("\n     |     'sobre' onde estão informações     |");
	printf("\n     |     relativas ao projeto.              |");
	printf("\n     |                                        |");
	printf("\n     | 5 - Escreva a letra 's' para sair      |");
	printf("\n     |     da aplicação.                      |");
	printf("\n     |                                        |");
	printf("\n     | 6 - Escreva a letra 'r' para poder     |");
	printf("\n     |     re-inserir os ficheiros.           |");
	printf("\n     |                                        |");
	printf("\n     |----------------------------------------|");
	printf("\n     |                                        |");
	printf("\n     |       Prima Enter para continuar       |");
	printf("\n     |       --------------------------       |");
	printf("\n     |                                        |");
	printf("\n     \\________________________________________/");
	printf("\n");
	printf("\n");
	getchar();
			break;

		case 7:
			/*Funcionalidades/Queries*/
	printf("\n      ________________________________MENU PRINCIPAL_____________________________");
	printf("\n     /    |                                                                      \\");
	printf("\n     | Funcionalidades/Queries:                                                   |");
	printf("\n     |--------------------------                                                  |");
	printf("\n     |    |                                                     GereVendas - LI3  |");
	printf("\n     |----|-----------------------------------------------------------------------|");
	printf("\n     | 1  | Escreva 'q2' para obter todos produtos de uma determinada letra.      |");/*feito - Adicionada funcionalidade extra:*/
	printf("\n     |----|-----------------------------------------------------------------------|");/* -> Permite obter todos os produtos de todas as letras*/
	printf("\n     | 2  | Escreva 'q3'para obter dados das vendas e faturação de um produto     |");
	printf("\n     |    | globais ou de uma determinada filial sobre um mês específico.         |");/*feito*/
	printf("\n     |----|-----------------------------------------------------------------------|");
	printf("\n     | 3  | Escreva 'q4' para obter a lista global ou por filial dos produtos     |");/*feito*/
	printf("\n     |    | que nunca foram comprados.                                            |");
	printf("\n     |----|-----------------------------------------------------------------------|");
	printf("\n     | 4  | Escreva 'q5' para ver uma tabela com o número de produtos por mês     |");/*feito*/
	printf("\n     |    | comprados por um determinado cliente.                                 |");
	printf("\n     |----|-----------------------------------------------------------------------|");
	printf("\n     | 5  | Escreva 'q6' para obter o total de vendas e o total faturado entre    |");/*feito*/
	printf("\n     |    | um determinado intervalo de meses.                                    |");
	printf("\n     |----|-----------------------------------------------------------------------|");
	printf("\n     | 6  | Escreva 'q7' para obter todos os clientes que realizaram compras      |");/*feito*/
        printf("\n     |    | em todas as filiais.                                                  |");
	printf("\n     |----|-----------------------------------------------------------------------|");
	printf("\n     | 7  | Escreva 'q8' para obter os clientes que compraram determinado         |");/*feito*/
	printf("\n     |    | produto em determinada filial.                                        |");
	printf("\n     |----------------------------------------------------------------------------|");
	printf("\n     |                                                                            |");
	printf("\n     |                         Prima Enter para ver mais                          |");
	printf("\n     |                         -------------------------                          |");
	printf("\n     |                                                                            |");
	printf("\n     \\___________________________________________________________________________/");
	printf("\n");
	printf("\n");
	getchar();
	printf("\n      ________________________________MENU PRINCIPAL_____________________________");
	printf("\n     /    |                                                                      \\");
	printf("\n     | Funcionalidades/Queries:                                                   |");
	printf("\n     |--------------------------                                                  |");
	printf("\n     |    |                                                     GereVendas - LI3  |");
	printf("\n     |----|-----------------------------------------------------------------------|");
	printf("\n     | 8  | Escreva 'q9' para obter os produtos mais comprados durante um mês     |");/*feito*/
	printf("\n     |    | por um determinado cliente.                                           |");
	printf("\n     |----|-----------------------------------------------------------------------|");
	printf("\n     | 9  | Escreva 'q10'para obter a lista do N produtos mais vendidos durante   |");/*feito*/
	printf("\n     |    | o ano e dados sobre os mesmos.                                        |");
	printf("\n     |----|-----------------------------------------------------------------------|");
	printf("\n     | 10 | Escreva 'q11' para obter os N produtos em que determinado cliente     |");/*feito - Adicionada funcionalidade extra:*/
	printf("\n     |    | gastou mais dinheiro.                                                 |");/* -> Permite obter um Top N em vez de apenas Top 3*/
	printf("\n     |----|-----------------------------------------------------------------------|");
	printf("\n     | 11 | Escreva 'q12' para ver o número de clientes que nunca realizaram      |");/*feito*/
	printf("\n     |    | nenhuma compra e o número de produtos que nunca foi comprado.         |");
	printf("\n     |----------------------------------------------------------------------------|");
	printf("\n     |                                                                            |");
	printf("\n     |                         Prima Enter para continuar                         |");
	printf("\n     |                         --------------------------                         |");
	printf("\n     |                                                                            |");
	printf("\n     \\___________________________________________________________________________/");
	printf("\n");
	printf("\n");
	getchar();
			break;

		case 6:
			/*About*/
	printf("\n      __________________________SOBRE__________________________");
	printf("\n     /                            |                             \\");
	printf("\n     |     GereVendas - LI3       |      2015/2016              |");
	printf("\n     |____________________________|_____________________________|");
	printf("\n     |  Grupo 80                  |        Docentes             |");
	printf("\n     |                            |                             |");
 	printf("\n     |  - Daniel Malhadas A72293  |   - Fernando Martins        |");
	printf("\n     |  - Joel   Morais   A70841  |   - Vitor    Fonte          |");
	printf("\n     |  - Rui    Miranda  A75488  |                             |");
	printf("\n     |____________________________|_____________________________|");
	printf("\n     |                                                          |");
	printf("\n     |                 Prima Enter para continuar               |");
	printf("\n     |                 --------------------------               |");
	printf("\n     |                                                          |");
	printf("\n     \\__________________________________________________________/");
	printf("\n");
	getchar();

			break;

		case 2:
			/*Apresentacao de lista*/
	printf("\n      ______________APRESENTAÇÃO______________");
	printf("\n     /                                        \\");
	printf("\n     | Instruções:                            |");
	printf("\n     |-------------                           |");
	printf("\n     |                                        |");
	printf("\n     | 1 - Escreva a letra 'p' seguida de     |");
	printf("\n     |     um número para avançar para a      |");
	printf("\n     |     página desse número específico.    |");
	printf("\n     |                                        |");
	printf("\n     | 2 - Escreva '>' para avançar para a    |");
	printf("\n     |     página seguinte.                   |");
	printf("\n     |                                        |");
	printf("\n     | 3 - Escreva '<' para retroceder para   |");
	printf("\n     |     a página anterior.                 |");
	printf("\n     |                                        |");
	printf("\n     | 4 - Escreva a letra 's' para voltar    |");
	printf("\n     |     ao menu principal.                 |");
	printf("\n     |                                        |");
	printf("\n     | 5 - Escreva a letra 'h' para poder     |");
	printf("\n     |     Consultar as instruções.           |");
	printf("\n     |                                        |");
	printf("\n     |----------------------------------------|");
	printf("\n     |                                        |");
	printf("\n     |       Prima Enter para continuar       |");
	printf("\n     |       --------------------------       |");
	printf("\n     |                                        |");
	printf("\n     \\________________________________________/");
	printf("\n");
	printf("\n");
	getchar();
			break;

		case 3:
	printf("\n");
	printf("\n      ________CARREGAMENTO DE FICHEIROS_______");
	printf("\n     /                                        \\");
	printf("\n     |   Ficheiro de produtos                 |");
	printf("\n     |------------------------                |");
	printf("\n     |                                        |");
	printf("\n     |  Forneça um nome para o ficheiro       |");
	printf("\n     |  de produtos.                          |");
	printf("\n     |                                        |");
	printf("\n     |  Caso não queira escreva '*' e         |");
	printf("\n     |  será usado o nome 'Produtos.txt'      |");
	printf("\n     |  por defeito.                          |");
	printf("\n     |                                        |");
	printf("\n     \\________________________________________/");
	printf("\n");
	printf("\n     Nome do ficheiro: ");
			break;


		case 4:
	printf("\n");
	printf("\n      ________CARREGAMENTO DE FICHEIROS_______");
	printf("\n     /                                        \\");
	printf("\n     |   Ficheiro de clientes                 |");
	printf("\n     |------------------------                |");
	printf("\n     |                                        |");
	printf("\n     |  Forneça um nome para o ficheiro       |");
	printf("\n     |  de produtos.                          |");
	printf("\n     |                                        |");
	printf("\n     |  Caso não queira escreva '*' e         |");
	printf("\n     |  será usado o nome 'Clientes.txt'      |");
	printf("\n     |  por defeito.                          |");
	printf("\n     |                                        |");
	printf("\n     \\________________________________________/");
	printf("\n");
	printf("\n     Nome do ficheiro: ");
			break;

	case 9:
	printf("\n");
	printf("\n      _________________QUERY 2________________");
	printf("\n     /                                        \\");
	printf("\n     | Produtos de uma dada letra             |");
	printf("\n     |---------------------------             |");
	printf("\n     |                                        |");
	printf("\n     |  Forneça uma letra                     |");
	printf("\n     |                                        |");
	printf("\n     |  Caso queira a lista de todos os       |"); 
        printf("\n     |  produtos escreva '*'                  |");
	printf("\n     |                                        |");
	printf("\n     \\________________________________________/");
	printf("\n");
	printf("\n     Escreva a letra: ");
	break;

	case 10:
	printf("\n");
	printf("\n      _________________QUERY 3________________");
	printf("\n     /                                        \\");
	printf("\n     | Dados sobre produto                    |");
	printf("\n     |--------------------                    |");
	printf("\n     |                                        |");
	printf("\n     |  Forneça o produto                     |");
	printf("\n     |                                        |");
	printf("\n     \\________________________________________/");
	printf("\n");
	printf("\n     Escreva o produto: ");
	break;
	
	case 11:
	printf("\n");
	printf("\n      _________________QUERY 3________________");
	printf("\n     /                                        \\");
	printf("\n     | Dados sobre produto                    |");
	printf("\n     |--------------------                    |");
	printf("\n     |                                        |");
	printf("\n     |  Forneça o mês                         |");
	printf("\n     |                                        |");
	printf("\n     \\________________________________________/");
	printf("\n");
	printf("\n     Escreva o mês: ");
	break;

	case 12:
	printf("\n");
	printf("\n      _________________QUERY 3________________");
	printf("\n     /                                        \\");
	printf("\n     | Dados sobre produto                    |");
	printf("\n     |--------------------                    |");
	printf("\n     |                                        |");
	printf("\n     |  Forneça a filial                      |");
	printf("\n     |                                        |");
	printf("\n     |  Escreva '*' para obter resultados     |");
	printf("\n     |  globais, de todas as filiais          |");
	printf("\n     |                                        |");
	printf("\n     \\________________________________________/");
	printf("\n");
	printf("\n     Escreva filial: ");
	break;

	case 13:
	printf("\n");
	printf("\n      ________CARREGAMENTO DE FICHEIROS_______");
	printf("\n     /                                        \\");
	printf("\n     |   Ficheiro de vendas                   |");
	printf("\n     |---------------------                   |");
	printf("\n     |                                        |");
	printf("\n     |  Forneça um nome para o ficheiro       |");
	printf("\n     |  de vendas.                            |");
	printf("\n     |                                        |");
	printf("\n     |  Caso não queira escreva '*' e         |");
	printf("\n     |  será usado o nome 'Vendas_1M.txt'     |");
	printf("\n     |  por defeito.                          |");
	printf("\n     |                                        |");
	printf("\n     \\________________________________________/");
	printf("\n");
	printf("\n     Nome do ficheiro: ");
			break;


	case 14:
	printf("\n");
	printf("\n      _________________QUERY 4________________");
	printf("\n     /                                        \\");
	printf("\n     | Produtos nunca vendidos                |");
	printf("\n     |------------------------                |");
	printf("\n     |                                        |");
	printf("\n     |  Forneça a filial                      |");
	printf("\n     |                                        |");
	printf("\n     |  Escreva '*' para obter resultados     |");
	printf("\n     |  globais, de todas as filiais          |");
	printf("\n     |                                        |");
	printf("\n     \\________________________________________/");
	printf("\n");
	printf("\n     Escreva filial: ");
	break;


	case 15:
	printf("\n");
	printf("\n      _________________QUERY 6________________");
	printf("\n     /                                        \\");
	printf("\n     | Dados Globais num intervalo            |");
	printf("\n     |----------------------------            |");
	printf("\n     |                                        |");
	printf("\n     |  Forneça o primeiro mês                |");
	printf("\n     |                                        |");
	printf("\n     \\________________________________________/");
	printf("\n");
	printf("\n     Escreva o mês: ");
	break;

	case 16:
	printf("\n");
	printf("\n      _________________QUERY 6________________");
	printf("\n     /                                        \\");
	printf("\n     | Dados Globais num intervalo            |");
	printf("\n     |----------------------------            |");
	printf("\n     |                                        |");
	printf("\n     |  Forneça o segundo mês                 |");
	printf("\n     |                                        |");
	printf("\n     \\________________________________________/");
	printf("\n");
	printf("\n     Escreva o mês: ");
	break;

	case 17:
	printf("\n");
	printf("\n      _________________QUERY 5________________");
	printf("\n     /                                        \\");
	printf("\n     | Dados sobre cliente                    |");
	printf("\n     |--------------------                    |");
	printf("\n     |                                        |");
	printf("\n     |  Forneça o cliente                     |");
	printf("\n     |                                        |");
	printf("\n     \\________________________________________/");
	printf("\n");
	printf("\n     Escreva o cliente: ");
	break;

	case 18:
	printf("\n");
	printf("\n      ________________QUERY 11________________");
	printf("\n     /                                        \\");
	printf("\n     | Top N cliente                          |");
	printf("\n     |--------------                          |");
	printf("\n     |                                        |");
	printf("\n     |  Forneça o cliente                     |");
	printf("\n     |                                        |");
	printf("\n     \\________________________________________/");
	printf("\n");
	printf("\n     Escreva o cliente: ");
	break;

	case 19:
	printf("\n");
	printf("\n      ________________QUERY 11________________");
	printf("\n     /                                        \\");
	printf("\n     | Top N cliente                          |");
	printf("\n     |--------------                          |");
	printf("\n     |                                        |");
	printf("\n     |  Forneça o numero de produtos          |");
	printf("\n     |  (exemplo: 3 para Top3; 10 para        |");
	printf("\n     |  Top 10; etc...)                       |");
	printf("\n     |                                        |");
	printf("\n     \\________________________________________/");
	printf("\n");
	printf("\n     Escreva o número do top: ");
	break;

	case 20:
	printf("\n");
	printf("\n      ________________QUERY 10________________");
	printf("\n     /                                        \\");
	printf("\n     | Top N produtos                         |");
	printf("\n     |---------------                         |");
	printf("\n     |                                        |");
	printf("\n     |  Forneça o numero de produtos          |");
	printf("\n     |  (exemplo: 3 para Top3; 10 para        |");
	printf("\n     |  Top 10; etc...)                       |");
	printf("\n     |                                        |");
	printf("\n     \\________________________________________/");
	printf("\n");
	printf("\n     Escreva o número do top: ");
	break;

	case 21:
	printf("\n");
	printf("\n      _________________QUERY 9__________________");
	printf("\n     /                                          \\");
	printf("\n     | produtos mais comprados (descendente)    |");
	printf("\n     |------------------------                  |");
	printf("\n     |                                          |");
	printf("\n     |  Forneça o cliente                       |");
	printf("\n     |                                          |");
	printf("\n     \\__________________________________________/");
	printf("\n");
	printf("\n     Escreva o cliente: ");
	break;
	
	case 22:
	printf("\n");
	printf("\n      _________________QUERY 9__________________");
	printf("\n     /                                          \\");
	printf("\n     | produtos mais comprados (descendente)    |");
	printf("\n     |------------------------                  |");
	printf("\n     |                                          |");
	printf("\n     |  Forneça o mês                           |");
	printf("\n     |                                          |");
	printf("\n     \\__________________________________________/");
	printf("\n");
	printf("\n     Escreva o mês: ");
	break;

	case 23:
	printf("\n");
	printf("\n      _________________QUERY 8__________________");
	printf("\n     /                                          \\");
	printf("\n     | clientes que compraram produto           |");
	printf("\n     |-------------------------------           |");
	printf("\n     |                                          |");
	printf("\n     |  Forneça o produto                       |");
	printf("\n     |                                          |");
	printf("\n     \\__________________________________________/");
	printf("\n");
	printf("\n     Escreva o produto: ");
	break;

	}

}


void apresenta(Apresentacao a,int tipo){
	int i, j, r, z, y, w;
	char opcao[BUFFER_GENERICO]="";

	/*Imprimir instruções*/
	ajuda(2);

	switch(tipo){

		case CATALOGO :
			z = get_paginas_catalogo(a);
			y = get_elem_por_pagina_catalogo(a);
			w = get_elem_total_catalogo(a);
			break;

		case FATURACAO :
			z = get_paginas_faturacao(a);
			y = get_elem_por_pagina_faturacao(a);
			w = get_elem_total_faturacao(a);
			break;

		case GESTAO :
			z = get_paginas_gestao(a);
			y = get_elem_por_pagina_gestao(a);
			w = get_elem_total_gestao(a);
			break;

		default :
			z=0;
			y=0;
			w=0;
			break;

		
	}

	for(i=1, r=1; i<=z;){

		printf("\n      _____________________");
		printf("\n     /                     \\");
		printf("\n     | PÁGINA %d de %d",i,z);
		printf("\n     | --------------------");
		printf("\n     | TOTAL %d", w);
		printf("\n     \\_____________________/");
		printf("\n     /                     \\\n");


		switch(tipo){

			case CATALOGO:
				for(j=1;j<=y;j++,r++) {
					if (apresenta_elemento_catalogo(a,i,j)!=NULL)
						printf("     | %d - %s\n", r, apresenta_elemento_catalogo(a,i,j));
				}
				break;

			case FATURACAO:
				for(j=1;j<=y;j++,r++) {
					if (apresenta_elemento_faturacao(a,i,j)!=NULL)
						printf("     | %d - %s\n", r, apresenta_elemento_faturacao(a,i,j));
				}
				break;

			case GESTAO:
				for(j=1;j<=y;j++,r++) {
					if (apresenta_elemento_gestao(a,i,j)!=NULL)
						printf("     | %d - %s\n", r, apresenta_elemento_gestao(a,i,j));
				}
				break;

		}

		printf("     \\_____________________/\n");

			if((scanf("%s", opcao))<=0) {
				getchar();
				continue;
			}
			/*getchar "elimina" o Enter ignorado pelo scanf*/
			getchar();

			switch(tolower(opcao[0])) {


				case 'p' :
					if(atoi(opcao+1)>0 && atoi(opcao+1)<=z){
						i  = atoi(opcao+1);
						r = y*i-(y-1);
						break;
					}
					printf("\nERRO: Inseriu uma página inválida: %s.",opcao);
					printf("\nA voltar à página %d.\n",i);
					r-=y;
					break;


				case '>' :
					if (i==z) return;
					i++;
					break;


				case '<' :
					if (i<=1) {
						if (r<=21) {
							r=1;
							break;
						}
						r-=y*2;
						break;
					}
					i--;
					r-=y*2;
					break;
	
			
				case 's' :
					printf("\nA voltar ao Menu Principal..\n"); 
					return;			
		

				case 'h' :
					ajuda(2);
					r-=y;
					break;			


				default :
					printf("\nERRO: Inseriu uma opção inválida: %s.",opcao);
					printf("\nA voltar à página %d.\n",i);
					r-=y;
			 }
	}
}

/*
 *
 * Vendas:   891.108 linhas válidas
 *
 */
int ler_compras(char* ficheiro, Cat clientes, Cat produtos, Faturacao f, Gestao g){
	FILE *fp;
	int elementos = 0; 
	float tempo;
    	char linha[BUFFER_VENDAS], *ap;
	clock_t tinicial, tfinal;
	Compra compra = NULL;
	int total;
	tinicial = clock(); /*Mede tempo no início*/

	if(strlen(ficheiro)<4) return KO;
	if (strcmp(ficheiro+((strlen(ficheiro))-4), ".txt")!=0){
		printf("\nERRO: O ficheiro tem uma extensão inválida (não é .txt).\n");	
		return KO;
	}	

	if (!(fp = fopen(ficheiro,"r"))) return KO;
	
    	for (total=0;fgets(linha, BUFFER_VENDAS, fp) != NULL;total++) {
        	ap = strtok(linha, "\n\r");

        	if (ap != NULL) {
			compra = init_compra();
			if((compra=valida_compra(compra, ap, clientes, produtos))) {
            			elementos++;

				f = inserir_compra_faturacao (f, produto_compra    (compra)
					                       , mes_compra        (compra)
							       , tipo_compra       (compra)   
                                                               , filial_compra     (compra)
                                                               , quantidade_compra (compra)
							       , preco_compra      (compra)
							     );

			        g = inserir_compra_gestao  (g, cliente_compra    (compra)
							     , produto_compra    (compra)
   							     , mes_compra        (compra)
							     , tipo_compra       (compra)   
                                                             , filial_compra     (compra)
                                                             , quantidade_compra (compra)
							     , preco_compra      (compra)
							 );
				limpa_compra(compra);

        		}
    		}
	}

	fclose(fp);

	tfinal = clock(); /*Mede tempo no fim*/
	
	tempo = (float) tfinal - tinicial;

	printf("      ________________________________________________________________\n");
	printf("     /                                                                \\\n");
	printf("     | Ficheiro utilizado:                      %s\n", ficheiro);
	printf("     |----------------------------------------------------------------\n");
   	printf("     | Total de compras inseridas:              %d de %d\n", elementos,total);
	printf("     |----------------------------------------------------------------\n");
	printf("     | Tempo total a inserir elementos:         %f\n", tempo/CLOCKS_PER_SEC);
	printf("     |----------------------------------------------------------------\n");
	printf("     | Tempo médio por inserção:                %f\n", (tempo/elementos)/CLOCKS_PER_SEC);
	printf("     |----------------------------------------------------------------\n");
	printf("     |                                                                \n");
	printf("     |              Prima Enter para continuar                        \n");
	printf("     |              --------------------------                        \n");
	printf("     \\________________________________________________________________/\n");
	printf("\n");
	getchar();

	return OK;
}




/* 
 *
 * clientes: 16.384
 * Produtos: 171.008
 *
 */
int ler_catalogo(char *ficheiro, Cat c, Faturacao f, Gestao g) {
	FILE *fp;
	int elementos = 0; 
	float tempo;
    	char linha[BUFFER_CATALOGO], *ap;
	clock_t tinicial, tfinal;
	int total;

	tinicial = clock(); /*Mede tempo no início*/
	
	if(strlen(ficheiro)<4) return KO;
	if (strcmp(ficheiro+((strlen(ficheiro))-4), ".txt")!=0){
		printf("\nERRO: O ficheiro tem uma extensão inválida (não é .txt).\n");	
		return KO;
	}	

	if (!(fp = fopen(ficheiro,"r"))) return KO;

    	for (total=0;fgets(linha, BUFFER_CATALOGO, fp) != NULL;total++) {
        	ap = strtok(linha, "\n\r");

        	if (ap != NULL) {
            		elementos++;
            		             c = inserir                   (c, ap);
			if (f)       f = inserir_produto_faturacao (f, ap);
			if (f && g)  g = inserir_produto_gestao    (g, ap);
			if (!f && g) g = inserir_cliente_gestao    (g, ap);
        	}
    	}

	fclose(fp);

	tfinal = clock(); /*Mede tempo no fim*/
	
	tempo = (float) tfinal - tinicial;

	printf("      ________________________________________________________________\n");
	printf("     /                                                                \\\n");
	printf("     | Ficheiro utilizado:                      %s\n", ficheiro);
	printf("     |----------------------------------------------------------------\n");
   	printf("     | Total de elementos inseridos:            %d de %d\n", elementos, total);
	printf("     |----------------------------------------------------------------\n");
	printf("     | Tempo total a inserir elementos:         %f\n", tempo/CLOCKS_PER_SEC);
	printf("     |----------------------------------------------------------------\n");
	printf("     | Tempo médio por inserção:                %f\n", (tempo/elementos)/CLOCKS_PER_SEC);
	printf("     |----------------------------------------------------------------\n");
	printf("     |                                                                \n");
	printf("     |              Prima Enter para continuar                        \n");
	printf("     |              --------------------------                        \n");
	printf("     \\________________________________________________________________/\n");
	printf("\n");
	getchar();

	return OK;
}



void libertar_memoria_catalogo(Cat c){
	int elementos = 0; 
	float tempo;
	clock_t tinicial, tfinal;

	elementos = num_elementos(c);

	tinicial = clock(); /*Mede tempo no início*/

	libertar_catalogo(c);

	tfinal = clock(); /*Mede tempo no fim*/
	
	tempo = (float) tfinal - tinicial;

	printf("      __________________________________________________________\n");
	printf("     /                                                          \\\n");
   	printf("     | Total de elementos removidos:            %d\n", elementos);
	printf("     |----------------------------------------------------------\n");
	printf("     | Tempo total a remover elementos:         %f\n", tempo/CLOCKS_PER_SEC);
	printf("     |----------------------------------------------------------\n");
	printf("     | Tempo médio por remoção:                 %f\n", (tempo/elementos)/CLOCKS_PER_SEC);
	printf("     |----------------------------------------------------------\n");
	printf("     |                                                          \n");
	printf("     |              Prima Enter para continuar                  \n");
	printf("     |              --------------------------                  \n");
	printf("     \\__________________________________________________________/\n");
	printf("\n");
	getchar();

}


void libertar_memoria_gestao(Gestao g){
	int elementos = 0; 
	float tempo;
	clock_t tinicial, tfinal;

	elementos = num_elementos_gestao(g);

	tinicial = clock(); /*Mede tempo no início*/

	libertar_gestao(g);

	tfinal = clock(); /*Mede tempo no fim*/
	
	tempo = (float) tfinal - tinicial;

	printf("      __________________________________________________________\n");
	printf("     /                                                          \\\n");
   	printf("     | Total de elementos removidos:            %d\n", elementos);
	printf("     |----------------------------------------------------------\n");
	printf("     | Tempo total a remover elementos:         %f\n", tempo/CLOCKS_PER_SEC);
	printf("     |----------------------------------------------------------\n");
	printf("     | Tempo médio por remoção:                 %f\n", (tempo/elementos)/CLOCKS_PER_SEC);
	printf("     |----------------------------------------------------------\n");
	printf("     |                                                          \n");
	printf("     |              Prima Enter para continuar                  \n");
	printf("     |              --------------------------                  \n");
	printf("     \\__________________________________________________________/\n");
	printf("\n");
	getchar();

}


void libertar_memoria_faturacao(Faturacao f){
	int elementos = 0; 
	float tempo;
	clock_t tinicial, tfinal;

	elementos = get_num_elementos(f);

	tinicial = clock(); /*Mede tempo no início*/

	libertar_faturacao(f);

	tfinal = clock(); /*Mede tempo no fim*/
	
	tempo = (float) tfinal - tinicial;

	printf("      __________________________________________________________\n");
	printf("     /                                                          \\\n");
   	printf("     | Total de elementos removidos:            %d\n", elementos);
	printf("     |----------------------------------------------------------\n");
	printf("     | Tempo total a remover elementos:         %f\n", tempo/CLOCKS_PER_SEC);
	printf("     |----------------------------------------------------------\n");
	printf("     | Tempo médio por remoção:                 %f\n", (tempo/elementos)/CLOCKS_PER_SEC);
	printf("     |----------------------------------------------------------\n");
	printf("     |                                                          \n");
	printf("     |              Prima Enter para continuar                  \n");
	printf("     |              --------------------------                  \n");
	printf("     \\__________________________________________________________/\n");
	printf("\n");
	getchar();

}

void ler_ficheiros(Cat clientes, Cat produtos, Faturacao f, Gestao g){
	char opcao[BUFFER_GENERICO];	
		
	/*Carregamento de ficheiros*/
	while(1){
		ajuda(4); /*clientes*/
		if((scanf("%s", opcao))<=0) {
			getchar();
			continue;
		}
		/*getchar "elimina" o Enter ignorado pelo scanf*/
		getchar();

		if ((strcmp(opcao,"*"))==0) {
			if ((ler_catalogo("Clientes.txt", clientes, NULL, g))==KO)
			printf("\nERRO: O ficheiro com o nome por defeito não se encontra nesta diretoria.\n");
			else break;
		}

		else if ((ler_catalogo(opcao, clientes, NULL, g))==KO) printf("\nERRO: Não existe nenhum ficheiro com esse nome.\n");
		      else break;
	}

	while(1){
		ajuda(3);/*produtos*/
		if((scanf("%s", opcao))<=0) {
			getchar();
			continue;
		}
		/*getchar "elimina" o Enter ignorado pelo scanf*/
		getchar();

		if ((strcmp(opcao,"*"))==0) {
			if ((ler_catalogo("Produtos.txt", produtos, f, g))==KO)
			printf("\nERRO: O ficheiro com o nome por defeito não se encontra nesta diretoria.\n");
			else break;
		}

		else if ((ler_catalogo(opcao, produtos, f, g))==KO) printf("\nERRO: Não existe nenhum ficheiro com esse nome.\n");
		      else break;
	}

	while(1){
		ajuda(13);/*compras*/
		if((scanf("%s", opcao))<=0) {
			getchar();
			continue;
		}
		getchar();

		if ((strcmp(opcao,"*"))==0) {
			if ((ler_compras("Vendas_1M.txt", clientes, produtos, f, g))==KO)
			printf("\nERRO: O ficheiro com o nome por defeito não se encontra nesta diretoria.\n");
			else break;
		}

		else if ((ler_compras(opcao, clientes, produtos, f, g))==KO) printf("\nERRO: Não existe nenhum ficheiro com esse nome.\n");
		      else break;
	}

}



void queries (int q, Cat c1, Cat c2, Faturacao f, Gestao g){
	Apresentacao a = NULL;
	char opcao[BUFFER_GENERICO], item1[BUFFER_GENERICO];
	int item2;
	int item3;
	int m,filial,t;
	int i = 0;
	Capsula capsula = NULL;
	float tempo;
	clock_t tinicial, tfinal;

	switch(q){
		case 2:
			while(1){
				ajuda(9);

				if(scanf("%s",opcao)<=0) {
					getchar();
					printf("\nERRO: Opção inválida.\n");
					continue;
				}
				getchar();

				if ((toupper(opcao[0])>='A' && toupper(opcao[0])<='Z')||opcao[0]=='*') {
					tinicial = clock(); /*Mede tempo no início*/
					a = preenche_apresentacao_catalogo(c2, toupper(opcao[0]));
					tfinal = clock(); /*Mede tempo no fim*/
					tempo = (float) tfinal - tinicial;					
					printf("     Resultado obtido em: %f\n",tempo/CLOCKS_PER_SEC);					
					apresenta(a,CATALOGO);
					elimina_apresentacao_catalogo(a);
					a = NULL;
					break;
				}

			printf("\nERRO: Opção inválida.\n");

			}
			break;
	
		case 3:
			while(1){

				ajuda(11);
				if(scanf("%d",&item2)<=0) {
					getchar();
					printf("\nERRO: Opção inválida.\nPor favor escreva um número entre 1 e 12 para o mês.\n");
					continue;
				}
				getchar();			

				if (!(item2>=1&&item2<=12)) {
					printf("\nERRO: Opção inválida.\nPor favor escreva um número entre 1 e 12 para o mês.\n");
					continue;
				}

				ajuda(12);
				if(scanf("%s",item1)<=0) {
					getchar();
					printf("\nERRO: Opção inválida.\nPor favor escolha uma filial válida.\nOu então escreva'*' para obter dados globais.\n");
					continue;
				}
				getchar();

				if (strcmp(item1,"*")!=0 && !(atoi(item1)>=1&&atoi(item1)<=N_FILIAIS)){
					printf("\nERRO: Opção inválida.\nPor favor escolha uma filial válida.\nOu então escreva'*' para obter dados globais.\n");
					continue;
				}

				ajuda(10);
				if(scanf("%s",opcao)<=0) {
					getchar();
					printf("\nERRO: Opção inválida.\n");
					continue;
				}
				getchar();


				if (strcmp(item1,"*")==0) {
					tinicial = clock(); /*Mede tempo no início*/
					capsula = total_dados_produto(f,NULL,item2, opcao);
					tfinal = clock(); /*Mede tempo no fim*/
					tempo = (float) tfinal - tinicial;					
					printf("     Resultado obtido em: %f\n",tempo/CLOCKS_PER_SEC);	
					if (!capsula){
						printf("\n     O produto indicado não está registado.\n");
						printf("\nA voltar ao Menu Principal..\n");
						break;
					}
					printf("\n");
					printf("      ___________________PRODUTO %s__________________________\n",opcao);
					printf("     /                                                           \\\n");
					printf("     | Mês: %d\n",item2);
					printf("     |--------------------------Quantidade-----------------------\n");
   					printf("     | Total global de quantidade vendida em modo N:   %d\n", get_int_capsula_faturacao(capsula,0));
					printf("     | Total global de quantidade vendida em modo P:   %d\n", get_int_capsula_faturacao(capsula,1));
					printf("     |---------------------------Vendas--------------------------\n");
					printf("     | Total Número de vendas em modo N:  %d\n", get_int_capsula_faturacao(capsula,2));
					printf("     | Total Número de vendas em modo P:  %d\n", get_int_capsula_faturacao(capsula,3));
					printf("     |---------------------------Lucro---------------------------\n");
					printf("     | Total global de lucro em modo  N:  %.2f\n", get_double_capsula_faturacao(capsula,0));
					printf("     | Total global de lucro em modo  P:  %.2f\n", get_double_capsula_faturacao(capsula,1));
					printf("     |---------------------------Total---------------------------\n");
					printf("     | TOTAl QUANTIDADE: %d\n",get_int_capsula_faturacao(capsula,0)+get_int_capsula_faturacao(capsula,1));
					printf("     | TOTAL FATURAÇÃO:  %.2f\n", get_double_capsula_faturacao(capsula,0)+get_double_capsula_faturacao(capsula,1));
					printf("     | TOTAL VENDAS:     %d\n",get_int_capsula_faturacao(capsula,2)+get_int_capsula_faturacao(capsula,3));
					printf("     |-----------------------------------------------------------\n");
					printf("     |                                                          \n");
					printf("     |                  Prima Enter para continuar                  \n");
					printf("     |                  --------------------------                  \n");
					printf("     \\__________________________________________________________/\n");
					printf("\n");
					getchar();
					printf("\nA voltar ao Menu Principal..\n");

					libertar_capsula_faturacao(capsula);

					break;
				}

				if ((item3=atoi(item1))>=0){
					tinicial = clock(); /*Mede tempo no início*/
					capsula = total_dados_produto(f,&item3,item2, opcao);
					tfinal = clock(); /*Mede tempo no fim*/
					tempo = (float) tfinal - tinicial;					
					printf("     Resultado obtido em: %f\n",tempo/CLOCKS_PER_SEC);	

					if (!capsula){
						printf("\nERRO: O produto indicado não está registado.\n");
						printf("\nA voltar ao Menu Principal..\n");
						break;
					}


					printf("\n");
					printf("      ___________________PRODUTO %s__________________________\n",opcao);
					printf("     /                                                           \\\n");
					printf("     | Mês: %d\n",item2);
					printf("     |--------------------------Quantidade-----------------------\n");
   					printf("     | Total na filial %d de quantidade vendida em modo N:  %d\n", item3, get_int_capsula_faturacao(capsula,0));
					printf("     | Total na filial %d de quantidade vendida em modo P:  %d\n", item3, get_int_capsula_faturacao(capsula,1));
					printf("     |---------------------------Vendas--------------------------\n");
   					printf("     | Total na filial %d de vendas em modo N:  %d\n", item3, get_int_capsula_faturacao(capsula,2));
					printf("     | Total na filial %d de vendas em modo P:  %d\n", item3, get_int_capsula_faturacao(capsula,3));
					printf("     |---------------------------Lucro---------------------------\n");
					printf("     | Total na filial %d de lucro em modo  N:  %.2f\n", item3, get_double_capsula_faturacao(capsula,0));
					printf("     | Total na filial %d de lucro em modo  P:  %.2f\n", item3, get_double_capsula_faturacao(capsula,1));
					printf("     |---------------------------Total---------------------------\n");
					printf("     | TOTAl QUANTIDADE: %d\n",get_int_capsula_faturacao(capsula,0)+get_int_capsula_faturacao(capsula,1));
					printf("     | TOTAL FATURAÇÃO:  %.2f\n", get_double_capsula_faturacao(capsula,0)+get_double_capsula_faturacao(capsula,1));
					printf("     | TOTAL VENDAS:     %d\n",get_int_capsula_faturacao(capsula,2)+get_int_capsula_faturacao(capsula,3));
					printf("     |-----------------------------------------------------------\n");
					printf("     |                                                          \n");
					printf("     |                  Prima Enter para continuar                  \n");
					printf("     |                  --------------------------                  \n");
					printf("     \\__________________________________________________________/\n");
					printf("\n");
					getchar();
					printf("\nA voltar ao Menu Principal..\n");

					libertar_capsula_faturacao(capsula);

					break;
				}

				printf("\nERRO: Opção inválida. \n");
				break;
			}

			break;

		case 4:
			while(1){
				ajuda(14);

				if(scanf("%s",item1)<=0) {
					getchar();
					printf("\nERRO: Opção inválida.\n");
					continue;
				}
				getchar();

				if (strcmp(item1,"*")!=0 && !(atoi(item1)>=1&&atoi(item1)<=N_FILIAIS)){
					printf("\nERRO: Opção inválida.\nPor favor escolha uma filial válida.\nOu então escreva'*' para obter dados globais.\n");
					continue;
				}
			
				tinicial = clock(); /*Mede tempo no início*/
				if(strcmp(item1,"*")==0) 
					a = nunca_comprados(f, NULL);
				else {
					item2 = atoi(item1);
					a = nunca_comprados(f, &item2);
				}
				tfinal = clock(); /*Mede tempo no fim*/
				tempo = (float) tfinal - tinicial;
				printf("     Resultado obtido em: %f\n",tempo/CLOCKS_PER_SEC);
				apresenta(a,FATURACAO);
				elimina_apresentacao_faturacao(a);
				a = NULL;
				break;

			}
			break;

		case 5:
			while(1){

				ajuda(17);
				if(scanf("%s",opcao)<=0) {
					getchar();
					printf("\nERRO: Opção inválida.\n");
					continue;
				}
				getchar();
				break;
			}
			
			tinicial = clock(); /*Mede tempo no início*/
			capsula = dados_cliente(g,opcao);
			tfinal = clock(); /*Mede tempo no fim*/
			tempo = (float) tfinal - tinicial;					
			printf("     Resultado obtido em: %f\n",tempo/CLOCKS_PER_SEC);	
				
			if (!capsula){
				printf("\n     O cliente indicado não está registado.\n");
				printf("\nA voltar ao Menu Principal..\n");
				break;
			}
			printf("\n");
			printf("      ___________________CLIENTE %s__________________________\n",opcao);
			printf("     /                                                          \\\n");
			for (filial=0;filial<3;filial++){
				printf("     |-----------------FILIAL %d - Quantidade por mês------------\n",filial+1);		
				for (t=0,m=0;m<12;m++,i++){
					t+=get_int_capsula_faturacao(capsula,i);
					printf("     | Mês #%d - %d\n",m+1, get_int_capsula_faturacao(capsula,i));
				}
				printf("     | TOTAL - %d\n",t);
			}	
			printf("     |-----------------------------------------------------------\n");
			printf("     |                                                          \n");
			printf("     |                  Prima Enter para continuar                  \n");
			printf("     |                  --------------------------                  \n");
			printf("     \\__________________________________________________________/\n");
			printf("\n");
			getchar();
			printf("\nA voltar ao Menu Principal..\n");

			libertar_capsula_gestao(capsula);
			break;

		case 6:
			while(1){
				ajuda(15);
				if(scanf("%d",&item2)<=0) {
					getchar();
					printf("\nERRO: Opção inválida.\nPor favor escreva um número entre 1 e 12 para o mês.\n");
					continue;
				}
				getchar();			
	
				if (!(item2>=1&&item2<=12)) {
					printf("\nERRO: Opção inválida.\nPor favor escreva um número entre 1 e 12 para o mês.\n");
					continue;
				}
	
				ajuda(16);
				if(scanf("%d",&item3)<=0) {
					getchar();
					printf("\nERRO: Opção inválida.\nPor favor escreva um número entre 1 e 12 para o mês.\n");
					continue;
				}
				getchar();

				if (!(item3>=1&&item3<=12)) {
					printf("\nERRO: Opção inválida.\nPor favor escreva um número entre 1 e 12 para o mês.\n");
					continue;
				}
				break;
			}
			tinicial = clock(); /*Mede tempo no início*/
			capsula  =  dados_globais_intervalo(f, item2, item3);
			tfinal   = clock(); /*Mede tempo no fim*/
			tempo    = (float) tfinal - tinicial;
			printf("     Resultado obtido em: %f\n",tempo/CLOCKS_PER_SEC);
			printf("\n");
			printf("      ___________________Dados Globais__________________________\n");
			printf("     /                                                          \\\n");
			printf("     | Dados entre mês %d e mês %d\n", item2, item3);
			printf("     |-----------------------------------------------------------\n");
			printf("     | Total global de número de vendas:     %d\n",get_int_capsula_faturacao(capsula,1));
			printf("     |-----------------------------------------------------------\n");
   			printf("     | Total global de quantidade vendida:   %d\n", get_int_capsula_faturacao(capsula,0));
			printf("     |-----------------------------------------------------------\n");
			printf("     | Total global de lucro:                %.2f\n", get_double_capsula_faturacao(capsula,0));
			printf("     |-----------------------------------------------------------\n");
			printf("     |                                                          \n");
			printf("     |                  Prima Enter para continuar                  \n");
			printf("     |                  --------------------------                  \n");
			printf("     \\__________________________________________________________/\n");
			printf("\n");
			getchar();
			printf("\nA voltar ao Menu Principal..\n");

			libertar_capsula_faturacao(capsula);

			break;

		case 7:

			tinicial = clock(); /*Mede tempo no início*/
			a        = compradores_todas_filiais(g);
			tfinal   = clock(); /*Mede tempo no fim*/
			tempo    = (float) tfinal - tinicial;					
			printf("     Resultado obtido em: %f\n",tempo/CLOCKS_PER_SEC);

			if (!a) {
				printf("     Nenhum cliente comprou em todas as filiais.\n");	
				printf("\nA voltar ao Menu Principal..\n");				
			}			
			else {
				apresenta(a,GESTAO);
				elimina_apresentacao_gestao(a);
				a = NULL;
			}

			break;

		case 8:

			while(1){
				ajuda(23);			
				if(scanf("%s",opcao)<=0) {
					getchar();
					printf("\nERRO: Opção inválida.\n");
					continue;
				}
				getchar();
				break;			
			}

			tinicial = clock(); /*Mede tempo no início*/
			a = clientes_produto(g, opcao);
			tfinal = clock(); /*Mede tempo no fim*/
			tempo = (float) tfinal - tinicial;					
			printf("     Resultado obtido em: %f\n",tempo/CLOCKS_PER_SEC);					
			if(!a) {
				printf("     O produto %s não foi comprado por nenhum cliente.\n",opcao);
				printf("\nA voltar ao menu principal..");
				break;
			}			
			apresenta(a,GESTAO);
			elimina_apresentacao_catalogo(a);
			a = NULL;

			break;

		case 9:
			while(1){

				ajuda(21);
				if(scanf("%s",opcao)<=0) {
					getchar();
					printf("\nERRO: Opção inválida.\n");
					continue;
				}
				getchar();
				break;
			}

			while(1){
				ajuda(22);			
				if(scanf("%d",&item2)<=0) {
					getchar();
					printf("\nERRO: Opção inválida.\n");
					continue;
				}
				getchar();

				if(item2<1||item2>12){
					printf("ERRO: Por favor escolha um valor para o mês que esteja entre 1 e 12.\n");
					continue;
				}

				break;			
			}

			
			tinicial = clock(); /*Mede tempo no início*/
			a = top_mes_descendente(g, opcao, item2);
			tfinal = clock(); /*Mede tempo no fim*/
			tempo = (float) tfinal - tinicial;					
			printf("     Resultado obtido em: %f\n",tempo/CLOCKS_PER_SEC);	
				
			if (!a){
				printf("\n     O cliente indicado não está registado.\n");
				printf("\nA voltar ao Menu Principal..\n");
			}
			else {
				apresenta(a,GESTAO);
				elimina_apresentacao_gestao(a);
				a = NULL;
			}			

			break;

		case 10:

			while(1){
				ajuda(20);			
				if(scanf("%d",&item2)<=0) {
					getchar();
					printf("\nERRO: Opção inválida.\n");
					continue;
				}
				getchar();

				if(item2<=0 || item2>num_elementos(c2)){
					printf("ERRO: Por favor escolha um valor para o top que seja maior que 0\n");
					printf("      e menor que o número de produtos registado (%d)",num_elementos(c2));
					continue;
				}

				break;			
			}

			tinicial = clock(); /*Mede tempo no início*/
			a        = top_produtos(g, item2);
			tfinal   = clock(); /*Mede tempo no fim*/
			tempo    = (float) tfinal - tinicial;					
			printf("     Resultado obtido em: %f\n",tempo/CLOCKS_PER_SEC);

			if (a==NULL) printf("ERRO\n");

			else { 
				apresenta(a,GESTAO);
				elimina_apresentacao_gestao(a);
				a = NULL;
			}

			break;

		case 11:

			while(1){
				ajuda(18);			
				if(scanf("%s",opcao)<=0) {
					getchar();
					printf("\nERRO: Opção inválida.\n");
					continue;
				}
				getchar();
				break;			
			}

			while(1){
				ajuda(19);			
				if(scanf("%d",&item2)<=0) {
					getchar();
					printf("\nERRO: Opção inválida.\n");
					continue;
				}
				getchar();

				if(item2<=0){
					printf("ERRO: Por favor escolha um valor para o top que seja maior que 0\n");
					continue;
				}

				break;			
			}

			tinicial = clock(); /*Mede tempo no início*/
			a = top_cliente(g, opcao, item2);
			tfinal = clock(); /*Mede tempo no fim*/
			tempo = (float) tfinal - tinicial;					
			printf("     Resultado obtido em: %f\n",tempo/CLOCKS_PER_SEC);					
			if(!a) {
				printf("     O cliente %s não realizou nenhuma compra.\n",opcao);
				printf("\nA voltar ao menu principal..");
				break;
			}			
			apresenta(a,GESTAO);
			elimina_apresentacao_catalogo(a);
			a = NULL;


			break;

		case 12:
			tinicial = clock(); /*Mede tempo no início*/
			item2 = get_num_nao_comprados_global(f);
			item3 = num_clientes_gestao(g);
			t     = num_elementos(c2);
			m     = num_elementos(c1);
			tfinal = clock(); /*Mede tempo no fim*/
			tempo = (float) tfinal - tinicial;					
			printf("     Resultado obtido em: %f\n",tempo/CLOCKS_PER_SEC);	
			printf("      ___________________Dados Globais__________________________\n");
			printf("     /                                                          \\\n");
			printf("     | Produtos nunca comprados e Clientes não compradores\n");
			printf("     |-----------------------------------------------------------\n");
			printf("     | Total de Produtos Nunca comprados:  %d\n",   item2);
   			printf("     | Total de Clientes não compradores:  %d\n", m-item3);
			printf("     |-----------------------------------------------------------\n");
			printf("     | Total de Produtos: %d\n", t);
			printf("     | Total de Clientes: %d\n", m);
			printf("     |-----------------------------------------------------------\n");
			printf("     |                                                          \n");
			printf("     |                  Prima Enter para continuar                  \n");
			printf("     |                  --------------------------                  \n");
			printf("     \\__________________________________________________________/\n");
			printf("\n");
			getchar();
			printf("\nA voltar ao Menu Principal..\n");
			break;


	}
}


void menu(Cat c1, Cat c2, Faturacao f, Gestao g){
	char opcao[BUFFER_GENERICO];
		

	while(1){

		ajuda(1);

		if(scanf("%s",opcao)<=0) {
			getchar();
			printf("\nERRO: Opção inválida, consulte as instruções escrevendo 'h'.\n");
			continue;
		}
		getchar();

		switch(tolower(opcao[0])){

			case 'h' :
				ajuda(5);
				break;

			case 's' :
				printf("\n     A eliminar Catálogo de Clientes..\n");
				libertar_memoria_catalogo(c1);
				printf("\n     A eliminar Catálogo de Produtos..\n");
				libertar_memoria_catalogo(c2);				
				printf("\n     A eliminar Módulo Faturacao de Produtos..\n");
				libertar_memoria_faturacao(f);	
				printf("\n     A eliminar Módulo Gestão de Clientes..\n");
				libertar_memoria_gestao(g);					
				ajuda(8);
				return;

			case 'r' :
				printf("\n     A eliminar Catálogo de Clientes..\n");
				libertar_memoria_catalogo(c1);
				printf("\n     A eliminar Catálogo de Produtos..\n");
				libertar_memoria_catalogo(c2);
				printf("\n     A eliminar Módulo Faturacao de Produtos..\n");
				libertar_memoria_faturacao(f);	
				printf("\n     A eliminar Módulo Gestão de Clientes..\n");
				libertar_memoria_gestao(g);
			
				c1 = init_catalogo ();
				c2 = init_catalogo ();
				f  = init_faturacao();
				g  = init_gestao   ();
				
				ler_ficheiros(c1,c2,f,g);
				break;	

			case 'l' :
				ajuda(7);
				break;

			case 't' :
				ajuda(0);
				break;

			case 'a' :
				ajuda(6);
				break;

			case 'q':
				switch(atoi(opcao+1)){
				

					case 2  : 
						queries(2,NULL,c2,NULL,NULL);
						break;

					case 3  :
						queries(3,NULL,NULL,f,NULL);
						break;

					case 4  :
						queries(4,NULL,NULL,f,NULL);
						break;

					case 5  :
						queries(5,NULL,NULL,NULL,g);
						break;

					case 6  :
						queries(6,NULL,NULL,f,NULL);
						break;

					case 7  :
						queries(7,NULL,NULL,NULL,g);
						break;

					case 8  :
						queries(8,NULL,NULL,NULL,g);
						break;

					case 9  :				
						queries(9,NULL,NULL,NULL,g);
						break;

					case 10 :
						queries(10,NULL,c2,NULL,g);
						break;

					case 11 :
						queries(11,NULL,NULL,NULL,g);
						break;

					case 12 :
						queries(12,c1,c2,f,g);
						break;

					default : 
						printf("\nERRO: Selecionou uma query/funcionalidade que não existe.\nConsulte a lista de queries/funcionalidades escrevendo 'l'.\n");
						break;
				}
				break;

			default : 
				printf("\nERRO: Opção inválida, consulte as instruções escrevendo 'h'.\n");
				break;
		}

	}
}



int main () {
	Cat       c1 = NULL;
	Cat       c2 = NULL;
	Faturacao f  = NULL;
	Gestao    g  = NULL;
	ajuda(0);

	c1 = init_catalogo  ();
	c2 = init_catalogo  ();
	f  = init_faturacao ();
	g  = init_gestao    ();
	
	/*Carregamento de ficheiros*/
	ler_ficheiros(c1, c2, f, g);

	/*Menu principal*/
	menu(c1, c2, f,g);


	return 0;
}























