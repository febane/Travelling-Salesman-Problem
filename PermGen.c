/**
 * Caixeiro Viajante
 * PermGen.c
 * Gerador de permutacoes
 * Ver documentacao para mais informacoes
 * 
 * @author Fernando Barbosa Neto
 * @author Jeferson de Oliveira Batista
 * 
 */


#include "PermGen.h"

PermGen* criarPermGen(int n) {
	int i;
	PermGen* novo = (PermGen*) malloc(sizeof(PermGen));
	novo->dim = n;
	novo->clock = (int*) calloc(n, sizeof(int));
	novo->check = (int*) calloc(n, sizeof(int));
	novo->perm = (int*) calloc(n, sizeof(int));
	for(i = 0; i < n; i++) {
		novo->clock[i] = 1;
		novo->check[i] = 1;
		novo->perm[i] = i;
	}
	return novo;
}

int step(PermGen* pg) {
	int i, j, s, select;
	int n = pg->dim;
	int pos = n-1;
	
	// Resetando a checagem de elementos
	for(i = 0; i < n; i++) {
		pg->check[i] = 1;
	}
	
	// Fazendo o clock andar
	while(pg->clock[pos] == n-pos) {
		pg->clock[pos] = 1;
		pos--;
		
		if(pos == -1) {
			reset(pg);
			return 0;
		}
	}
	
	pg->clock[pos] += 1;
	
	// Gerando a permutação
	for(i = 0; i < n; i++) {
		select = pg->clock[i];
		s = j = 0;
		while(s < select) {
			s += pg->check[j];
			j++;
		}
		pg->perm[i] = j-1;
		pg->check[j-1] = 0;
	}
	return 1;
}

void reset(PermGen* pg) {
	int n = pg->dim;
	int i;
	for(i = 0; i < n-1; i++) {
		pg->clock[i] = 1;
		pg->check[i] = 1;
		pg->perm[i] = i;
	}
}

void printPerm(PermGen* pg) {
	int n = pg->dim;
	int i;
	for(i = 0; i < n; i++) {
		printf("%d ", pg->perm[i]);
	}
	printf("\n");
}

int *getPerm(PermGen* pg) {
	return pg->perm;
}

void liberarPerm(PermGen* pg) {
	free(pg->clock);
	free(pg->check);
	free(pg->perm);
	free(pg);
}


