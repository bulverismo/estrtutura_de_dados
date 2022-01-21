# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "FilaArr.h"

int main (int argc, char **argv)
{
  int i=0;
  // Cria o tipo de dado
  fila* f = cria();

  // faz inserções
  srand(time(NULL));
  while(++i<101)
    insere(f,rand()%1000);

  // retirando elementos
  printf("Primeiro elemento: %d\n",retira(f));
  printf("Segundo elemento: %d\n",retira(f));
  printf("Configurações da fila:\n");

  // imprimindo elementos da fila
  imprime(f);

  // liberando endereços de memória utilizados 
  libera(f);

  return 0;

}
// gcc -std=c99 -o filaArr main.c FilaArr.c -lm
