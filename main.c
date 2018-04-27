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
				printf("Criar matriz %s %dx%d\n", nome1, linha, coluna);
				nova_matriz(nome1,linha,coluna,&lista);
				break;
			case DM: //<nome>
				scanf("%s", nome1);
				printf("Destruir matriz\n\n");
				exclui_matriz (nome1, &lista);
				break;
			case IM: //<nome>
				scanf("%s", nome1);
				printf("Imprimir matriz\n\n");
				imprime_matriz(nome1, lista);
				break;
			case AE: //<nome> <linha> <coluna> <valor>
				scanf("%s %d %d %f", nome1, &linha, &coluna, &valor);
				printf("Atribuir valor\n\n");
				atribui_valor(nome1, lista, valor, linha, coluna);
				break;
			case AL: //<nome> <linha> <val1> <val2> ... <valn>
				scanf("%s %d ", nome1, &linha);
				printf("Atribuir linha\n\n");
				atribui_linha(nome1,lista,linha);
				break;
			case AC: //<nome> <coluna> <val1> <val2> ... <valn>
				scanf("%s %d", nome1, &coluna);
				printf("Atribuir coluna\n\n");
				atribui_coluna(nome1,lista,coluna);
				break;
			case TM: //<nome> <nome-resultado>
				scanf("%s %s", nome1, nomeR);
				printf("Transpor matriz\n\n");
				transpor_matriz(nome1,&lista, nomeR);
				break;
			case SM: //<nome1> <nome2> <nome-resultado>
				scanf("%s %s %s", nome1, nome2, nomeR);
				printf("Somar matrizes\n\n");
				somar_matriz (nome1,nome2,nomeR,&lista);
				break;
			case DV: //<nome1> <nome2> <nome-resultado>
				scanf("%s %s %s", nome1, nome2, nomeR);
				printf("Dividir matrizes\n\n");
				dividir_matriz (nome1,nome2,nomeR,&lista);
				break;
			case MM: //<nome1> <nome2> <nome-resultado>
				scanf("%s %s %s", nome1, nome2, nomeR);
				printf("Multiplicar matriz por matriz\n\n");
				break;
			case ME: //<nome1> <nome2> <nome-resultado>
				scanf("%s %s %s", nome1, nome2, nomeR);
				printf("Multiplicar matrizes elemento a elemento\n\n");
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

