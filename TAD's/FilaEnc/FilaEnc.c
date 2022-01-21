# include <stdio.h>
# include <stdlib.h>
# include "FilaEnc.h"

/* Inicializa a fila */
fila* cria(void) {

  fila* f=(fila*) malloc(sizeof(fila));
  f->ini=f->fim=NULL;
  return f;

}

/* função auxiliar: insere no fim */
no* ins_fim(no* fim, int v)
{
  
  no* p;
  p=cria_nodo(v);

  if (fim!=NULL)
    fim->prox=p;

  return p;
 
}

/* cria nodo */
no* cria_nodo(int dado)
{
  no* p = (no*) malloc(sizeof(no));

  p->dados=preenche_dados(dado);
  p->prox=NULL;
  
  return p;
}

Dados* preenche_dados(int dado)
{
  Dados* d=(Dados*) malloc(sizeof(Dados));
  d->info=dado; 
  return d;
}

/* remove do inicio */ 
no* ret_ini(no* ini)
{
  no* p = ini->prox;
  free(ini);
  return p;
}

void insere(fila* f, int v)
{
  f->fim = ins_fim(f->fim,v);
  if (f->ini==NULL) /* fila antes vazia? */
    f->ini = f->fim;

}

int retira ( fila* f )
{
  //Dado que vai ser retirado
  int v;

  if (vazia(f)) 
  {
    printf("Fila vazia.\n");
    exit(1);
  }

  v = f->ini->dados->info;

  f->ini = ret_ini(f->ini);

  if (f->ini == NULL) /* fila ficou vazia? */
    f->fim = NULL;

  return v;

}

int vazia( fila* f )
{
  return (f->ini==NULL);
}

void libera (fila * f) 
{
  no* q = f->ini;
  while (q!=NULL)
  {
    no* t = q->prox;
    free(q);
    q = t;
  }
  free(f);
}

void imprime(fila *f)
{
  no* q;
  for (q=f->ini; q!=NULL; q=q->prox)
    printf("%d\n",q->dados->info);
}
