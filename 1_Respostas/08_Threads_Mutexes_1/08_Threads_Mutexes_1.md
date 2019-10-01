1. Quais são as vantagens e desvantagens em utilizar:

(a) fork?

	A função fork gera processos-filhos, os quais podem ser vistos como novos ambientes com lugares protegidos na memória. É possível realizar comunicação entre processos-filhos e processo pai por meio de pipes e não há compartilhamento de memória (variáveis) entre processos-filhos, assim como não há comunicação entre eles.

(b) threads?

	Threads são executadas em processos (aplicações), sendo que uma aplicação pode rodar várias threads. As threads compartilham memória, apresentando as mesmas variáveis e, dessa forma, é mais fácil realizar comunicação entre elas. O ponto negativo disso é que há risco de corrupção de dados, pois eles podem ser utilizados em várias threads diferentes.

2. Quantas threads serão criadas após as linhas de código a seguir? Quantas coexistirão? Por quê?

(a)

```C
void* funcao_thread_1(void *arg);
void* funcao_thread_2(void *arg);

int main (int argc, char** argv)
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, funcao_thread_1, NULL);
	pthread_create(&t2, NULL, funcao_thread_2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
```
	Serão criadas 2 threads e as 2 coexistirão até o fim do código.

(b)
```C
void* funcao_thread_1(void *arg);
void* funcao_thread_2(void *arg);

int main (int argc, char** argv)
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, funcao_thread_1, NULL);
	pthread_join(t1, NULL);
	pthread_create(&t2, NULL, funcao_thread_2, NULL);
	pthread_join(t2, NULL);
	return 0;
}
```
	Serão criadas 2 threads, porém, a thread t1 acabará e, só após isso, a thread t2 será criada e terminada no fim do código. Portanto, elas não coexistem.

3. Apresente as características e utilidades das seguintes funções:

(a) `pthread_setcancelstate()`

	Essa função habilita ou desabilita o estado de "cancelamento" de uma thread. Quando está desabilitado, um pedido de cancelamento da thread ficará em espera e não funcionará até que o estado de cancelamento da thread esteja habilitado. Quando isso ocorre, o tipo de cancelamento é dado pela função `pthread_setcanceltype()`.

(b) `pthread_setcanceltype()`

	O tipo de cancelamento de uma thread pode ser assíncrono (asynchronous) ou diferido (deferred). O tipo assíncrono significa que o cancelamento pode ocorrer a qualquer momento, idealmente, ele ocorre imediatamente, porém, não há como o sistema garantir isso. Já no tipo diferido, o cancelamento será adiado até que a thread chame uma função que é um ponto de cancelamento.

(DICA: elas são relacionadas à função pthread_cancel().)
