#include <string.h>
#include "lista.h"

#define TAMANHO_NOME 20

struct matriz{
char nome [20];
int linha;
int coluna
float *mat;
matriz *prox;
};

void nova_matriz (char nome[TAMANHO_NOME], int linha, int coluna, matriz **inicio)
{
	matriz *aux;
	aux=(*matriz)malloc(*matriz);
	strcpy(aux->nome, nome);
	
}
