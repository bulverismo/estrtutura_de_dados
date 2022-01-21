/* Arquivo de exemplo usando uma tadGenérica
 * Criado por José Américo 
 * na disciplina de Estrura de Dados UFRGS 2020/2
 */


# include <stdio.h>
# include <stdlib.h>
# include "tadGenerica.h"

int main (void)
{
  tipoAbstrato var1,var2;

  printf("Lendo dado 1:\n");
  le_dado(&var1);
  fflush(stdin);

  printf("Lendo dado 2:\n");
  le_dado(&var2);
  fflush(stdin);

  valida_dado(var1);

  printf("Comparando dados:\n");
  imprime_dado(var1);

  printf("Calculando a diferença entre os dados:\n");
  calcula_diferenca(var1, var2);
  
    
  return 0;
}
/*
gcc -std=c99 -o go main.c tadGenerica.c -lm #*/
