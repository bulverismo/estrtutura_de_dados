#include "interface.h"

void preenche(GENERICO *tipo)
{
    printf("Digite um nomes: ");
    scanf("%s",tipo->nome);
}

void imprime(GENERICO tipo)
{
    puts(tipo.nome);
}

char* formatar(int format_size) {
    char *number = malloc (sizeof (char) * 5);;
    sprintf(number, "%%%d[^\\n]%%c", format_size);

    puts(number);

    return number;
}
