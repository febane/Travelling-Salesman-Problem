#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void exato(int tam, float **matriz);
float nn(int tam, float **matriz, int melhorCaminho[], int print);
void opt(int tam, float **matriz);
void opt_cria_caminho(int tam, int melhorCaminho[], int i, int k, int novoCaminho[]);
float calcula_distancia(int tam, int caminho[tam], float **matriz);
