1. Como se utiliza o comando `ps` para:

(a) Mostrar todos os processos rodando na máquina?
```bash
	ps -aux
```
(b) Mostrar os processos de um usuário?
```bash
	ps -u
```
(c) Ordenar todos os processos de acordo com o uso da CPU?
```bash
	ps aux | sort -rk 3,3
```
(d) Mostrar a quanto tempo cada processo está rodando?
```bash
	ps -eo pid,comm,lstart,etime,time,args
```
2. De onde vem o nome `fork()`?
```bash
	Um dos significados da palavra fork em inglês é bifurcação, e isso faz sentido com o que a função faz, pois ela cria um processo (processo filho) igual ao processo original (processo pai), como se fosse um processo de divisão em duas partes idênticas.
```
3. Quais são as vantagens e desvantagens em utilizar:

(a) `system()`?
```bash
	Vantagens: É uma função simples que utiliza recursos do shell para criar um novo processo.
	Desvantagens: É suscetível a falhas de execução por depender muito do sistema operacional utilizado. Um processo que funciona em UNIX pode não funcionar no Windows, por exemplo.
```
(b) `fork()` e `exec()`?
```bash
	Vantagens: São funções menos suscetíveis a falhas em relação ao system() e dão um melhor entendimento sobre processos.
	Desvantagens: São mais difíceis de utilizar em relação ao system().
```
4. É possível utilizar o `exec()` sem executar o `fork()` antes?
```bash
	Sim. Nesse caso, o PID do processo continua o mesmo, porém, toda a funcionalidade do programa original (texto, variáveis e outras informações) é substituída pela funcionalidade do programa chamado na função exec().
```
5. Quais são as características básicas das seguintes funções:

(a) `execp()`?
```bash
	Funções que contêm a letra 'p' em seus nomes aceitam que o nome ou procura do programa esteja no diretório atual (current path). Funções que não possuem o 'p' devem conter o caminho completo do programa a ser executado.
```
(b) `execv()`?
```bash
	Funções que contêm a letra 'v' em seus nomes aceitam que a lista de argumentos do novo programa seja nula.
```
(c) `exece()`?
```bash
	Funções que contêm a letra 'e' em seus nomes aceitam um argumento adicional.
```
(d) `execvp()`?
```bash
	Permite que a lista de argumentos do novo programa seja nula e aceitam que o nome ou procura do programa esteja no diretório atual.
```
(e) `execve()`?
```bash
	Permite que a lista de argumentos do novo programa seja nula e aceitam um argumento adicional.
```
(f) `execle()`?
```bash
	Permite especificar o ambiente (enviroment) do programa executado pelo argumento 'envp'.
```
