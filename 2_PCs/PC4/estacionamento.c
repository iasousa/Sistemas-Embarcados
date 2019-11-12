#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <unistd.h>
#include <signal.h>

#define ENTRADA 7

int main(int argc, char* argv[])
{
  FILE *fp;
  int i = 0;
  char placa[10][8], string[8], zerar[8] = "0000000", c;
  int socket_id;
	struct sockaddr_in servidorAddr;
	int length;
	unsigned short servidorPorta;
	char *IP_Servidor;
	char *mensagem;

  wiringPiSetup();
  pinMode(ENTRADA, INPUT);
  
  if(argc != 3)
  {
    printf("O programa deve ser executado com 2 argumentos da seguinte forma:\n");
    printf("%s <IP do Servidor> <Porta do Servidor>\n", argv[0]);
    exit(1);
  }
  IP_Servidor = argv[1];
	servidorPorta = atoi(argv[2]);
  
  while(1)
  {
    // Abrindo o socket para o cliente
    socket_id = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(socket_id < 0)
    {
      fprintf(stderr, "Erro na criacao do socket!\n");
      exit(0);
    }
    // Conectando o socket ao IP "IP_Servidor" pela porta "servidorPorta"
    memset(&servidorAddr, 0, sizeof(servidorAddr)); // Zerando a estrutura de dados
    servidorAddr.sin_family = AF_INET;
    servidorAddr.sin_addr.s_addr = inet_addr(IP_Servidor);
    servidorAddr.sin_port = htons(servidorPorta);
    if(connect(socket_id, (struct sockaddr *) &servidorAddr, 
							sizeof(servidorAddr)) < 0)
    {
      fprintf(stderr, "Erro na conexao!\n");
      exit(0);
    }
    
    for(i = 0; i < 10; i++)
    {
      strcpy(placa[i], zerar);
    }
    
    i = 0;
    printf("Pressione o botao\n");
    while(digitalRead(ENTRADA) > 0);
    system("fswebcam -r 640x480 --jpeg 100 -D 1 teste.jpg");
    system("alpr -c br teste.jpg > placa.txt");
  
    fp = fopen("placa.txt", "r");
    
    for(c = getc(fp); !feof(fp); c = getc(fp))
    {
      if(c == '-')
      {
        fseek(fp, 1, SEEK_CUR);
        fgets(placa[i], 8, fp);
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

    fgets(string, 8, fp);
    fclose(fp);

    if(strcmp(placa[0], string) == 0)
    {
      printf("Placa no banco de dados = %s\n", string);
      printf("ABRIR\n");
      mensagem = "ABRIR";
    } else {
      printf("NAO ABRIR\n");
      mensagem = "NAO ABRIR";
    }
    
    length = strlen(mensagem) + 1;
    write(socket_id, &length, sizeof(length));
    write(socket_id, mensagem, length);
    close(socket_id);
  }
  
  return 0;
}
