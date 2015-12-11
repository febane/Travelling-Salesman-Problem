/**
 * Caixeiro Viajante
 * convexHull.c
 * Implementacao do Convex Hull
 * Ver documentacao para mais informacoes
 * 
 * @author Fernando Barbosa Neto
 * @author Jeferson de Oliveira Batista
 * 
 */


#include "convexHull.h"
#define ESQ +1
#define NEUTRO 0
#define DIR -1

void pilhaInicTour(Tour* tour, Pilha *pilha) {
	Ponto *p;
	while(!vaziaPilha(pilha)) {
		p = top1(pilha);
		inserirInic(tour, p);
		pop(pilha);
	}
}

void pilhaFimTour(Tour *tour, Pilha *pilha) {
	Ponto *p;
	pop(pilha);
	while(top2(pilha) != NULL) {
		p = top1(pilha);
		inserirFim(tour, p);
		pop(pilha);
	}
	pop(pilha);
}

Tour *fazerEnvoltorio(Ponto **pontos, int n) {
	int i, c;
	ordenarPontos(pontos, 0, n-1);
		
	Tour *tour = criarTour();
	Pilha *pilha = criarPilha();
	
	// Parte de cima do envoltório
	push(pilha, pontos[0]);
	push(pilha, pontos[1]);
	
	for(i = 2; i < n; i++) {
		while(top2(pilha) != NULL) {
			c = curva(top2(pilha), top1(pilha), pontos[i]);
			if(c == ESQ) {
				pop(pilha);
			}
			else
				break;
		}
		push(pilha, pontos[i]);
	}
	pilhaInicTour(tour, pilha);
	
	// Parte de baixo do envoltório
	push(pilha, pontos[0]);
	push(pilha, pontos[1]);
	
	for(i = 2; i < n; i++) {
		while(top2(pilha) != NULL) {
			c = curva(top2(pilha), top1(pilha), pontos[i]);
			if(c == DIR) {
				pop(pilha);
			}
			else
				break;
		}
		push(pilha, pontos[i]);
	}
	pilhaFimTour(tour, pilha);

	liberarPilha(pilha);
	checkPoint(tour);
	return tour;
}

void finalizarTour(Tour *tour, Ponto **pontos, int n) {
	Ponto *p;
	int i, pos;
	for(i = 0; i < n; i++) {
		p = pontos[i];
		pos = findPos(p, tour);
		if(pos != -1) {
			inserirPos(tour, p, pos);
			p->check = 1;
		}
	}
}

int findPos(Ponto *p, Tour *tour) {
	if(p->check)
		return -1;
	
	int i, pos;
	float custoAnt, custoProx, distAux;	
	Ponto *t; // ponto que pertence ao tour
	
	Lista *atual = tour->prim;
	int posAtual = 1;
	Lista *maisProx = atual;
	int posMaisProx = 0;
	Lista *anterior;
	Lista *posterior;
	
	t = atual->p;
	float distancia;
	float menorDist = dist(p, t);
	
	atual = atual->prox;
	while(atual != NULL) {
		t = atual->p;
		distancia = dist(p, t);
		if(distancia < menorDist) {
			menorDist = distancia;
			maisProx = atual;
			posMaisProx = posAtual;
		}
		atual = atual->prox;
		posAtual++;
	}
	
	if(maisProx == tour->prim) {
		anterior = tour->ult;
		posterior = maisProx->prox;
	}
	else if(maisProx == tour->ult) {
		atual = tour->prim;
		for(i = 0; i < posMaisProx-1; i++) {
			atual = atual->prox;
		}
		anterior = atual;
		posterior = tour->prim;
	}
	else {
		atual = tour->prim;
		for(i = 0; i < posMaisProx-1; i++) {
			atual = atual->prox;
		}
		anterior = atual;
		posterior = maisProx->prox;
	}
	
	distAux = dist(p, maisProx->p);
	custoAnt = dist(p, anterior->p) + distAux - dist(maisProx->p, anterior->p);
	custoProx = dist(p, posterior->p) + distAux - dist(maisProx->p, posterior->p);
	
	if(custoProx < custoAnt)
		pos = posMaisProx;
	else {
		if(posMaisProx == 0)
			pos = tour->tam-1;
		else
			pos = (posMaisProx-1);
	}
	return pos;
}

int curva(Ponto *p1, Ponto *p2, Ponto *p3) {
	float x1, y1, x2, y2, produtoVet;
	x1 = p2->x - p1->x;
	y1 = p2->y - p1->y;
	x2 = p3->x - p2->x;
	y2 = p3->y - p2->y;
	produtoVet = x1*y2 - x2*y1;
	
	if(produtoVet > 0)
		return ESQ;
	if(produtoVet < 0)
		return DIR;
	else
		return NEUTRO;
}

float dist(Ponto *p1, Ponto *p2) {
	float dx, dy, dist;
	dx = p1->x - p2->x;
	dy = p1->y - p2->y;
	
	dist = sqrt(dx*dx + dy*dy);
	return dist;
}

// Só é usada em tours com mais de dois pontos
float custo(Tour *tour) {
	float c = 0.0;
	int n = tour->tam;
	int i;
	Lista *aux = tour->prim;
	for(i = 0; i < n-1; i++) {
		c += dist(aux->p, aux->prox->p);
		aux = aux->prox;
	}
	c += dist(tour->ult->p, tour->prim->p);
	return c;
}


