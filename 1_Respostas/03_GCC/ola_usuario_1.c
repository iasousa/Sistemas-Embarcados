#include <stdio.h>

int main ()
{
  char nome[30];

  printf("Digite o seu nome:\n");
  scanf("%s", nome);
  printf("Olá %s\n", nome);

  return 0;
}
