# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h> 
# include <regex.h> 
# include <string.h> 
# include "generica.h"

/* Valida data */
int valida_data(int dia, int mes, int ano, Data *d) {

  int tudo_certo = 1;
  
  if ((( mes == 4 || mes == 6 || mes == 9 || mes == 11 ) & (dia > 0 && dia < 31)) || (( mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12 ) & (dia > 0 && dia < 32)) || (( mes == 2 && anoBissexto(ano) == 0 ) && (dia > 0 && dia < 30)) || (( mes == 2 && anoBissexto(ano) == 1 ) && (dia > 0 && dia < 29)) )
    tudo_certo = 0;
    
  if (tudo_certo == 0)
  {
    d->mes = mes;
    d->dia = dia;
    d->ano = ano;
  }
  return tudo_certo;
}

int anoBissexto ( int ano ) {
	int bissexto;
 
	if (ano % 400 == 0) 
		bissexto = 0;		
	else if ((ano % 4 == 0) && (ano % 100 != 0)) 
		bissexto = 0;		
	else 
		bissexto = 1;
	
 
  return bissexto;
}
/* Imprime data */
void imprime_data(Data d) {
  printf("%d/%d/%d\n", d.dia, d.mes, d.ano);
}

/* Calcula diferença de dias */
void calcula_data(Data d1, Data d2) {
  int dia,mes,ano;
  ano = abs(d1.ano-d2.ano) * 365;
  mes = ano + abs(d1.mes-d2.mes) * 30;
  dia = mes + abs(d1.dia-d2.dia);
 
  printf("%d dias de diferença\n",dia); 
  
}

/* Calcula dia da Páscoa */
void calcula_pascoa()
{
  int c; 
  int n;
  int k;
  int i;
  int j;
  int l;
  int m;
  int d;
  int a;
  printf("Páscoa do ano:");scanf("%d",&a);
  c = a/100;
  n = a - (19*(a/19));
  k = (c - 17)/25;
  i = c - c/4 - ((c-k)/3) +(19*n) + 15;
  i = i - (30*(i/30));
  i = i - ((i/28)*(1-(i/28))*(29/(i+1))*((21-n)/11));
  j = a + a/4 + i + 2 -c + c/4;
  j = j - (7*(j/7));
  l = i - j;
  m = 3 + ((l+40)/44);
  d = l + 28 - (31*(m/4));
  printf("Páscoa do ano %d acontece dia %d/%d\n",a,d,m);
}
int converte(char *stringData, Data *d)
{
  int i=0,j=0,h=0,v,tam=0,dados[3];
  char acum[11],final[5],ch; 

  if (validaFormatoString(stringData) == 0 ) 
  {
    tam = strlen(stringData);
    tam++;
    for ( i;i<tam+1;i++ )
    {
      if ( i != tam )
      {
        ch = stringData[i];
        if ( ch != '/' && ch != '-' )
        {
          acum[h] = ch;
          h++;
          continue;
        }
      }

      v = 0;

      do 
      {
        final[v] = acum[v];
        v++;
      }while ( v < h );

      v--;

      final[v+1] = '\0';

      dados[j] = atoi(final);
      j++;
      h = 0;
    }
  }

  else
  {
    fprintf(stderr, "OCORREU UMA CATASTROFE, SAIA DA FRENTE DO COMPUTADOR AGORA\n");
    exit(1);
  }

  if ( valida_data(dados[0],dados[1],dados[2],d) == 0 )
  {
    d->dia = dados[0];
    d->mes = dados[1];
    d->ano = dados[2];
    return 0;
  }
  else
    return 1;
  
    
}

int validaFormatoString(char *stringData)
{
  /* Aloca espaço para a estrutura do tipo regex_t */
  regex_t reg;

  /* compila a ER, em caso de erro, a função retorna 
   * diferente de zero */
  if (regcomp(&reg, "^([0-9]{1,2}/[0-9]{1,2}/[0-9]{4}|[0-9]{1,2}-[0-9]{1,2}-[0-9]{4})$" , REG_EXTENDED|REG_NOSUB) != 0 ) {
    fprintf(stderr, "OCORREU UMA CATASTROFE, SAIA DA FRENTE DO COMPUTADOR AGORA\n");
    exit(1);
  }

  /* tenta casar a ER compilada (&reg) com a entrada stringData
   * se a função regexec retornar 0 casou, caso contrário não */
  if ((regexec(&reg, stringData , 0, (regmatch_t *)NULL, 0)) == 0)
    return 0; // casou
  else
    return 1; // não casou

}

int somaDias(Data d, int dias)
{
  int meses[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  int total=0;

  for(int mes = 1; mes < d.mes; mes++)
    total += meses[mes-1];

  if (anoBissexto(d.ano) == 0)
    total++;

  total += d.dia;
  total += dias;
    
  printf("dias até aqui %d\n", total);


  return total;
  
}


