# include <stdio.h>
# include "LLArr.h"

#define MAX 5
int main(void) {

  TProduto Lista[MAX];
  
  inicializa( Lista, &inicio, &fim );
  insere( Lista, &inicio, &fim, 1);

  printf("função consulta retorna o dado em 1: %d\n",consulta( Lista, inicio, fim, 1 ));
  imprime(Lista, inicio, fim, 1);

  printf("função remove o dado de 1: %d\n",remover(Lista, &inicio, &fim, 1));
  printf("dado em 1: %d\n",consulta( Lista, inicio, fim, 1 ));

  imprime(Lista, inicio, fim, 1);
  
  return 0;

}

