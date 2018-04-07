#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"

//Funcao criarMatriz(linhas, colunas); > Pronta
//Funcao destruitMatriz(*matriz);      > Pronta retorna 1 caso matriz nula retorna 2 caso desalocada com sucesso
//Funcao void imprimirMatriz(float**); > Fazendo

int main()
{
	float **p;
	int i, j, count = 5;
	
	p = criarMatriz(3, 3);

	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			p[i][j] = count;
			count += 2;
		}
	}
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			printf(" %.f ", p[i][j]);
		}
		printf("\n");
	}
	

	
		
	//imprimirMatriz(p);
	
	destruirMatriz(p);
	
	
	
	
}
