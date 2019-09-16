#include <stdio.h>
#include <stdlib.h>
#include "bib_arqs.h"

int main(int argc, char *argv[])
{
  char *string, c;
  int i, j = 0, contador = 0;

  string = le_arq_texto(argv[2]);

  for(i = 0; (c = getc(fp)) != EOF; i++)
  {
    while((c = getc(fp)) != ' ')
    {
      sprintf(palavras[i], "%c", c);
    }
    j++;
  }

  for(i = 0; i == j; i++)
  {
    if(palavras[i] == argv[1])
    {
      contador++;
    }
  }

  fclose(fp);
  printf("'%s' ocorre %d vezes no arquivo '%s'.\n", argv[1], contador, argv[2]);

  return 0;
}
