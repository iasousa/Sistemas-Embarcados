#include <stdio.h>
#include <stdlib.h>
#include "bib_arqs.h"

int tam_arq_texto(char *nome_arquivo)
{
  FILE *fp;
  int tamanho;

  if(!(fp = fopen(nome_arquivo, "r")))
  {
      printf("Erro na leitura do arquivo.\n");
      exit(1);
  }

  fseek(fp, SEEK_SET, SEEK_END);
  tamanho = ftell(fp);

  fclose(fp);

  return tamanho;
}

char* le_arq_texto(char *nome_arquivo)
{
  FILE *fp;
  char *string;

  string = (char *)malloc(sizeof(char)*tam_arq_texto(nome_arquivo));

  if(!(fp = fopen(nome_arquivo, "r")))
  {
    printf("Erro na abertura do arquivo.\n");
    exit(1);
  }

  fgets(string, (sizeof(char)*tam_arq_texto(nome_arquivo)), fp);

  fclose(fp);

  return string;
}
