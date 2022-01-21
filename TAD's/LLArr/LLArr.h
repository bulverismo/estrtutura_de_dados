/* TAD Lista Linear com Contiguidade Física - Em arranjo*/

/* Tipo de dado exportado */
struct T_Produto {
  int cod;
  char nome[40];
  float preco;
};

typedef struct T_Produto TProduto;

int inicio, fim; 

/* Operações exportadas */

/* Inicializar a lista */
void inicializa ( TProduto t[], int *inicio, int *fim );

/* Consultar lista */
int consulta ( TProduto t[], int inicio, int fim, int posicao);

/* Insere na lista */
void insere ( TProduto t[], int *inicio, int *fim, int posicao);

/* Remove da lista */
int remover ( TProduto t[], int *inicio, int *fim, int posicao);

/* Imprime Nodo */
void imprime ( TProduto t[],int inicio, int fim, int posicao );

/* Destrói Lista */
void destroi ( TProduto t[], int *inicio, int *fim );
