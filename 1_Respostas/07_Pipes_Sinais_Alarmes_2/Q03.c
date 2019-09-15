#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  int pid[2], fd[2];
  char mensagem[100];

  pipe(fd);

  pid[0] = fork();
  if(pid[0] == 0)
  {
    sprintf(mensagem, "FILHO1: Quando o vento passa, é a bandeira que se move.");
    write(fd[1], mensagem, sizeof(mensagem));
    exit(1);
  } else{
    read(fd[0], mensagem, sizeof(mensagem));
    printf("%s\n", mensagem);
  }

  pid[1] = fork();
  if(pid[1] == 0)
  {
    sprintf(mensagem, "FILHO2: Não, é o vento que se move.");
    write(fd[1], mensagem, sizeof(mensagem));
    sleep(0.5);
    read(fd[0], mensagem, sizeof(mensagem));
    printf("%s\n", mensagem);
    exit(1);
  } else{
    read(fd[0], mensagem, sizeof(mensagem));
    printf("%s\n", mensagem);
    sprintf(mensagem, "PAI: Os dois se enganam. É a mente dos senhores que se move.");
    write(fd[1], mensagem, sizeof(mensagem));
    wait(NULL);
  }

  return 0;
}
