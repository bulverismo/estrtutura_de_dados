/*TAD Fila em Arranjo*/

/* TIPO DE DADO exportado */

// tamanho da lista
#define N 100 


// tipo de dado que vai ser manipulado fica aqui isolado
// podendo essa logica de lista em arranjo ser utilizada 
// com qualquer tipo de dado ou estrutura
// devendo cuidar somente da rotina de insersão
struct dados {
  int info;
  char* nome;
};

typedef struct dados Dados;

// Nesta parte trata de cada um dos nós da fila 
// que tem sua parte que trata sobre a fila 
// separado da logica dos dados em si
// se eu adicionar mais uma struct de dado
// devo somente me preocupar em criar um função que
// insere seus dados
// dessa forma posso somente trocar aqui o tipo de dado da lista
// me preocupando somente com a rotina de inserção do dado
struct No {
  Dados* dados; // dados
};

typedef struct No no;

// fila em si é um vetor de nós
// da pra fazer essa parte da referencia ao nó de diversas
// formas depende do objetivo
// temos aqui junto da struct da fila os controladores dos indices
// de inicio e fim da lista
struct Fila {
  int ini,fim;
  no vet[N];
};

typedef struct Fila fila;

/* OPERAÇÕES Exportadas */

/* Inicializa fila */
fila* cria (void);

/* Função auxiliar para incrementar o valor de um índice */
int incr( int i );

/* função para inserir no final */
void insere(fila* f, int v);

/* função para remover o primeiro pois é uma fila */
int retira ( fila* f );

/* função para testar se a fila esta vazia */
int vazia( fila* f );

/* libera os endereços utilizados na lista */
void libera( fila* f );

/* imprime a fila */
void imprime( fila* f );

/* função auxiliar para preencer dados */
Dados* preenche_dados(int dado);
