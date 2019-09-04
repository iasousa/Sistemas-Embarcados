1. Considerando a biblioteca-padrão da linguagem C, responda:

(a) Quais são as funções (e seus protótipos) para abrir e fechar arquivos?
```bash
	Abrir arquivos: FILE *fopen(char *nome_do_arquivo, char *modo);
	Fechar arquivos: int fclose(FILE *ponteiro_para_arquivo);
```
(b) Quais são as funções (e seus protótipos) para escrever em arquivos?
```bash
	int putc(int ch, FILE *fp);
	char fputs(char *str, FILE *fp);
	unsigned fwrite(void *buffer,int numero_de_bytes,int count,FILE *fp);
	int fprintf(FILE *stream, const char *format, ... );
```
(c) Quais são as funções (e seus protótipos) para ler arquivos?
```bash
	int getc(FILE *fp);
	char *fgets(char *str, int tamanho, FILE *fp);
	unsigned fread(void *buffer, int numero_de_bytes, int count, FILE *fp);
	int fscanf(FILE *stream, const char *format, ... );
```
(d) Quais são as funções (e seus protótipos) para reposicionar um ponteiro para arquivo?
```bash
	int fseek(FILE * stream, long int offset, int origin);
	void rewind(FILE * stream);
```
(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?
```bash
	#include <stdio.h>
```
2. O que é a norma POSIX?
```bash
	POSIX é uma família de normas especificadas pela IEEE com o objetivo de garantir compatibilidade entre sistemas operacionais. A POSIX define APIs (interfaces de programação de aplicações), linhas de comando shell e interfaces utilitárias para compatibilidade de software com variantes de Unix e outros sistemas operacionais. 
```
3. Considerando a norma POSIX, responda:

(a) Quais são as funções (e seus protótipos) para abrir e fechar arquivos?
```bash
	Abrir arquivos: int open(const char *path, int oflag, ...);
	Fechar arquivos: int close(int fildes);
```
(b) Quais são as funções (e seus protótipos) para escrever em arquivos?
```bash
	ssize_t write(int fildes, const void *buf, size_t nbyte);
```
(c) Quais são as funções (e seus protótipos) para ler arquivos?
```bash
	ssize_t read(int fildes, void *buf, size_t nbyte);
```
(d) Quais são as funções (e seus protótipos) para reposicionar um ponteiro para arquivo?
```bash
	off_t lseek(int fd, off_t offset, int whence);
```
(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?
```bash
	#include <fnctl.h> para a função open()
	#include <unistd.h> para as funções close(), write(), read() e lseek()
```
