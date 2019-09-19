#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
  int fp, i;
  char string[10] = "Ola Mundo!";

  fp = open("ola_mundo.txt", O_WRONLY | O_CREAT, S_IRWXU);

  if(fp == -1)
  {
    printf("Erro na abertura do arquivo.\n");
    return(1);
  }

  write(fp, string, strlen(string));

  close(fp);

  return 0;
}
