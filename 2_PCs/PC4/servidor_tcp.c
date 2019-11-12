// Servidor Local
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

int main (int argc, char* const argv[])
{
	unsigned short servidorPorta;
	struct sockaddr_in servidorAddr;

	if (argc != 2)
	{
		printf("O programa deve ser executado com 1 argumento da seguinte forma:\n");
		printf("%s <Porta do Servidor>\n", argv[0]);
		exit(1);
	}
	servidorPorta = atoi(argv[1]);

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
		int socketCliente;
		struct sockaddr_in clienteAddr;
		unsigned int clienteLength;

		// Aguardando a conexao de um cliente
		clienteLength = sizeof(clienteAddr);
		if((socketCliente = accept(socket_id, (struct sockaddr *) &clienteAddr, &clienteLength)) < 0)
			fprintf(stderr, "Falha no accept().\n");

		fprintf(stderr, "Conexão do Cliente %s\n", inet_ntoa(clienteAddr.sin_addr));

		// Tratando comunicacao com o cliente
		print_client_message(socketCliente);

		// Fechando a conexao com o cliente
		close(socketCliente);
	}
	return 0;
}

void sigint_handler(int signum)
{
	fprintf(stderr, "\nDesligando o servidor...\n");
	end_server();
}

void print_client_message(int client_socket)
{
	int length;
	char* text;
	//fprintf(stderr, "\nMensagem enviada pelo cliente tem ");
	read(client_socket, &length, sizeof (length));
	//fprintf(stderr, "%d bytes.", length);
	text = (char*) malloc (length);
	read(client_socket, text, length);
	fprintf(stderr,"Mensagem = %s\n\n", text);
	if (!strcmp (text, "sair"))
	{
		free (text);
		fprintf(stderr, "Cliente pediu para o servidor fechar.\n");
		end_server();
	}
	free (text);
}

void end_server(void)
{
	// Fechando o socket local
	close(socket_id);
	exit(0);
}
