/**
 * Caixeiro Viajante
 * pilha.c
 * Implementacoes da TAD Pilha
 * Ver documentacao para mais informacoes
 * 
 * @author Fernando Barbosa Neto
 * @author Jeferson de Oliveira Batista
 * 
 */


#include "pilha.h"

Pilha *criarPilha() {
	Pilha *novo = (Pilha*) malloc(sizeof(Pilha));
	novo->prim = novo->seg = NULL;
	return novo;
}

int vaziaPilha(Pilha *pilha) {
	return (pilha->prim == NULL);
}

void push(Pilha *pilha, Ponto *p) {
	No *novo = (No*) malloc(sizeof(No));
	novo->p = p;
	novo->next = pilha->prim;
	pilha->seg = pilha->prim;
	pilha->prim = novo;
}

void pop(Pilha *pilha) {
	if(vaziaPilha(pilha)) {
		printf("A pilha ja esta vazia!\n\n");
		return;
	}
	else {
		free(pilha->prim);
		pilha->prim = pilha->seg;
		if(pilha->seg != NULL)
			pilha->seg = pilha->seg->next;
	}
}

Ponto *top1(Pilha *pilha) {
	if(pilha->prim == NULL)
		return NULL;
	else
		return pilha->prim->p;
}

Ponto *top2(Pilha *pilha) {
	if(pilha->seg == NULL)
		return NULL;
	else
		return pilha->seg->p;
}

void printPilha(Pilha *pilha) {
	No *atual;
	Ponto *p;
	if(vaziaPilha(pilha)) {
		printf("A pilha esta vazia!\n\n");
		return;
	}
	else {
		atual = pilha->prim;
		while(atual != NULL) {
			p = atual->p;
			printf("%d - (%.0f, %.0f)\n", p->id, p->x, p->y);
			atual = atual->next;
		}
		printf("\n");
	}
}

void liberarPilha(Pilha *pilha) {
	while(!vaziaPilha(pilha))
		pop(pilha);
	free(pilha);
}


