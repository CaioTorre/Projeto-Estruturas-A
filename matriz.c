#include <stdlib.h>
#include <stdio.h>

float **criarMatriz(int linhas, int colunas)
{
	float **Matriz;
	
	if(linhas >= 50 || linhas <= 1 || colunas >= 50 || linhas <= 1)
	{
		printf("ERRO\n");
	}
	else
	{
		Matriz = (float **)malloc(linhas * sizeof(float));
		for(int i=0; i < linhas; i++)
		{
			Matriz[i] = (float *)malloc(colunas * sizeof(float));
		}

		if(!Matriz)
		{
			printf("ERRO\n");
			return 0;
		}	
		return Matriz;
	}
}

void destruirMatriz(float** matriz, int linhas)
{
	int i;	

	if(!matriz)
		printf("ERRO\n");
	else
	{
		for(i = 0; i < linhas; i++)
			free(matriz[i]);
		free(matriz);

		printf("OK\n");
	}
}

void imprimirMatriz(float** matriz, int linhas, int colunas)
{		
	int i, j;

	if(!matriz)
		printf("ERRO\n");
	else
	{
		for(i = 0; i < linhas; i++){
			for(j = 0; j < colunas; j++){
				printf("%6.2f", matriz[i][j]);
			}
			printf("\n");		
		}
	}		
}

void atribuirValor(float **matriz, float valor, int linha, int coluna, int linhas, int colunas)
{
	if(!(*matriz) || linha >= linhas || coluna >= colunas || linha < 0 || coluna < 0)
		printf("ERRO\n");
	else
	{
		matriz[linha][coluna] = valor;
	}
}

float** transporMatriz(float **matriz, int linhas, int colunas)
{
	int i, j;
		

	criarmatriz
	
}






















