typedef struct no matriz;

void nova_matriz (char nome[], int linhas, int colunas);
void exclui_matriz (char nome[], matriz **inicio);
void imprime_matriz (char nome1[], char nome2[], char nome[], matriz *inicio);
void atribui_valor (char nome[], matriz *inicio, float valor, int linha, int coluna);
void atribui_linha (char nome[], matriz *inicio, int linha);
void atribui_coluna (char nome[], matriz *inicio, int coluna);
void transpor_matriz (char nome[], matriz *inicio);
void somar_matriz (char nome1[], char nome2[], char nome[], matriz **inicio);
void dividir_matriz (char nome1[], char nome2[], char nome[], matriz **inicio);
void ME (char nome1[], char nome2[], char nome[], matriz **inicio);
void MM (char nome1[], char nome2[], char nome[], matriz **inicio);
matriz *encontra_matriz (char nome [], matriz *inicio);
