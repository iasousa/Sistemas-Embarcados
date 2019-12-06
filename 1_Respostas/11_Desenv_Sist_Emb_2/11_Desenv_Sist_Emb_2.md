1. Defina qual modelo de Raspberry Pi você utilizará no projeto desta disciplina com o Raspberry Pi. Justifique sua escolha.

Será utilizada a Raspberry Pi B por conta da sua razoável capacidade de processamento de informações, conexão WiFi e portas USB. Esses itens são necessários ao projeto, pois é preciso de poder de processamento para realizar o reconhecimento de placas de automóveis, conexão wireless para comunicação via protocolo TCP/IP e porta USB para conexão da camêra.

2. Defina qual sistema operacional você utilizará no projeto desta disciplina com o Raspberry Pi. Justifique sua escolha.

Será utilizado o Raspbian porque esse sistema operacional tem compatibilidade com todos os recursos que serão utilizados no projeto (linguagens de programação e bibliotecas).

3. Defina de qual forma você instalará o sistema operacional escolhido. Escreva o passo-a-passo da instalação e forneça os links necessários para isto.

1) Baixar o Raspbian pelo site https://www.raspberrypi.org/downloads/raspbian/

2) Baixar o software balenaEtcher pelo site https://www.balena.io/etcher/ para criar um cartão SD bootável

3) Conectar o cartão SD ao computador que tem a imagem baixada no passo 1 e o programa baixado no passo 2

4) Abrir o balenaEtcher e selecionar a imagem baixada no passo 1, assim como o cartão SD no qual será instalada essa imagem

5) Clicar em "Flash!" e aguardar o término da instalação do sistema operacional no cartão SD

6) Inserir o cartão SD na Raspberry Pi. Quando a Raspberry for conectada à energia, o sistema operacional será iniciado automaticamente.

4. Defina de qual forma você desenvolverá software para o Raspberry Pi no projeto desta disciplina. Escreva o passo-a-passo do desenvolvimento e forneça os links necessários para isto.

1) Instalar o MariaDB Server para criar um servidor para o banco de dados que será manipulado através da linguagem SQL. Site do MariaDB: https://mariadb.org/

2) Criar uma tabela com dados dos moradores e outra com dados dos seus veículos em linguagem SQL

3) Instalar o openalpr para reconhecimento de placas de automóveis pelo link https://github.com/openalpr/openalpr

4) Instalar o fswebcam digitando "sudo apt install fswebcam" no terminal da Raspberry Pi. Esse recurso será utilizado para tirar fotos com a câmera conectada a uma das portas USB da Raspberry

5) Fazer o código que relaciona todos os itens anteriores na linguagem de programação C: o usuário pressiona um botão conectado a um pino GPIO da Raspberry Pi acionando a câmera pelo fswebcam para tirar foto de uma placa de carro, essa foto passa pelo openalpr, o qual faz o reconhecimento da placa e a saída do programa openalpr é comparada às placas presentes no banco de dados. Caso a placa reconhecida pelo openalpr esteja no banco de dados, a Raspberry envia a mensagem "ABRIR" por protocolo TCP/IP para um computador e, caso a placa não esteja no banco de dados, a Raspberry envia a mensagem "NAO ABRIR" pelo mesmo protocolo

6) Criar um bot no Telegram para realização de cadastros no banco de dados pelo aplicativo

7) Fazer o código que relaciona o bot do Telegram com o banco de dados na linguagem C++. Esse bot será utilizado pelo administrador para realizar os cadastros dos moradores. Esses cadastros serão salvos no banco de dados presente na Raspberry
