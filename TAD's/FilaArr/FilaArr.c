# include <stdio.h>
# include <stdlib.h>
# include "FilaArr.h"

int incr ( int i ) 
{
  // se N for 10 e i 9 então
  // (9 + 1) % 10 retorna 0
  // se < 10 returna i+1 << esse é o tipo de caso que nos interessa
  // pois indica o incremento que vai ocorrer. 
    return (i+1)%N;
}

/* Inicializa a fila */
fila* cria(void) {

  fila* f=(fila*) malloc(sizeof(fila));
  f->ini=f->fim=0;  // inicializa a fila vazia
  return f;

}

Dados* preenche_dados(int dado)
{
  Dados* d=(Dados*) malloc(sizeof(Dados));
  d->info=dado; 
  return d;
}


// Procedimento de inserção
void insere(fila* f, int v)
{
  int fim=incr(f->fim);

  if ( fim == f->ini )  // se incr retornar 0 , fila esta cheia
  {
    printf("fila cheia.\n");
  }else{
  // Se chegou até aqui é por que pode inserir na posicição livre
    f->vet[f->fim].dados = preenche_dados(v);
    f->fim = fim;
  }

}

int retira ( fila* f )
{
  //Dado que vai ser retirado
  int v;

  if (vazia(f)) 
  {
    printf("Fila vazia.\n");
    return 0;
  }else{
    v = f->vet[f->ini].dados->info;
    f->ini = incr(f->ini);
    return v;
  }


}

int vazia( fila* f )
{
  return (f->ini==f->fim);
}

void libera (fila * f) 
{
  free(f);
}

void imprime(fila* f)
{
  for (int i=f->ini; i<f->fim; i++)
    printf("%d\n",f->vet[i].dados->info);
}
