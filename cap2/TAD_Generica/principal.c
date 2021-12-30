//gcc -o executavel principal.c implementacao.c
//or
//make

#include<stdio.h>
#include "interface.h"

int main(void) {

    GENERICO tipo_generico;

    preenche(&tipo_generico);

    printf("Main genérica\n");

    imprime(tipo_generico);

    return 0;
}
