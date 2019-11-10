#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/un.h>

int socket_id;
void sigint_handler(int signum);
void print_client_message(int client_socket);
void end_server(void);

int main ()
{
	unsigned short servidorPorta;
	struct sockaddr_in servidorAddr;

	servidorPorta = 8080;

	// Definindo o tratamento de SIGINT
	signal(SIGINT, sigint_handler);

	// Abrindo o socket local
	socket_id = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(socket_id < 0)
	{
		fprintf(stderr, "Erro na criacao do socket!\n");
		exit(0);
	}

	// Ligando o socket a porta "servidorPorta"
	memset(&servidorAddr, 0, sizeof(servidorAddr)); // Zerando a estrutura de dados
	servidorAddr.sin_family = AF_INET;
	servidorAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servidorAddr.sin_port = htons(servidorPorta);
	if(bind(socket_id, (struct sockaddr *) &servidorAddr, sizeof(servidorAddr)) < 0)
	{
		fprintf(stderr, "Erro na ligacao!\n");
		exit(0);
	}

	// Tornando o socket passivo (para virar um servidor)
	if(listen(socket_id, 10) < 0)
	{
		fprintf(stderr, "Erro!\n");
		exit(0);
	}

	while(1)
	{
		int socketCliente, mensagem;
		struct sockaddr_in clienteAddr;
		unsigned int clienteLength;

		// Aguardando a conexao de um cliente
		clienteLength = sizeof(clienteAddr);
		if((socketCliente = accept(socket_id, (struct sockaddr *) &clienteAddr, &clienteLength)) < 0)
			fprintf(stderr, "Falha no accept().\n");

		// Tratando comunicacao com o cliente
		read(socketCliente, &mensagem, 1);
		printf("%d\n", mensagem);
		if(mensagem == 10)
		{
			printf("Fechando o servidor\n");
		 	close(socketCliente);
			end_server();
		}
	}
	return 0;
}

void sigint_handler(int signum)
{
	fprintf(stderr, "\nRecebido o sinal CTRL+C... vamos desligar o servidor!\n");
	end_server();
}

void end_server(void)
{
	// Fechando o socket local
	close(socket_id);
	exit(0);
}
