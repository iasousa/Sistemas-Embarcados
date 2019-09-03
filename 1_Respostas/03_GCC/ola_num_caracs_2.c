#include <stdio.h>
#include "num_caracs.h"

int main(int argc, char **argv)
{
  int i, soma = 0;

  for(i = 0; i < argc; i++)
  {
    soma += Num_caracs(argv[i]);
  }

  printf("Total de caracteres de entrada: %d\n", soma);

  return 0;
}
