# include <stdio.h>
# include <stdlib.h>
# include "LLEnc.h"

TipoPtNo* inicializa(void)
{
  return NULL;
}

void imprime(TipoPtNo* ptLista)
{
  TipoPtNo* ptaux;
  if (ptLista == NULL)
    puts("lista vazia");
  else
  for (ptaux=ptLista; ptaux!=NULL; ptaux=ptaux->prox)
    printf("Titulo = %s Distribuidor = %s Diretor = %s\n",
      ptaux->info.titulo,
      ptaux->info.distr,
      ptaux->info.diretor);
}

TipoPtNo* insereInicio ( TipoPtNo* ptLista, TipoInfoNo dados )
{
  TipoInfoNo *novo;
  novo = ( TipoPtNo* ) malloc(sizeof(TipoPtNo));
  novo->info = dados;
  novo->prox=ptLista;
  ptLista = novo;
  return novo;
}
