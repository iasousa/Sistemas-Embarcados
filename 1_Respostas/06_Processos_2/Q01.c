#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  printf("Processo Pai. PID = %d\n", (int)getpid());

  pid_t child_pid1 = fork();
  if(child_pid1 == 0)
  {
    printf("Processo Filho 1. PID = %d\n", (int)getpid());
    exit(1);
  }

  pid_t child_pid2 = fork();
  if(child_pid2 == 0)
  {
    printf("Processo Filho 2. PID = %d\n", (int)getpid());
    exit(1);
  }

  pid_t child_pid3 = fork();
  if(child_pid3 == 0)
  {
    printf("Processo Filho 3. PID = %d\n", (int)getpid());
    exit(1);
  }

  return 0;
}
