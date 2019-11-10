#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <unistd.h>

int main (int argc, char* const argv[])
{
	int socket_id;
	struct sockaddr_in servidorAddr;
	unsigned short servidorPorta;
	char *IP_Servidor;
	char mensagem[100];

	IP_Servidor = "127.0.0.1";
	servidorPorta = 8080;

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
	strcpy(mensagem, "CLIENTE: Pai, qual é a verdadeira essência da sabedoria?\n");
	printf("%s", mensagem);
	write(socket_id, mensagem, sizeof(mensagem));
	read(socket_id, mensagem, sizeof(mensagem));
	printf("%s", mensagem);
	strcpy(mensagem, "CLIENTE: Mas até uma criança de três anos sabe disso!\n");
	printf("%s", mensagem);
	write(socket_id, mensagem, sizeof(mensagem));
	read(socket_id, mensagem, sizeof(mensagem));
	printf("%s", mensagem);

	// Fechando o socket local
	close(socket_id);
	return 0;
}
