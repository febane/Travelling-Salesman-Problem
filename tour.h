#include <stdlib.h>
#include "vetorDePontos.h"

typedef struct lista {	
	Ponto *p;
	struct lista *prox;
} Lista;

typedef struct tour {
	Lista* prim;
	Lista* ult;
	int tam;
} Tour;

Tour *criarTour();
void inserirInic(Tour *tour, Ponto *p);
void inserirFim(Tour *tour, Ponto *p);
void inserirPos(Tour *tour, Ponto *p, int pos);
void printTour(Tour *tour);
void checkPoint(Tour *tour);
int liberarPrim(Tour *tour);
void liberarTour(Tour *tour);


