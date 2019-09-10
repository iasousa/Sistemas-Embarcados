#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int v_global = 0; // Variavel global para este exemplo
void Incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
}

int main()
{
  pid_t child_pid1 = fork();
  if(child_pid1 == 0)
  {
    Incrementa_Variavel_Global(getpid());
    exit(1);
  }

  pid_t child_pid2 = fork();
  if(child_pid2 == 0)
  {
    Incrementa_Variavel_Global(getpid());
    exit(1);
  }

  pid_t child_pid3 = fork();
  if(child_pid3 == 0)
  {
    Incrementa_Variavel_Global(getpid());
    exit(1);
  }

  return 0;
}
