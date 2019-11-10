#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <unistd.h>

int main ()
{
	int socket_id;
	struct sockaddr_in servidorAddr;
	unsigned short servidorPorta;
	char *IP_Servidor;
	int mensagem = 0;

	IP_Servidor = "127.0.0.1";
	servidorPorta = 8080;

	for(mensagem = 1; mensagem != 11; mensagem++)
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
		
		// Mandando mensagem ao servidor
		write(socket_id, &mensagem, 1);
		usleep(1000000);
		close(socket_id);
	}

	return 0;
}
