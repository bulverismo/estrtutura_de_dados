# include <stdio.h>
# include <stdlib.h>
# include "FilaEnc.h"

int main (int argc, char **argv)
{
  // Cria o tipo de dado
  fila* f = cria();

  // faz inserções
  insere(f,2);
  insere(f,3);
  insere(f,1);
  insere(f,5);
  insere(f,33);
  insere(f,99);

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
// gcc -std=c99 -o exec main.c FilaEnc.c -lm
