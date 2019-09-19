#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
  int fp;
  char nome[50], arquivo[50], idade[10];

  printf("Digite o seu nome: ");
  gets(nome);

  printf("Digite a sua idade: ");
  gets(idade);

  sprintf(arquivo, "%s.txt", nome);

  fp = open(arquivo, O_WRONLY | O_CREAT, S_IRWXU);

  if(fp == -1)
  {
    printf("Erro na abertura do arquivo.\n");
    return 1;
  }

  write(fp, "Nome: ", 6);
  write(fp, nome, strlen(nome));
  write(fp, "\n", 1);
  write(fp, "Idade: ", 7);
  write(fp, idade, strlen(idade));
  write(fp, "\n", 1);

  close(fp);

  return 0;
}
