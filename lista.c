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
	if (strcmp(nome, aux->prox->nome) == 0){

	}
	if (strcmp(nome, aux->prox->nome) != 0)
		exclui_matriz (nome, &aux->prox);
	
}
