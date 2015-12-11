#include <math.h>
#include "pilha.h"
#include "tour.h"

void pilhaInicTour(Tour* tour, Pilha *pilha);
void pilhaFimTour(Tour *tour, Pilha *pilha);
Tour* fazerEnvoltorio(Ponto **pontos, int n);
void finalizarTour(Tour *tour, Ponto **pontos, int n);
int findPos(Ponto *p, Tour *tour);
int curva(Ponto *p1, Ponto *p2, Ponto *p3);
float dist(Ponto *p1, Ponto *p2);
float custo(Tour *tour);


