1. Quantos pipes serão criados após as linhas de código a seguir? Por quê?

(a)
```C
int pid;
int fd[2];
pipe(fd);
pid = fork();
```
	Será criado 1 pipe que poderá ser utilizado para a comunicação entre os processos pai e filho. A primitiva pipe precisa de dois descritores de arquivo (fd[0] para leitura e fd[1] para escrita). Como a função é chamada uma vez antes do fork, será criado apenas um pipe.

(b)
```C
int pid;
int fd[2];
pid = fork();
pipe(fd);
```
	Serão criados 2 pipes, um para o processo pai e outro para o filho, porém, os processos não poderão se comunicar por esses pipes. Isso ocorre porque a função pipe foi chamada depois do fork.

2. Apresente mais cinco sinais importantes do ambiente Unix, além do `SIGSEGV`, `SIGUSR1`, `SIGUSR2`, `SIGALRM` e `SIGINT`. Quais são suas características e utilidades?
```
	1 - SIGHUP(Corte): Sinal emitido aos processos associados a um terminal quando este se desconecta. Este sinal também é emitido a cada processo de um grupo quando o chefe termina sua execução.
	2 - SIGQUIT(Abandono): Sinal emitido aos processos do terminal quando as teclas de abandono (QUIT ou CTRL+D) do teclado são acionadas.
	3 - SIGILL(Instrução ilegal): Sinal emitido quando uma instrução ilegal é detectada.
	4 - SIGIOT: Problemas de instrução de entrada/saída. Sinal emitido em caso de problemas de hardware.
	5 - SIGEMT: Problemas de instrução no emulador. Sinal emitido em caso de erro material dependente da implementação.
```
3. Considere o código a seguir:

```C
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void tratamento_alarme(int sig)
{
	system("date");
	alarm(1);
}

int main()
{
	signal(SIGALRM, tratamento_alarme);
	alarm(1);
	printf("Aperte CTRL+C para acabar:\n");
	while(1);
	return 0;
}
```

Sabendo que a função `alarm()` tem como entrada a quantidade de segundos para terminar a contagem, quão precisos são os alarmes criados neste código? De onde vem a imprecisão? Este é um método confiável para desenvolver aplicações em tempo real?
	
	A função alarm() é executada através de um processo. Dessa forma, ela só é razoavelmente precisa quando executada em sistemas com alto poder de processamento, assim como os computadores que apresentam processadores com 4 ou mais núcleos operando na faixa de GHz. Isso ocorre porque o sistema operacional tem que cuidar de vários processos ao mesmo tempo e não há uma forma de garantir a execução de um processo específico em tempo real. A execução do alarm também depende da carga do processador, ou seja, caso o processador esteja sendo muito utilizado em processos mais pesados, a função alarm atrasaria ainda mais sua execução.

