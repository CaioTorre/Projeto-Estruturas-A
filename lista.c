#include <string.h>
#include "matriz.h"

#define TAMANHO_NOME 20

struct matriz{
char nome [TAMANHO_NOME];
int linhas;
int colunas
float **mat;
matriz *prox;
};

void nova_matriz (char nome[], int linhas, int colunas, matriz **inicio)
{
	matriz *aux;
	aux = (*matriz) malloc (sizeof matriz);
	strcpy (aux->nome, nome);
	aux->linhas = linhas;
	aux->colunas = colunas;
	aux->*mat = criarMatriz (linha, coluna);//
	aux->prox = *inicio;
	*inicio = aux;
}

void exclui_matriz (char nome[], matriz **inicio)
{
	matriz *aux = *inicio;
	if(!aux){	
		printf("ERRO\n");
		break;
	}
	if (!strcmp(nome, aux->nome)){
		destruirMatriz (aux->mat, aux->linhas);//
		*inicio = aux->prox;
		free(aux);
		break;
	}
	do{
		if (!strcmp(nome, aux->prox->nome)){
			destruirMatriz (aux->prox->mat, aux->prox->linhas);//
			aux->prox = aux->prox->prox;
			free(aux);
			break;
		}
		aux = aux->prox;
	}while (aux);

	printf("ERRO\n");
	break;
}

void imprime_matriz (char nome1[], nome2[], nome[], matriz *inicio)
{
	matriz *aux = encontra_matriz (nome, *inicio);
	imprimirMatriz (aux->(&mat), aux->linhas, aux->colunas);//
}

void atribui_valor (char nome[TAMANHO_NOME], matriz *inicio, float valor, int linha, int coluna)
{
	matriz *aux = encontra_matriz (nome, inicio);
	atribuirValor (aux->(&mat), valor, linha, coluna, aux->linhas, aux->colunas);//
}

void atribui_linha (char nome[], matriz *inicio, int linha)
{
	matriz *aux = encontra_matriz (nome, inicio);
	atribuirLinha (aux->(&mat), aux->linhas, aux->colunas, linha);//
}

void atribui_coluna (char nome[], matriz *inicio, int coluna)
{
	matriz *aux = encontra_matriz (nome, inicio);
	atribuirColuna (aux->(&mat), aux->linhas, aux->colunas, coluna);//
}

void transpor_matriz (char nome[], matriz *inicio)
{
	matriz *aux = encontra_matriz (nome, inicio);
	aux->(*mat) = transporMatriz (aux->(&mat), aux->linhas, aux->colunas);//
}

void somar_matriz (char nome1[], char nome2[], char nome[], matriz **inicio)
{
	matriz *aux1 = encontra_matriz (nome1, inicio);
	matriz *aux2 = encontra_matriz (nome2, inicio);
	matriz *aux = (*matriz) malloc (sizeof matriz);
	strcpy (aux->nome, nome);
	aux->linhas = aux1->linhas;
	aux->colunas = aux1->colunas;
	aux->*mat = criarMatriz (linha, coluna);//
	aux->prox = *inicio;
	*inicio = aux;
	(*inicio)->mat = somarMatriz (aux1->mat, aux2->mat, aux1->linhas, aux1->colunas, aux2->linhas, aux2->colunas);
}

void dividir_matriz (char nome1[], char nome2[], char nome[], matriz **inicio)
{
	matriz *aux1 = encontra_matriz (nome1, inicio);
	matriz *aux2 = encontra_matriz (nome2, inicio);
	matriz *aux = (*matriz) malloc (sizeof matriz);
	strcpy (aux->nome, nome);
	aux->linhas = aux1->linhas;
	aux->colunas = aux1->colunas;
	aux->*mat = criarMatriz (linha, coluna);//
	aux->prox = *inicio;
	*inicio = aux;
	(*inicio)->mat = divideMatriz (aux1->mat, aux2->mat, aux1->linhas, aux1->colunas, aux2->linhas, aux2->colunas);
}

void ME (char nome1[], char nome2[], char nome[], matriz **inicio)
{
	matriz *aux1 = encontra_matriz (nome1, inicio);
	matriz *aux2 = encontra_matriz (nome2, inicio);
	matriz *aux = (*matriz) malloc (sizeof matriz);
	strcpy (aux->nome, nome);
	aux->linhas = aux1->linhas;
	aux->colunas = aux1->colunas;
	aux->*mat = criarMatriz (linha, coluna);//
	aux->prox = *inicio;
	*inicio = aux;
	(*inicio)->mat = ME (aux1->mat, aux2->mat, aux1->linhas, aux1->colunas, aux2->linhas, aux2->colunas);
}

void MM (char nome1[], char nome2[], char nome[], matriz **inicio)
{
	matriz *aux1 = encontra_matriz (nome1, inicio);
	matriz *aux2 = encontra_matriz (nome2, inicio);
	matriz *aux = (*matriz) malloc (sizeof matriz);
	strcpy (aux->nome, nome);
	aux->linhas = aux1->linhas;
	aux->colunas = aux2->colunas;
	aux->*mat = criarMatriz (linha, coluna);//
	aux->prox = *inicio;
	*inicio = aux;
	(*inicio)->mat = MM (aux1->mat, aux2->mat, aux1->linhas, aux1->colunas, aux2->linhas, aux2->colunas);
}

matriz *encontra_matriz (char nome [TAMANHO_NOME], matriz *inicio)
{
	
	if (!strcmp(nome, inicio->nome))
		return inicio;
	return encontra_matriz (inicio->prox->nome, inicio->prox);
}
