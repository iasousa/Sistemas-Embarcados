#include <stdio.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  char c;

  if(!(fp = fopen(argv[1], "r")))
  {
    printf("Erro na leitura do arquivo\n");
    return 1;
  }

  while((c = getc(fp)) != EOF)
  {
    printf("%c", c);
  }

  fclose(fp);

  return 0;
}
