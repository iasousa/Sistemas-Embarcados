Para todas as questões, compile-as com o gcc e execute-as via terminal.

1. Crie um "Olá mundo!" em C.
	No arquivo Ola_Mundo.c

2. Crie um código em C que pergunta ao usuário o seu nome, e imprime no terminal "Ola " e o nome do usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':

```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu
$ Ola Eu
```
	No arquivo ola_usuario_1.c

3. Apresente os comportamentos do código anterior nos seguintes casos:

(a) Se o usuário insere mais de um nome.
```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu Mesmo
```
	Aparece apenas o primeiro nome, no caso, o terminal mostra a mensagem **Olá Eu**, ignorando o "Mesmo".

(b) Se o usuário insere mais de um nome entre aspas duplas. Por exemplo:
```bash
$ ./ola_usuario_1
$ Digite o seu nome: "Eu Mesmo"
```
	Aparece o nome "Eu" junto com as primeiras aspas da seguinte maneira: **Olá "Eu**. Novamente, o "Mesmo" é ignorado.

(c) Se é usado um pipe. Por exemplo:
```bash
$ echo Eu | ./ola_usuario_1
```
	É entendido que o argumento a ser passado para o programa será o nome "Eu" e, assim, aparece a mensagem **Olá Eu** sem que o usuário precise digitar o nome novamente.

(d) Se é usado um pipe com mais de um nome. Por exemplo:
```bash
$ echo Eu Mesmo | ./ola_usuario_1
```
	Aparece apenas o primeiro nome, no caso, o terminal mostra a mensagem **Olá Eu**, ignorando o "Mesmo", assim como no item a. Porém, o usuário não precisa digitar o nome novamente ao executar o programa.

(e) Se é usado um pipe com mais de um nome entre aspas duplas. Por exemplo:
```bash
$ echo "Eu Mesmo" | ./ola_usuario_1
```
	Aparece apenas o primeiro nome, no caso, o terminal mostra a mensagem **Olá Eu**, ignorando o "Mesmo", assim como no item a. Porém, o usuário não precisa digitar o nome novamente ao executar o programa.

(f) Se é usado o redirecionamento de arquivo. Por exemplo:
```bash
$ echo Ola mundo cruel! > ola.txt
$ ./ola_usuario_1 < ola.txt >
```
	É entendido que o argumento a ser passado para o programa será o nome "Ola", o qual está escrito no arquivo ola.txt. O programa ignora as palavras "mundo cruel!" e aparece a mensagem **Olá Ola**, como se Ola fosse o nome a ser passado. Novamente, o usuário não precisa digitar o nome ao executar o programa, pois o argumento é passado pelo arquivo de texto ola.txt.

4. Crie um código em C que recebe o nome do usuário como um argumento de entrada (usando as variáveis argc e *argv[]), e imprime no terminal "Ola " e o nome do usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':

```bash
$ ./ola_usuario_2 Eu
$ Ola Eu
```
	No arquivo ola_usuario_2.c

5. Apresente os comportamentos do código anterior nos seguintes casos:

(a) Se o usuário insere mais de um nome.
```bash
$ ./ola_usuario_2 Eu Mesmo
```
	Aparece a mensagem **Olá Eu Mesmo**. Diferente do programa "ola_usuario_1" da questão 2, dessa vez o "Mesmo" não é ignorado.

(b) Se o usuário insere mais de um nome entre aspas duplas. Por exemplo:
```bash
$ ./ola_usuario_2 "Eu Mesmo"
```
	Aparece a mensagem **Olá Eu Mesmo**, assim como no item a. Não aparecem as aspas.

(c) Se é usado um pipe. Por exemplo:
```bash
$ echo Eu | ./ola_usuario_2
```
	Aparece apenas a mensagem **Olá**, como se nenhum argumento fosse passado para o programa.

(d) Se é usado um pipe com mais de um nome. Por exemplo:
```bash
$ echo Eu Mesmo | ./ola_usuario_2
```
	Ocorre o mesmo do item c: aparece apenas a mensagem **Olá**.

(e) Se é usado um pipe com mais de um nome entre aspas duplas. Por exemplo:
```bash
$ echo Eu Mesmo | ./ola_usuario_2
```
	Ocorre o mesmo dos itens c e d: aparece apenas a mensagem **Olá**.

(f) Se é usado o redirecionamento de arquivo. Por exemplo:
```bash
$ echo Ola mundo cruel! > ola.txt
$ ./ola_usuario_2 < ola.txt >
```
	Ocorre o mesmo dos itens c, d, e: aparece apenas a mensagem **Olá**.

6. Crie um código em C que faz o mesmo que o código da questão 4, e em seguida imprime no terminal quantos valores de entrada foram fornecidos pelo usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_3':

```bash
$ ./ola_usuario_3 Eu
$ Ola Eu
$ Numero de entradas = 2
```
	No arquivo ola_usuario_3.c

7. Crie um código em C que imprime todos os argumentos de entrada fornecidos pelo usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_argumentos':

```bash
$ ./ola_argumentos Eu Mesmo e Minha Pessoa
$ Argumentos: Eu Mesmo e Minha Pessoa
```
	No arquivo ola_argumentos.c

8. Crie uma função que retorna a quantidade de caracteres em uma string, usando o seguinte protótipo:
`int Num_Caracs(char *string);` Salve-a em um arquivo separado chamado 'num_caracs.c'. Salve o protótipo em um arquivo chamado 'num_caracs.h'. Compile 'num_caracs.c' para gerar o objeto 'num_caracs.o'.
	gcc -c num_caracs.c

9. Re-utilize o objeto criado na questão 8 para criar um código que imprime cada argumento de entrada e a quantidade de caracteres de cada um desses argumentos. Por exemplo, considerando que o código criado recebeu o nome de 'ola_num_caracs_1':

```bash
$ ./ola_num_caracs_1 Eu Mesmo
$ Argumento: ./ola_num_caracs_1 / Numero de caracteres: 18
$ Argumento: Eu / Numero de caracteres: 2
$ Argumento: Mesmo / Numero de caracteres: 5
```
	gcc -o ola_num_caracs_1 ola_num_caracs_1.c num_caracs.o

10. Crie um Makefile para a questão anterior.
	Na pasta Q10.

11. Re-utilize o objeto criado na questão 8 para criar um código que imprime o total de caracteres nos argumentos de entrada. Por exemplo, considerando que o código criado recebeu o nome de 'ola_num_caracs_2':

```bash
$ ./ola_num_caracs_2 Eu Mesmo
$ Total de caracteres de entrada: 25
```
	gcc -o ola_num_caracs_2 ola_num_caracs_2.c num_caracs.o

12. Crie um Makefile para a questão anterior.
	Na pasta Q12.
