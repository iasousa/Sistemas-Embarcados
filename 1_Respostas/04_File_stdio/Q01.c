#include <stdio.h>

int main()
{
  FILE *fp;
  char string[10] = "Ola mundo!";
  int i;

  fp = fopen("ola_mundo.txt", "w");

  if(!fp)
  {
    printf("Erro na abertura do arquivo.\n");
    return 1;
  }

  for(i = 0; string[i]; i++)
  {
    putc(string[i], fp);
  }

  fclose(fp);

  return 0;
}
