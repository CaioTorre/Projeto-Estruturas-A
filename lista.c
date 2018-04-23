#include <string.h>
#include "lista.h"

#define TAMANHO_NOME 20

struct matriz{
char nome [TAMANHO_NOME];
int linha;
int coluna
float **mat;
matriz *prox;
};

void nova_matriz (char nome[TAMANHO_NOME], int linha, int coluna, matriz **inicio)
{
	matriz *aux;
	aux = (*matriz) malloc (*matriz);
	strcpy (aux->nome, nome);
	aux->linha = linha;
	aux->coluna = coluna;
	//aux->*mat = criarMatriz (linha, coluna);
	aux->prox = *inicio;
	*inicio = aux;
}

void exclui_matriz (char nome[TAMANHO_NOME], matriz **inicio)
{
	matriz *aux = *inicio;
	if(!aux){	
		printf("ERRO\n");
		break;
		}
	if (strcmp(nome, aux->nome) == 0)
	{
	//destruirMatriz (*inicio->mat, linhas)
	}
	
	
}

void imprime_matriz (char nome[TAMANHO_NOME], matriz *inicio, int linhas, int colunas)
{
	matriz *aux = encontra_matriz (nome, *inicio);
	//imprimirMatriz (aux->(&mat), linhas, colunas);
}

void atribui_valor (char nome[TAMANHO_NOME], matriz *inicio, float valor, int linha, int coluna, int linhas, int colunas)
{
	matriz *aux = encontra_matriz (nome, inicio);
	//atribuirValor (aux->(&mat), valor, linha, coluna, linhas, colunas);
}

void transpor_matriz (char nome[TAMANHO_NOME], matriz *inicio, int linhas, int colunas)
{
	matriz *aux = encontra_matriz (nome, inicio);
	//aux->(*mat) = transporMatriz (aux->(&mat), linhas, colunas);
}

matriz *encontra_matriz (char nome [TAMANHO_NOME], matriz *inicio)
{
	
	if (strcmp(nome, inicio->nome) == 0)
		return inicio;
	return encontra_matriz (inicio->prox->nome, inicio->prox);
}
