/*TAD Fila Encadeada*/

/* TIPO DE DADO exportado */
// temos aqui separado a logica do dado em si
// isolado em uma estrutura de dado que ao ser 
// modificada só preciso me preocupar com a função que trata da sua inserção
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
struct No {
  Dados* dados; // dados
  struct No* prox;
};

typedef struct No no;

// Mais uma vez vemos a lógica separada
// neste caso a lógica da fila esta totalmente isolada
// dos dados em si, somente tendo ligação com o tipo
// do dado de cada um dos nós desta fila
struct Fila {
  no* ini;
  no* fim;
};

typedef struct Fila fila;

/* OPERAÇÕES Exportadas */

/* Inicializa fila */
fila* cria (void);

/* função auxiliar para inserir final */
no* ins_fim(no* fim, int v);

/* criar nodo */
no* cria_nodo(int dado);

/* função auxiliar para retirar do inicio */
no* ret_ini(no* ini);

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
