#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  int pid, fd[2];
  char nome[50];

  pipe(fd);

  pid = fork();
  if(pid == 0)
  {
    printf("Digite o seu nome:\n");
    scanf("%s", nome);
    write(fd[1], nome, sizeof(nome));
    exit(1);
  } else{
    read(fd[0], nome, sizeof(nome));
    printf("Nome: %s\n", nome);
  }

  return 0;
}
