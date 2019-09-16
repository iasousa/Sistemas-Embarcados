#include <stdio.h>

int main()
{
  FILE *fp;
  char nome[30], arquivo[34];
  int idade, i;

  printf("Digite seu nome: ");
  fgets(nome, 29, stdin);

  printf("Digite sua idade: ");
  scanf("%d", &idade);

  for(i = 0; nome[i]; i++)
  {
    if(nome[i] == '\n')
    {
      nome[i] = 0;
    }
  }

  sprintf(arquivo, "%s.txt", nome);

  if(!(fp = fopen(arquivo, "w")))
  {
    printf("Erro na abertura do arquivo\n");
    return 1;
  }

  fprintf(fp, "Nome: %s\n", nome);
  fprintf(fp, "Idade: %d\n", idade);
  fclose(fp);

  return 0;
}
