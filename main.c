/*
 * Estrutura e Recuperação de Dados A
 * Projeto 1 (Lista Ligada e Matrizes)
 */
//Bruno Guilherme Marini Spirlandeli    - RA 17037607
//Caio Lima e Souza Della Torre Sanches - RA 17225285
//Gabriela Nelsina Vicente              - RA 17757089
//Marcos Aurélio Tavares de Sousa Filho - RA 17042284

#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include "lista.h"

#define TAMANHO_NOME 20
#define TAMANHO_VALS 300

typedef struct no matriz;
struct no{
char nome[TAMANHO_NOME];
int linhas;
int colunas;
float **mat;
struct no *prox;
};

enum opcodes {CM = 64, DM = 90, IM = 220, AE = 4, AL = 11, AC = 2, TM = 506, SM = 480, DV = 99, MM = 324, ME = 316, FE = 134};

void exibe (matriz *Lista) {
    while (Lista!=NULL) {
      printf("(%s lin:%d col:%d) ",Lista->nome, Lista->linhas, Lista->colunas);
      Lista = Lista->prox;
    }
}

int main() {
	int cont = 1;
	matriz *lista=NULL;
	enum opcodes opcode;
	char cmd[3];
	char nome1[TAMANHO_NOME], nome2[TAMANHO_NOME], nomeR[TAMANHO_NOME], vals[TAMANHO_VALS];
	float valores[50], valatual, valor;
	int linha, coluna;
	do {
		fgets(cmd, 3, stdin);
		opcode = ((int)cmd[0] - 65) * 26 + (int)cmd[1] - 65;
		switch (opcode) {
			case CM: //<nome> <numero linhas> <numero colunas>
				scanf("%s %d %d", nome1, &linha, &coluna);
				nova_matriz(nome1,linha,coluna,&lista);
				break;
			case DM: //<nome>
				scanf("%s", nome1);
				exclui_matriz (nome1, &lista);
				break;
			case IM: //<nome>
				scanf("%s", nome1);
				imprime_matriz(nome1, lista);
				break;
			case AE: //<nome> <linha> <coluna> <valor>
				scanf("%s %d %d %f", nome1, &linha, &coluna, &valor);
				atribui_valor(nome1, lista, valor, linha, coluna);
				break;
			case AL: //<nome> <linha> <val1> <val2> ... <valn>
				scanf("%s %d ", nome1, &linha);
				atribui_linha(nome1,lista,linha);
				break;
			case AC: //<nome> <coluna> <val1> <val2> ... <valn>
				scanf("%s %d", nome1, &coluna);
				atribui_coluna(nome1,lista,coluna);
				break;
			case TM: //<nome> <nome-resultado>
				scanf("%s %s", nome1, nomeR);
				transpor_matriz(nome1,&lista, nomeR);
				break;
			case SM: //<nome1> <nome2> <nome-resultado>
				scanf("%s %s %s", nome1, nome2, nomeR);
				somar_matriz (nome1,nome2,nomeR,&lista);
				break;
			case DV: //<nome1> <nome2> <nome-resultado>
				scanf("%s %s %s", nome1, nome2, nomeR);
				dividir_matriz (nome1,nome2,nomeR,&lista);
				break;
			case MM: //<nome1> <nome2> <nome-resultado>
				scanf("%s %s %s", nome1, nome2, nomeR);
				MMlista(nome1,nome2,nomeR,&lista);
				break;
			case ME: //<nome1> <nome2> <nome-resultado>
				scanf("%s %s %s", nome1, nome2, nomeR);
				MElista(nome1,nome2,nomeR,&lista);
				break;
		}
		#ifdef DEBUG
			printf("\n[DEBUG] Lista: ");
			exibe(lista);
			printf("\n");
			__fpurge(stdin);
		#endif
	} while (opcode != FE);
	return 0;
}
