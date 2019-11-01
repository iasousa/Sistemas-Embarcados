#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>

#define ENTRADA 7

int main()
{
  FILE *fp;
  int i = 0;
  char placa[10][7], string[7], zerar[7] = "000000", c;

  wiringPiSetup();
  pinMode(ENTRADA, INPUT);
  while(1)
  {
    for(i = 0; i < 10; i++)
    {
      strcpy(placa[i], zerar);
    }
    
    i = 0;
    printf("Pressione o botao\n");
    while(digitalRead(ENTRADA) > 0);
    system("fswebcam -r 640x480 --jpeg 100 -D 1 teste.jpg");
    system("alpr -c us teste.jpg > placa.txt");
  
    fp = fopen("placa.txt", "r");
    
    for(c = getc(fp); !feof(fp); c = getc(fp))
    {
      if(c == '-')
      {
        fseek(fp, 1, SEEK_CUR);
        fgets(placa[i], 7, fp);
        printf("%s\n", placa[i]);
        i++;
      }
    }
  
    fclose(fp); 
  
    fp = fopen("request.sql", "w");

    if(!fp)
    {
      printf("Erro na abertura do arquivo.\n");
      exit(0);
    }

    fprintf(fp, "SELECT V.placa FROM veiculos AS V\n"
                "WHERE V.placa = '%s';\n", placa[0]);

    fclose(fp);

    system("mysql estacionamento < request.sql > answer.txt");

    fp = fopen("answer.txt", "r");
    fseek(fp, 6, SEEK_SET);

    fgets(string, 7, fp);
    fclose(fp);

    if(strcmp(placa[0], string) == 0)
    {
      printf("Placa no banco de dados = %s\n", string);
      printf("ABRIR\n");
    } else {
      printf("NAO ABRIR\n");
    }
  }
  
  return 0;
}
