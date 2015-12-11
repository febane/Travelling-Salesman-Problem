/**
 * Caixeiro Viajante
 * atsp.c
 * Implementacoes do vetor que contera
 * ponteiros para os pontos do Convex Hull
 * Ver documentacao para mais informacoes
 * 
 * @author Fernando Barbosa Neto
 * @author Jeferson de Oliveira Batista
 * 
 */

#include "vetorDePontos.h"

Ponto **criarVetorDePontos(int n) {
	int i;
	
	Ponto **vetor = (Ponto**) calloc(n, sizeof(Ponto*));
	for(i = 0; i < n; i++) {
		vetor[i] = (Ponto*) malloc(sizeof(Ponto));
	}
	return vetor;
}

void lerPontos(Ponto **vetor, int n) {
	int i;
	
	for(i = 0; i < n; i++) {
		vetor[i]->id = i;
		vetor[i]->check = 0;
		scanf("%f %f", &vetor[i]->x, &vetor[i]->y);
	}
}

// Retorna 1 se o primeiro Ponto é "maior", 0 c.c.
int cmpPontos(Ponto *p1, Ponto *p2) {
	if(p1->x > p2->x)
		return 1;
	if(p1->x < p2->x)
		return 0;
	if(p1->y > p2->y)
		return 1;
	else
		return 0;
}

void ordenarPontos(Ponto **vetor, int ini, int fim) {
	int i, j;
	Ponto *aux, *pivo;
	
	i = ini;
	j = fim;
	pivo = vetor[(ini + fim)/2];
	
	while(i <= j) {
	
		while(cmpPontos(pivo, vetor[i]) && i < fim)
			i++;
			
		while(cmpPontos(vetor[j], pivo) && j > ini)
			j--;
			
		if(i <= j) {
		
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i++;
			j--;
			
		}
		
	}
	
	if(j > ini) {
		ordenarPontos(vetor, ini, j);
	}
	
	if(i < fim) {
		ordenarPontos(vetor,  i, fim);
	}
}

void liberarPontos(Ponto **vetor, int n) {
	int i;
	for(i = 0; i < n; i++) {
		free(vetor[i]);
	}
	free(vetor);
}


