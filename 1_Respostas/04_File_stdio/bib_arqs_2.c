#include <stdio.h>
#include <stdlib.h>
#include "bib_arqs.h"

int main()
{
  FILE *fp;
  char *string;

  string = le_arq_texto("ola.txt");

  printf("%s", string);

  free(string);

  return 0;
}
