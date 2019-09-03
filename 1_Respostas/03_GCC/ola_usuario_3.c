#include <stdio.h>

int main (int argc, char **argv)
{
  int i;

  printf("Olá ");

  for (i = 1; i < argc; i++)
  {
    if (i == (argc - 1))
    {
      printf("%s\n", argv[i]);
    } else{
      printf("%s ", argv[i]);
    }
  }

  printf("Numero de entradas = %d\n", argc);

  return 0;
}
