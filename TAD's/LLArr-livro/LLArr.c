# include <stdio.h>
# include <stdbool.h>
# include "LLArr.h"

void InicializaLLArr (int ia)
{
  IL = FL = ia - 1; // inicializa variaveis para poder inserir a partir do inicio do arranjo
}
/* Inserir no inicio da lista */
bool InserirIniLLArr (TipoNodo LL[],int ia, int fa, int *il,int *fl, TipoNodo InfoNodo)
{
  int Ind; // variavel auxiliar
  bool Sucesso;

  if ( (ia == *il) && (fa == *fl) ) // se a lista esta cheia não vai inserir
    Sucesso = false;
  else
  {
    if ( *il == -1 ) // se a lista esta vazia prepara para inserir no inicio
      *il = *fl = ia;
    else 
    {
      if ( *il > ia ) // se o inicio da lista não e no começo do arranjo
        *il = *il-1;
      else
      {
        for ( Ind = *fl; Ind >= *il; Ind--) // desloca nodos para cima
          LL[Ind+1] = LL[Ind];
        *fl = *fl + 1;
      }
    }
    LL[*il] = InfoNodo; // insere no inicio da lista
    Sucesso = true;
  }
  return Sucesso;  
}

/* Inserir no fim da lista */
bool InserirFimLLArr (TipoNodo LL[],int ia, int fa, int *il,int *fl, TipoNodo InfoNodo)
{
  bool Sucesso;
  int Ind; // variavel auxiliar

  if ( (ia == *il) && (fa == *fl) ) // se a lista esta cheia não vai inserir
    Sucesso = false;
  else
  {
    if ( *il == -1 ) // se a lista esta vazia então insere no primeiro nodo disponível 
      *il = *fl = ia;
    else if ( *fl < fa ) // se o final da lista é menor que o final do arranjo prepara o final da lista para receber o novo nodo
      *fl = *fl + 1;
    else
    {
      for ( Ind = *il; Ind >= *fl; Ind++) // desloca nodos para baixo 
        LL[Ind-1] = LL[Ind];
      *il = *il - 1;
    }
    LL[*fl] = InfoNodo;  // insere no fim da lista
    Sucesso = true;
  }
  return Sucesso;
}

/* Inserir na K'ésima posição da LISTA */
bool InserirLLArrPosK (TipoNodo LL[],int ia, int fa, int *il,int *fl,int K, TipoNodo InfoNodo)
{
  int Ind;
  bool Sucesso;

  //                                                                     se não há elementos na 
  //                                       se posição k não for um     lista e não quer adicionar
  //     se lista esta cheia                  um indice válido             na primeiro posição
  if ( (ia == *il) && (fa == *fl) || ( K > *fl-*il+1 ) || ( K <= 0 ) || ( *il == -1 && K != 1 ) )
    Sucesso = false;
  else 
    if ( *il == -1 ) // se a lista está vazia insere no inicio
      *il = *fl = ia;
    else if ( *fl != fa ) // se não quer adicionar no fim então desloca os nodos para adicionar no inicio
    {
      // insere no inicio
      for ( Ind = *fl; Ind >= *il+K-1; Ind--) // desloca nodos para cima
        LL[Ind+1] = LL[Ind];
      *fl = *fl + 1;
    }
    else  // entra neste caso se quer adicionar no fim
    {
      // insere no fim
      for ( Ind = *il; Ind >= *il+K-1; Ind++) // desloca nodos para baixo 
        LL[Ind-1] = LL[Ind];
      printf("debugame");
      *il = *il - 1;
    }
  LL[*il+K-1] = InfoNodo;
  Sucesso = true;
  return Sucesso;
}

void imprime ( TipoNodo LL[], int fim )
{
  for ( int i = 0; i <= fim; i++ )
  {
    printf(" [ %d ] ",LL[i].codigo);
  }
  printf("\n");
  printf("IA %d | FA %d | IL %d | FL %d\n",IA,FA,IL,FL);
  
}
