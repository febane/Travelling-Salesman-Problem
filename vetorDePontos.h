// Vetor que conterá ponteiros para os pontos do Convex Hull

#ifndef VETORDEPONTOS_H
#define VETORDEPONTOS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct ponto {
	int id;
	int check;
	float x, y;
} Ponto;

Ponto **criarVetorDePontos(int n);
void lerPontos(Ponto **vetor, int n);
int cmpPontos(Ponto *p1, Ponto *p2);
void ordenarPontos(Ponto **vetor, int ini, int fim);
void liberarPontos(Ponto **vetor, int n);

#endif


