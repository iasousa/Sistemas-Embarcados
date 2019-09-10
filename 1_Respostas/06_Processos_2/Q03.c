#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  int i;
  //pid_t child_pid;

  printf("Processo Pai. PID = %d\n", (int)getpid());

  for(i = 1; i < argc; i++)
  {
    pid_t child_pid = fork();

    if(child_pid == 0)
    {
      printf("Processo Filho %d. PID = %d\n", i, (int)getpid());
      execlp(argv[i], argv[i], NULL);
      exit(1);
    }
  }

  wait();

  return 0;
}
