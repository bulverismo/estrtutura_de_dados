# include <stdio.h>
# include <stdlib.h>
# include "tadGenerica.h"

/* lê dado */
void le_dado (tipoAbstrato *t) {
  printf("Letra: ");
  scanf("%c",&t->letra);
  printf("Numero: ");
  scanf("%d",&t->numero);
}

/* Valida se é um numero positivo */
int valida_dado(tipoAbstrato t) {
  if (t.numero < 0)
    return 0;
  else
    return 1;
}

/* Imprime dado */
void imprime_dado(tipoAbstrato t) {
  printf("Letra %c Numero %d\n", t.letra, t.numero);
}

/* Calcula diferenca entre dois numero */
void calcula_diferenca(tipoAbstrato t1, tipoAbstrato t2) {
  int diferenca;
  if ( valida_dado(t1) & valida_dado(t2) )
  {
    diferenca = t1.numero - t2.numero;
    printf("diferenca = %d\n",diferenca);
  }
  else
    printf("Dado inválido detectado!\n");
  
}
