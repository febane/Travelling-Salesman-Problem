/**
 * Caixeiro Viajante
 * atsp.c
 * Implementacoes para o ATSP
 * Ver documentacao para mais informacoes
 * 
 * @author Fernando Barbosa Neto
 * @author Jeferson de Oliveira Batista
 * 
 */


#include "atsp.h"
#include "PermGen.h"
#define INF 999999


void exato(int tam, float **matriz) {
	
	int i, ant;
	int *vetor;
	int caminho[tam+1];
	int melhorCaminho[tam+1];
	float melhorDist = INF, dist;
	
	// Começando e parando na cidade 0
	caminho[0] = caminho[tam] = 0;
	
	PermGen *pg = criarPermGen(tam-1);
	
	while(step(pg)) {
		
		vetor = getPerm(pg);
		
		for(i = 0; i < tam-1; i++)
			caminho[i+1] = vetor[i]+1;
		
		ant=0;
		dist=0;
		
		for(i = 1; i < tam+1; i++){
			
			dist += matriz[ant][caminho[i]];
			ant = caminho[i];
			
		}
		
		if(dist<melhorDist){
			
			melhorDist = dist;
			
			for(i=0;i<tam+1;i++)
				melhorCaminho[i] = caminho[i];
			
		}
		
	}
	
	for(i=0;i<tam;i++)
		printf("%d\n\n", melhorCaminho[i]);
		
	if(melhorDist>0.0)
		printf("%.0f\n\n", melhorDist);
		
	liberarPerm(pg);
	
}


float nn(int tam, float **matriz, int melhorCaminho[], int print){
	
	int i, j, ant;
	float melhorDist=0, menor;
	int rascunho[tam][tam];
	
	//inicio
	melhorCaminho[0] = 0;
	
	//caminhos intermediarios
	for(i=0;i<tam-1;i++){
		
		ant = melhorCaminho[i];
		
		menor = INF;
		
		for(j=1;j<tam;j++){
			
			if(matriz[ant][j]<menor){
			
				melhorCaminho[i+1] = j;
				menor = matriz[ant][j];
				
			}
			
		}
		
		for(j=1;j<tam;j++)
			matriz[j][melhorCaminho[i+1]] = INF;
		
		//printf("%f ", menor);
		melhorDist += menor;
		
	}
	
	//caminho que retorna ao inicio
	melhorDist += matriz[melhorCaminho[i]][0];
	
	if(print==1){
	
		for(i=0;i<tam;i++)
			printf("%d\n\n", melhorCaminho[i]);
		
		if(melhorDist>0.0)
			printf("%.0f\n\n", melhorDist);
	
	}
	
	return melhorDist;
	
}


void opt(int tam, float **matriz){
	
	int i, j, k, ant;
	float **rascunho = criarMatriz(tam);
	int caminho[tam], melhorCaminho[tam], novoCaminho[tam];
	float melhorDist, tempDist;
	
	for(i=0;i<tam;i++)
		for(j=0;j<tam;j++)
			rascunho[i][j] = matriz[i][j];
			
	//caminho armazena menor caminho por nn
	melhorDist = nn(tam, rascunho, caminho, 0);
	for(i=0;i<tam;i++)
		melhorCaminho[i] = caminho[i];
	
	//troca aresta 0 com as demais
	ant=0;
	for(i=2;i<tam-1;i++){
		
		opt_cria_caminho(tam, caminho, 0, i, novoCaminho);
		tempDist = calcula_distancia(tam, novoCaminho, matriz);
		
		if(tempDist<melhorDist){
			
			melhorDist = tempDist;
			
			for(k=0;k<tam;k++)
				melhorCaminho[k] = novoCaminho[k];
			
		}
		
	}
	
	//troca as arestas 1..tam-3 com as demais
	for(i=1;i<tam-2;i++){
		
		for(j=i+2;j<tam;j++){
		
			opt_cria_caminho(tam, caminho, i, j, novoCaminho);
			tempDist = calcula_distancia(tam, novoCaminho, matriz);
			
			if(tempDist<melhorDist){
				
				melhorDist = tempDist;
				
				for(k=0;k<tam;k++)
					melhorCaminho[k] = novoCaminho[k];
				
			}
			
		}
		
	}
	
	for(i=0;i<tam;i++)
		printf("%d\n\n", melhorCaminho[i]);
	
	if(melhorDist>0.0)
		printf("%.0f\n\n", melhorDist);
		
	liberarMatriz(tam, rascunho);
	
}


void opt_cria_caminho(int tam, int melhorCaminho[], int a, int b, int novoCaminho[]){
	
	int i, j=0;
	
	for(i=0;i<=a;i++){
		
		novoCaminho[j] = melhorCaminho[i];
		j++;
		
	}
	
	for(i=b;i>a;i--){
		
		novoCaminho[j] = melhorCaminho[i];
		j++;
		
	}
	
	for(i=b+1;i<tam;i++){
		
		novoCaminho[j] = melhorCaminho[i];
		j++;
		
	}
	
}


float calcula_distancia(int tam, int caminho[], float **matriz){
	
	float dist=0.0;
	int i, ant=0;
	
	for(i=1;i<tam;i++){
		
		dist += matriz[ant][caminho[i]];
		ant = caminho[i];
		
	}
	
	dist += matriz[ant][0];
	
	return dist;
	
}


