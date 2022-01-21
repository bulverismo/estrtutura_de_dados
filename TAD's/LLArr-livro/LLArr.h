/* TAD Lista Linear com Contiguidade Física - Em arranjo*/

# include <stdbool.h>

/* Declaração da estrutura para criar o tipo */
struct registro {
 // char nome[40];
  int codigo;
  float valor;
};

/* Declaração do tipo */
typedef struct registro TipoNodo;

/* IA inicio arranjo ( sempre vai começar na 0 )
 * IL inicio lista
 * FL fim lista
 * FA fim arranjo ( vai ser o ultimo indice possivel, no caso tamanho do vetor-1 )
 */

int IA,FA,IL,FL; 

/* Operações exportadas */

/* Inicializar a lista */
void InicializaLLArr (int ia);

/* Inserir no inicio da lista */
bool InserirIniLLArr (TipoNodo LL[],int ia, int fa, int *il,int *fl, TipoNodo InfoNodo);

/* Inserir no fim da lista */
bool InserirFimLLArr (TipoNodo LL[],int ia, int fa, int *il,int *fl, TipoNodo InfoNodo);

/* Inserir no posição k da lista */
bool InserirLLArrPosK (TipoNodo LL[],int ia, int fa, int *il,int *fl, int K, TipoNodo InfoNodo);

/* função imprime temporaria */
void imprime ( TipoNodo LL[], int fim );
