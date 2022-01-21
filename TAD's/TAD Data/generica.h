/*TAD DATA (dd,mm,aaaa)*/

/* TIPO DE DADO exportado */
struct data {
  int dia;
  int mes;
  int ano;
};

typedef struct data Data;

/* OPERAÇÕES Exportadas */

/* lê data , se verdadeiro retorna zero, se falso returna 1*/
int valida_data (int dia, int mes, int ano, Data *d);

/* Imprime data */
void imprime_data(Data d);

/* Valida ano bissexto */
int anoBissexto (int ano);

/* Calcula dias entre duas datas */
void calcula_data(Data d1, Data d2);

/* Calcula dia da Páscoa */
void calcula_pascoa();

/* Recebe uma string e converte para o tipo Data 
 * fazendo validação de formato
 * e se a data é valida
 * */
int converte(char *stringData, Data *d);

/* Valida string no formato:
 *
 * dd/mm/aaaa
 * dd/m/aaaa
 * d/mm/aaaa
 * d/m/aaaa
 *
 * dd-mm-aaaa
 * dd-m-aaaa
 * d-mm-aaaa
 * d-m-aaaa
 *
 * */
int validaFormatoString(char *stringData);

int somaDias(Data d, int dias);
