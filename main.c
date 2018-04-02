#include <stdlib.h>
#include <stdio.h>

#define TAMANHO_NOME 20
#define TAMANHO_VALS 300

enum opcodes {CM = 64, DM = 90, IM = 220, AE = 4, AL = 11, AC = 2, TM = 506, SM = 480, DV = 99, MM = 324, ME = 316, FE = 134};

int main() {
	int cont = 1;
	enum opcodes opcode;
	char cmd[3];
	char nome1[TAMANHO_NOME], nome2[TAMANHO_NOME], nomeR[TAMANHO_NOME], vals[TAMANHO_VALS];
	int linha, coluna;
	do {
		fgets(cmd, 3, stdin);
		opcode = ((int)cmd[0] - 65) * 26 + (int)cmd[1] - 65;
		switch (opcode) {
			case CM: //<nome> <numero linhas> <numero colunas>
				scanf("%s %d %d", nome1, &linha, &coluna);
				printf("Criar matriz %s %dx%d\n\n", nome1, linha, coluna);
				break;
			case DM: //<nome>
				printf("Destruir matriz\n\n");
				break;
			case IM: //<nome>
				printf("Imprimir matriz\n\n");
				break;
			case AE: //<nome> <linha> <coluna> <valor>
				printf("Atribuir valor\n\n");
				break;
			case AL: //<nome> <linha> <val1> <val2> ... <valn>
				printf("Atribuir linha\n\n");
				break;
			case AC: //<nome> <coluna> <val1> <val2> ... <valn>
				printf("Atribuir coluna\n\n");
				break;
			case TM: //<nome> <nome-resultado>
				printf("Transpor matriz\n\n");
				break;
			case SM: //<nome1> <nome2> <nome-resultado>
				printf("Somar matrizes\n\n");
				break;
			case DV: //<nome1> <nome2> <nome-resultado>
				printf("Dividir matrizes\n\n");
				break;
			case MM: //<nome1> <nome2> <nome-resultado>
				printf("Multiplicar matriz por matriz\n\n");
				break;
			case ME: //<nome1> <nome2> <nome-resultado>
				printf("Multiplicar matrizes elemento a elemento\n\n");
				break;
		}
	} while (opcode != FE);
	return 0;
}
