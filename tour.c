/**
 * Caixeiro Viajante
 * tour.c
 * Tratamento dos tours
 * Ver documentacao para mais informacoes
 * 
 * @author Fernando Barbosa Neto
 * @author Jeferson de Oliveira Batista
 * 
 */


#include "tour.h"

Tour *criarTour() {
	Tour *novo = (Tour*) malloc(sizeof(Tour));
	novo->prim = novo->ult = NULL;
	novo->tam = 0;
	return novo;
}

void inserirInic(Tour *tour, Ponto *p) {
	Lista *novo = (Lista*) malloc(sizeof(Lista));
	novo->p = p;
	novo->prox = tour->prim;
	tour->prim = novo;
	if(tour->ult == NULL) {
		tour->ult = novo;
	}
	tour->tam += 1;
}

void inserirFim(Tour *tour, Ponto *p) {
	Lista *novo = (Lista*) malloc(sizeof(Lista));
	novo->p = p;
	novo->prox = NULL;
	if(tour->ult == NULL) {
		tour->prim = tour->ult = novo;
	}
	else {
		tour->ult->prox = novo;
		tour->ult = novo;
	}
	tour->tam += 1;
}

// É usado apenas em tours com tam > 2
void inserirPos(Tour *tour, Ponto *p, int pos) {
	Lista *novo;
	Lista *l;
	int i;
	
	if(pos == tour->tam-1) {
		inserirInic(tour, p);
	}
	else {
		l = tour->prim;
		for(i = 0; i < pos; i++) {
			l = l->prox;
		}
		
		novo = (Lista*) malloc(sizeof(Lista));
		novo->p = p;
		novo->prox = l->prox;
		
		l->prox = novo;
		tour->tam += 1;
	}
}

void printTour(Tour *tour) {
	Ponto *p;
	Lista *atual = tour->prim;
	
	while(atual != NULL) {
		p = atual->p;
		printf("%d\n\n", p->id);
		atual = atual->prox;
	}
}

void checkPoint(Tour *tour) {	
	Ponto *p;
	Lista *atual = tour->prim;
	
	while(atual != NULL) {
		p = atual->p;
		p->check = 1;
		atual = atual->prox;
	}
}

int liberarPrim(Tour *tour) {
	Lista *aux;
	if(tour->tam == 0) {
		return 0;
	}
	if(tour->tam == 1) {
		free(tour->prim);
		tour->prim = tour->ult = NULL;
		tour->tam -= 1;
		return 1;
	}
	else {
		aux = tour->prim->prox;
		free(tour->prim);
		tour->prim = aux;
		tour->tam -= 1;
		return 1;
	}
}

void liberarTour(Tour *tour) {
	while(liberarPrim(tour));
	free(tour);
}


