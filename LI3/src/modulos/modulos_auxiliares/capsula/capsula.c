#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "capsula.h"


struct capsula{
	int tipo; /*0 se usar o int, 1 se usar o double, 2 se usar ambos*/

	int     q1;
	int *item1;
	
	int        q2;
	double *item2;
};



Capsula init_capsula(int item1_, int item2_){
	Capsula c = (Capsula) malloc (sizeof (struct capsula));

	c->tipo  = -1;

	if (item1_ > 0)
		c->item1 = (int*) malloc((sizeof (int))*item1_);
	else c->item1 = NULL;
	
	if (item2_ > 0)
		c->item2 = (double*) malloc((sizeof (double))*item2_);
	else c->item2 = NULL;

	c->q1 = 0;
	c->q2 = 0;

	return c;
}


Capsula insere_capsula(Capsula c, int t, int *item1, double *item2){
	c->tipo=t;	
	
	if (t==INT){	
		c->item1[c->q1] = *item1;
		c->q1++;
		return c;
	}

	if(t==DOUBLE){
		c->item2[c->q2] = *item2;
		c->q2++;
		return c;
	}

	if(t==AMBOS){
		c->item1[c->q1] = *item1;
		c->item2[c->q2] = *item2;
		c->q1++;
		c->q2++;
		return c;
	}

	return c;
}


void libertar_capsula(Capsula c){
	if (c->item1!=NULL) free(c->item1);
	if (c->item2!=NULL) free(c->item2);
	
	free(c);
}


int tipo_capsula(Capsula c){
	return c->tipo;
}


int int_capsula(Capsula c, int indice){
	if (indice>c->q1||!(c->item1)) return -1;
	return (c->item1)[indice];
}


double double_capsula(Capsula c, int indice){
	if (indice>c->q2||!(c->item2)) return -1;
	return (c->item2)[indice];
}

int q1_capsula(Capsula c){
	return c->q1;
}

int q2_capsula(Capsula c){
	return c->q2;
}



