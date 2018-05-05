float** criarMatriz(int linhas, int colunas, int zera, int OK);
void destruirMatriz(float **matriz, int linhas);
void imprimirMatriz(float **matriz, int linhas, int colunas);
void atribuirValor(float **matriz, float valor, int linha, int coluna, int linhas, int colunas);
void atribuirLinha(float **matriz, int linhas, int colunas, int linha);
void atribuirColuna(float **matriz, int linhas, int colunas, int coluna);
float** transporMatriz(float **matriz, int linhas, int colunas);
float**  somarMatriz(float **mat1, float **mat2, int lin1, int col1);
float**  divideMatriz(float **mat1, float **mat2, int lin2, int col2);
float**  MultMat(float **mat1, float **mat2, int lin1, int lin2, int col2);
float**  MultElemMat(float **mat1, float **mat2, int lin1, int col1);


