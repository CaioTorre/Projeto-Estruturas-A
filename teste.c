#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"

//Funcao float** criarMatriz(linhas, colunas);                    						> Pronta
//Funcao void destruitMatriz(referencia, linhas);               						> Pronta 
//Funcao void imprimirMatriz(ponteiro, linhas, colunas);   							> Pronta	
//Funcao void atribuirValor(ponteiro, valor, linha, coluna, linhas, colunas)					> Pronta
//Funcao void transporMatriz(ponteiro, ponteiro, linhas, colunas);

int main()
{
	float **p;
	int i, j, count = 0;
	int linhas = 3, colunas = 3;
	
	p = criarMatriz(linhas, colunas);

	for(i = 0; i < linhas; i++){
		for(j = 0; j < colunas; j++){
			p[i][j] = count;
			count += 1;
		}
	}
	
		
	imprimirMatriz(p, linhas, colunas);
	printf("\n\n\n");
	//destruirMatriz(p, linhas);
	
	atribuirValor(p, 9, 0, 2, linhas, colunas);
	imprimirMatriz(p, linhas, colunas);


	
	
	
	
	
}

