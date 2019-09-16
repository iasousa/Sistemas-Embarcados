#include <stdio.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  char arquivo[34];

  sprintf(arquivo, "%s.txt", argv[1]);

  if(!(fp = fopen(arquivo, "w")))
  {
    printf("Erro na abertura do arquivo\n");
    return 1;
  }

  fprintf(fp, "Nome: %s\n", argv[1]);
  fprintf(fp, "Idade: %s\n", argv[2]);
  fclose(fp);

  return 0;
}
