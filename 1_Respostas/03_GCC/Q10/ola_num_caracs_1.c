#include <stdio.h>
#include "num_caracs.h"

int main (int argc, char **argv)
{
  int tamanho[argc - 1];
  int i;

  for (i = 0; i < argc; i++)
  {
    tamanho[i] = Num_caracs(argv[i]);
    printf("Argumento: %s / Numero de caracteres: %d\n", argv[i], tamanho[i]);
  }

  return 0;
}
