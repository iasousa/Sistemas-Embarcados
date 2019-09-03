#include "num_caracs.h"

int Num_caracs (char *string)
{
  int numero = 0;

  while (string[numero] != '\0')
  {
    numero++;
  }

  return numero;
}
