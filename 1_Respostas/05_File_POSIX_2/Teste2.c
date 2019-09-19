#include <stdio.h>
#include <stdlib.h>
#include "bib_arqs.h"

int main()
{
  char *string;

  string = le_arq_texto("Eu.txt");
  printf("%s", string);

  free(string);

  return 0;
}
