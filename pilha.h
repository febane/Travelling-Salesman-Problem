#include <stdlib.h>
#include "vetorDePontos.h"

typedef struct no {
	Ponto *p;
	struct no *next;
} No;

typedef struct pilha {
	No *prim;
	No *seg;
} Pilha;

Pilha *criarPilha();
int vaziaPilha(Pilha *pilha);
void push(Pilha *pilha, Ponto *p);
void pop(Pilha *pilha);
Ponto *top1(Pilha *pilha);
Ponto *top2(Pilha *pilha);
void printPilha(Pilha *pilha);
void liberarPilha(Pilha *pilha);


