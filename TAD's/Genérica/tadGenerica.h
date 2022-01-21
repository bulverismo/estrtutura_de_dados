/*TAD Generica */

/* TIPO DE DADO exportado */
struct estruturaGenerica {
  char letra;
  int numero;
};

/* Criando um tipoAbstrato usando a estrutura estruturaGenerica */
typedef struct estruturaGenerica tipoAbstrato;

/* OPERAÇÕES Exportadas */

/* lê dado */
void le_dado (tipoAbstrato *t);

/* Valida se é um numero positivo */
int valida_dado(tipoAbstrato t);

/* Imprime dado */
void imprime_dado(tipoAbstrato t);

/* Calcula diferenca entre dois numero */
void calcula_diferenca(tipoAbstrato t1, tipoAbstrato t2);
