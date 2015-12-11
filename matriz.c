/**
 * Caixeiro Viajante
 * matriz.c
 * Leitura e implementacao matricial
 * Ver documentacao para mais informacoes
 * 
 * @author Fernando Barbosa Neto
 * @author Jeferson de Oliveira Batista
 * 
 */


#include "matriz.h"

float **criarMatriz(int tam) {
	int i;
	float **matriz = (float**) calloc(tam, sizeof(float*));
	for(i = 0; i < tam; i++) {
		matriz[i] = (float*) calloc(tam, sizeof(float));
	}
	return matriz;
}

void lerMatriz(int tam, float **matriz) {
	
	int i, j;
	
	for(i = 0; i < tam; i++) {
		for(j = 0; j < tam; j++) {
			scanf("%f", &matriz[i][j]);
		}
	}
}

void liberarMatriz(int tam, float **matriz) {
	int i;
	for(i = 0; i < tam; i++) {
		free(matriz[i]);
	}
	free(matriz);
}


