#include <stdio.h>
#include <stdlib.h>

#define TAM_NOME 10

typedef struct
{
    char nome[TAM_NOME];
}GENERICO;

void preenche(GENERICO *tipo);

void imprime(GENERICO tipo);

char* formatar(int format_size);
