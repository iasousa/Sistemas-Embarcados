#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  int pid, fd[2], i;

  pipe(fd);

  pid = fork();
  if(pid == 0)
  {
    while(i != 10)
    {
      read(fd[0], &i, sizeof(int));
      printf("%d\n", i);
    }
    exit(1);
  } else{
    for(i = 1; i <= 10; i++)
    {
      write(fd[1], &i, sizeof(int));
      sleep(1);
    }
  }

  return 0;
}
