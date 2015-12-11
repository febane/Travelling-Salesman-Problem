/**
 * Caixeiro Viajante
 * atsp.c
 * Arquivo Principal para uso dos metodos
 * e heurísticas para o Caixeiro Viajante
 * Ver documentacao para mais informacoes
 * 
 * @author Fernando Barbosa Neto
 * @author Jeferson de Oliveira Batista
 * 
 */


#include "PermGen.h"
#include "atsp.h"
#include "convexHull.h"

int main(int argc, char *argv[]) {
	
	int tam = atoi(argv[1]);
	int i;
	
	if(argc < 3) {
		printf("Usage: ./trab <dimension> <algorithm>\n\n");
		return 1;
	}
	
	if(tam > 2) {
	    
	    if(strcmp(argv[2], "hull")) {
	    	
	    	float **matriz = criarMatriz(tam);
	    	lerMatriz(tam, matriz);
	    	
		    if(!strcmp(argv[2], "exato")) {
		    	if(tam < 13) {
			    	exato(tam, matriz);
			    }
	    	}
		    else if(!strcmp(argv[2], "nn")) {
		        int melhorCaminho[tam];
	    		nn(tam, matriz, melhorCaminho, 1);
	    	}
	    	else if(!strcmp(argv[2],"opt")) {
	    		opt(tam, matriz);
		    }
		    else {
		    	printf("O algoritmo [%s] nao foi implementado!\n\n", argv[2]);
		    	return 3;
		    }
		    
		    liberarMatriz(tam, matriz);
		    
	    }
    	
    	else {
    		
    		Ponto **pontos = criarVetorDePontos(tam);
	        lerPontos(pontos, tam);
	
	        Tour *tour = fazerEnvoltorio(pontos, tam);
	        finalizarTour(tour, pontos, tam);
	        
	        printTour(tour);
	        printf("%.2f\n\n", custo(tour));
        	
        	liberarTour(tour);
	        liberarPontos(pontos, tam);
		    
	    }
	    
	}
	else {
		printf("Ha menos que 3 pontos no exemplo dado!\n\n");
		return 2;
	}
	
	printf("*\n\n");
	
	return 0;
}


