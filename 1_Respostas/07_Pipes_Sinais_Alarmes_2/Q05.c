#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void alarme(int sinal)
{
  system("ps");
  alarm(1);
}

void interrupcao(int sinal)
{
  printf("Processo terminado!\n");
  exit(1);
}

int main()
{
  signal(SIGALRM, alarme);
  signal(SIGINT, interrupcao);

  alarm(1);
  while(1);

  return 0;
}
