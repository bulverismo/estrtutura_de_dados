/*TAD Genérica Lista Linear Simplesmente Encadeada*/

/* TIPO DE DADO exportado */
/* dados armazenados */
struct s_InfoNo{
  int codigo;
  char nome[30];
  float preco;
};

typedef struct s_InfoNo TipoInfoNo;

/* informações do nodo */
struct s_PtNo{
  TipoInfoNo info;
  struct s_PtNo * prox;
};

typedef struct s_PtNo TipoPtNo;

/* OPERAÇÕES Exportadas */

/* inicializa lista */
TipoPtNo* inicializa(void);

/* Imprime data */
void imprime();

/* Consulta do dado armazenado */
void consulta();

/* Insere no Inicio */
TipoPtNo* insereInicio();

/* Insere no Fim */
TipoPtNo* insereInicio();

/* Remove nodo */
void remove();

/* Destrói a lista */
void destroi();
