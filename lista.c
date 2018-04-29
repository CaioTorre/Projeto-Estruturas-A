#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

#define TAMANHO_NOME 20

struct no{
char nome[TAMANHO_NOME];
int linhas;
int colunas;
float **mat;
struct no *prox;
};

typedef struct no matriz;

matriz *encontra_matriz (char nome[], matriz *inicio)
{
	if (!inicio)
		return NULL;
	if (!strcmp(nome, inicio->nome))
		return inicio;
	if(!inicio->prox)
		return NULL;
	return encontra_matriz (nome, inicio->prox);
}

void nova_matriz (char nome[], int linhas, int colunas, matriz **inicio)
{
	if (encontra_matriz(nome, (* inicio)) == NULL){
		matriz *aux;
		aux = (matriz *) malloc (sizeof(matriz));
		strcpy (aux->nome, nome);
		aux->linhas = linhas;
		aux->colunas = colunas;
		aux->mat = criarMatriz (linhas, colunas, 0, 1);//
		//printf("%d", (int) aux->mat);
		if ((int)aux->mat <= 0){
			//printf("will free");
			free(aux);
		}else{
			aux->prox = *inicio;
			*inicio = aux;
		}
	}else{
		printf("ERRO\n");
	}
}

void exclui_matriz (char nome[], matriz **inicio)
{
	matriz *aux = *inicio;
	if(!aux){	
		printf("ERRO\n");
	}
	else{
		if (!strcmp(nome, aux->nome)){
			destruirMatriz (aux->mat, aux->linhas);//
			*inicio = aux->prox;
			free(aux);
		}
		else{
			aux = aux->prox;
			while(aux->prox){
				if (!strcmp(nome, aux->prox->nome)){
					destruirMatriz (aux->prox->mat, aux->prox->linhas);//
					aux->prox = aux->prox->prox;
					free(aux);
					break;
					}
			aux = aux->prox;
			}
		}
	}
}

void imprime_matriz (char nome[], matriz *inicio)
{
	matriz *aux;
	if(aux = encontra_matriz (nome, inicio)) imprimirMatriz (aux->mat, aux->linhas, aux->colunas);//
	else printf("ERRO\n");
	
}

void atribui_valor (char nome[], matriz *inicio, float valor, int linha, int coluna)
{
	matriz *aux;
	if(aux = encontra_matriz (nome, inicio)) atribuirValor (aux->mat, valor, linha, coluna, aux->linhas, aux->colunas);//
	else printf("ERRO\n");
}

void atribui_linha (char nome[], matriz *inicio, int linha)
{
	matriz *aux;
	if(aux = encontra_matriz (nome, inicio)) atribuirLinha (aux->mat, aux->linhas, aux->colunas, linha);//
	else printf("ERRO\n");
}

void atribui_coluna (char nome[], matriz *inicio, int coluna)
{
	matriz *aux;
	if(aux = encontra_matriz (nome, inicio)) atribuirColuna (aux->mat, aux->linhas, aux->colunas, coluna);//
	else printf("ERRO\n");
}

void transpor_matriz (char nome[], matriz **inicio, char nomeRES[])
{
	matriz *aux, *aux2;
	if (encontra_matriz(nomeRES, (* inicio)) == NULL){
		if(aux = encontra_matriz (nome, *inicio)){ 
			aux2 = (matriz *) malloc (sizeof(matriz));
			strcpy (aux2->nome, nomeRES);
			aux2->linhas = aux->colunas;
			aux2->colunas = aux->linhas;
			aux2->mat = transporMatriz (aux->mat, aux->linhas, aux->colunas);//
			aux2->prox = *inicio;
			*inicio = aux2;
		}
		else printf("ERRO\n");
	}
	else printf("ERRO\n");
}

void somar_matriz (char nome1[], char nome2[], char nome[], matriz **inicio)
{
	if (encontra_matriz(nome, (* inicio)) == NULL){
		matriz *aux1 = encontra_matriz (nome1, *inicio);
		matriz *aux2 = encontra_matriz (nome2, *inicio);
		if((!aux1 || !aux2) || (aux1->linhas != aux2->linhas) || (aux1->colunas != aux2->colunas)) printf("ERRO\n");
		else{
			matriz *aux = (matriz *) malloc (sizeof(matriz));
			strcpy (aux->nome, nome);
			aux->linhas = aux1->linhas;
			aux->colunas = aux1->colunas;
			aux->prox = *inicio;
			*inicio = aux;
			(*inicio)->mat = somarMatriz (aux1->mat, aux2->mat, aux1->linhas, aux1->colunas);
		}
	}
	else prntf("ERRO\n");
}

void dividir_matriz (char nome1[], char nome2[], char nome[], matriz **inicio)
{
	if (encontra_matriz(nome, (* inicio)) == NULL){
		matriz *aux1 = encontra_matriz (nome1, *inicio);
		matriz *aux2 = encontra_matriz (nome2, *inicio);
		if((!aux1 || !aux2) || (aux1->linhas != aux2->linhas) || (aux1->colunas != aux2->colunas)) printf("ERRO\n");
		else{
			matriz *aux = (matriz *) malloc (sizeof(matriz));
			strcpy (aux->nome, nome);
			aux->linhas = aux1->linhas;
			aux->colunas = aux1->colunas;
			aux->mat = divideMatriz (aux1->mat, aux2->mat, aux1->linhas, aux1->colunas);
			if(aux->mat == (float **)-2){
				printf("ERRO\n");
				free(aux);
			}
			else{
				aux->prox = *inicio;
				*inicio = aux;
			}
		}
	}
	else printf("ERRO\n");
}

void MElista(char nome1[], char nome2[], char nome[], matriz **inicio)
{
	if (encontra_matriz(nome, (* inicio)) == NULL){
		matriz *aux1 = encontra_matriz (nome1, *inicio);
		matriz *aux2 = encontra_matriz (nome2, *inicio);
		if((!aux1 || !aux2) || (aux1->linhas != aux2->linhas) || (aux1->colunas != aux2->colunas))printf("ERRO\n");
		else{
			matriz *aux = (matriz *) malloc (sizeof(matriz));
			strcpy (aux->nome, nome);
			aux->linhas = aux1->linhas;
			aux->colunas = aux1->colunas;
			aux->mat = criarMatriz (aux->linhas, aux->colunas, 1, 0);//
			aux->prox = *inicio;
			*inicio = aux;
			(*inicio)->mat = MultElemMat(aux1->mat, aux2->mat, aux1->linhas, aux1->colunas);
		}
	}
	else printf("ERRO\n");
}

void MMlista(char nome1[], char nome2[], char nome[], matriz **inicio)
{
	if (encontra_matriz(nome, (* inicio)) == NULL){
		matriz *aux1 = encontra_matriz (nome1, *inicio);
		matriz *aux2 = encontra_matriz (nome2, *inicio);
		if((!aux1 || !aux2) || (aux1->colunas != aux2->linhas))	printf("ERRO\n");
		else{
		  matriz *aux = (matriz *) malloc (sizeof(matriz));
		  strcpy (aux->nome, nome);
		  aux->linhas = aux1->linhas;
		  aux->colunas = aux2->colunas;
		  aux->mat = criarMatriz(aux->linhas, aux->colunas,1, 0);//
		  aux->prox = *inicio;
		  *inicio = aux;
		  (*inicio)->mat = MultMat(aux1->mat, aux2->mat, aux1->linhas, aux1->colunas, aux2->linhas, aux2->colunas);
		}
	}
	else printf("ERRO\n");
}
