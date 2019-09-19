#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "bib_arqs.h"

int tam_arq_texto(char *nome_arquivo)
{
  struct stat st;
  int tamanho;

  stat(nome_arquivo, &st);
  tamanho = st.st_size;

  return tamanho;
}

char* le_arq_texto(char *nome_arquivo)
{
  int fp;
  char *string;

  string = (char *)malloc(sizeof(char)*tam_arq_texto(nome_arquivo));

  fp = open(nome_arquivo, O_RDONLY);

  if(fp == -1)
  {
    printf("Erro na abertura do arquivo.\n");
    exit(1);
  }

  read(fp, string, (sizeof(char)*tam_arq_texto(nome_arquivo)));

  close(fp);

  return string;
}
