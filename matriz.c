#include <stdlib.h>
#include <stdio.h>

float **criarMatriz(int linhas, int colunas)
{
	float **Matriz;

	Matriz = (float **)malloc(linhas * sizeof(float));
	for(int i=0; i < linhas; i++)
	{
		Matriz[i] = (float *)malloc(colunas * sizeof(float));
	}

	return Matriz;
}

int destruirMatriz(float** matriz)
{
	if(matriz == NULL)
		return 1;
	else
	{
		free(matriz);
		*matriz = NULL;
		return 2;
	}
}

void imprimirMatriz(float** matriz)
{	
	if(matriz == NULL)
		printf("Erro, matriz vazia!\n");
	else
	{	
	}		
}




















