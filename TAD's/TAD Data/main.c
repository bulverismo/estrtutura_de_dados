# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "generica.h"

int main (int argc, char **argv)
{
  int dia, mes, ano;
  Data date;
 /* scanf("%d",&dia);
  scanf("%d",&mes);
  scanf("%d",&ano);  
  
  if (valida_data(dia,mes,ano,&date) == 0)
    imprime_data(date);
  else
    printf("Data invalida!\n");
*/

  if ( converte(argv[1],&date) == 0 )
  {
    printf("data %d/%d/%d\n",date.dia,date.mes,date.ano);
    printf("retornou de soma dias %d\n",somaDias(date, 20)) ;
  }
  else
    printf("Data Invalida\n");


  return 0;
}
// gcc -std=c99 -o go main.c data.c -lm
