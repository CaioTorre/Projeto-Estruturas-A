#include <stdlib.h>
#include <stdio.h>

float **criarMatriz(int linhas, int colunas, int zera)
{
	float **Matriz;
	
	if(linhas >= 50 || linhas <= 1 || colunas >= 50 || linhas <= 1)
	{
		printf("ERRO\n");
		return (-1);
	}
	else
	{
		if(zera){
			if(!(Matriz = (float **)calloc(linhas,sizeof(float)))) return (-2);
		
			for(int i=0; i < linhas; i++)
			{
				Matriz[i] = (float *)calloc(colunas, sizeof(float));
			}
		}
		else{
			if(!(Matriz = (float **)malloc(linhas * sizeof(float)))) return (-2);
			
			for(int i=0; i < linhas; i++)
			{
				Matriz[i] = (float *)malloc(colunas * sizeof(float));
			}
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
	if(!matriz)
		printf("ERRO\n");
	else
	{
		for(int i = 0; i < linhas; i++)
			free(matriz[i]);
		free(matriz);

		printf("OK\n");
	}
}

void imprimirMatriz(float** matriz, int linhas, int colunas)
{
	if(!matriz)
		printf("ERRO\n");
	else
	{
		for(int i = 0; i < linhas; i++){
			for(int j = 0; j < colunas; j++){
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
	if(!matriz){
		printf("ERRO\n");
		return -1;
	}
	float **aux = criarMatriz(colunas, linhas, 0);
	for(int i = 0; i < linhas; i++){
		for(int j = 0; j < colunas; j++){
			aux[j][i] = matriz[i][j];
			printf("%6.2f", aux[j][i]);
		}
	printf("\n");		
	}
	return aux; 
		
}
float**  somarMatriz(float **mat1, float **mat2, int lin1, int col1, int lin2, int col2){
	if((!mat1 || !mat2) || ((lin1 != lin2) && (col1 != col2))){
		printf("ERRO\n");
		return -1;
	}
	else{
		float **aux = criarMatriz(lin1, col1, 0);
		for(int i=0; i < lin1; i++){
			for(int j=0; j < col1; j++){
				aux[i][j] = mat1[i][j]+mat2[i][j];
				printf("%6.2f", aux[i][j]);
			}
			printf("\n");
		}
		return aux;
	}
}
float**  divideMatriz(float **mat1, float **mat2, int lin1, int col1, int lin2, int col2){
	if((!mat1 || !mat2) || ((lin1 != lin2) && (col1 != col2))){
		printf("ERRO\n");
		return -1;
	}
	else{
		for(int i=0; i<lin2;i++)
			for(int j=0; j<col2;j++)
				if(mat2[i][j] == 0){
					printf("ERRO\n");
					return -2;
				}
		float **aux = criarMatriz(lin1, col1,0);
		for(int i=0; i<lin2;i++){
			for(int j=0; j<col2;j++){
				aux[i][j] = mat1[i][j]/mat2[i][j];
				printf("%6.2f", aux[i][j]);
				}
			printf("\n");
			}
		return aux;
	}
}
float**  ME(float **mat1, float **mat2, int lin1, int col1, int lin2, int col2){
	if((!mat1 || !mat2) || ((lin1 != lin2) && (col1 != col2))){
		printf("ERRO\n");
		return -1;
	}
	else{
		float **aux = criarMatriz(lin1, col1,0);
		for(int i=0; i<lin2;i++){
			for(int j=0; j<col2;j++){
				aux[i][j] = mat1[i][j]*mat2[i][j];
				printf("%6.2f", aux[i][j]);
				}
			printf("\n");
			}
		return aux;
	}
}
float**  MM(float **mat1, float **mat2, int lin1, int col1, int lin2, int col2){
	if((!mat1 || !mat2) || (col1 != lin2)){
		printf("ERRO\n");
		return -1;
	}
	else{
		float **aux = criarMatriz(lin1, col2,1);
		for(int i=0; i<col1;i++){
			for(int t=0; t<col2; t++){
				for(int j=0; j<lin2;j++) aux[i][t]+=mat1[i][j]*mat2[j][i+t];
				printf("%6.2f", aux[i][t]);
			}
		printf("\n");
		}
		return aux;
	}
}
























