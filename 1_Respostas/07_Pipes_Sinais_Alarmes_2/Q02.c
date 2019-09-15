#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  int pid, fd[2];
  char mensagem[100];

  pipe(fd);

  pid = fork();
  if(pid == 0)
  {
    sprintf(mensagem, "FILHO: Pai, qual é a verdadeira essência da sabedoria?");
    write(fd[1], mensagem, sizeof(mensagem));
    sleep(0.5);
    read(fd[0], mensagem, sizeof(mensagem));
    printf("%s\n", mensagem);
    sprintf(mensagem, "FILHO: Mas até uma criança de três anos sabe disso!");
    write(fd[1], mensagem, sizeof(mensagem));
    sleep(0.5);
    read(fd[0], mensagem, sizeof(mensagem));
    printf("%s\n", mensagem);
    exit(1);
  } else{
    read(fd[0], mensagem, sizeof(mensagem));
    printf("%s\n", mensagem);
    sprintf(mensagem, "PAI: Não façais nada violento, praticai somente aquilo que é justo e equilibrado.");
    write(fd[1], mensagem, sizeof(mensagem));
    sleep(0.5);
    read(fd[0], mensagem, sizeof(mensagem));
    printf("%s\n", mensagem);
    sprintf(mensagem, "PAI: Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...");
    write(fd[1], mensagem, sizeof(mensagem));
    wait(NULL);
  }

  return 0;
}
