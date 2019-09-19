#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int fp;
  char arquivo[50];

  sprintf(arquivo, "%s.txt", argv[1]);

  fp = open(arquivo, O_WRONLY | O_CREAT, S_IRWXU);

  if(fp == -1)
  {
    printf("Erro na abertura do arquivo\n");
    return 1;
  }

  write(fp, "Nome: ", 6);
  write(fp, argv[1], strlen(argv[1]));
  write(fp, "\n", 1);
  write(fp, "Idade: ", 7);
  write(fp, argv[2], strlen(argv[2]));
  write(fp, "\n", 1);

  close(fp);

  return 0;
}
