# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "LLArr.h"

int main(int argc, char **argv){

  bool Sucesso=true;

  if (argc < 3)
  {
    printf("%s: Você deve especificar o tamanho do array e o campo que inicia a lista\n",argv[0]);
    fprintf(stderr,"Tente \"%s --help\" para mais informações\n",argv[0]);
    exit(1);
  }
   
  int max; 
  max = atoi(argv[1]);
  IL = atoi(argv[2]); 
  FA = max - 1;
  IA = 0;

  /* Cria um arranjo de TipoNodo com max elementos */
  TipoNodo arranjo[max];

  TipoNodo dados;

  /* Configura qua */

  /* Declarar um arranjo do tipo TipoNodo*/ 

  InicializaLLArr(IA);

  printf("IA %d\nFA %d\nIL %d\nFL %d\n",IA,FA,IL,FL);

  int x=0;

  while (Sucesso)
  {
    x++;
    printf("codigo: ");
    scanf("%d",&dados.codigo);
    if ( x % 3 == 0 )
    {
      if (InserirFimLLArr(arranjo, IA, FA, &IL, &FL, dados))
        imprime(arranjo, FL);
      else
        Sucesso = false;
    }else if ( x % 4 == 0 )
    {
      int K=0;
      printf("posicao para inserir: ");
      scanf("%d",&K); 
      if (InserirLLArrPosK(arranjo, IA, FA, &IL, &FL, K, dados))
        imprime(arranjo, FL);
      else
        Sucesso = false;
    }else
    {
      if (InserirIniLLArr(arranjo, IA, FA, &IL, &FL, dados))
        imprime(arranjo, FL);
      else
        Sucesso = false;
    }
  }

  return 0;

}
