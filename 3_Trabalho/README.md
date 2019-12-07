# Estacionamento Automático
Para utilização dos códigos dessa pasta, é preciso:

1. Instalar o openalpr para reconhecimento de placas de automóveis pelo link https://github.com/openalpr/openalpr

2. Instalar o fswebcam digitando "sudo apt install fswebcam" no terminal da Raspberry Pi. Esse recurso é utilizado para tirar fotos com a câmera conectada a uma das portas USB da Raspberry

3. Instalar a biblioteca tgbot-cpp pelo link https://github.com/reo7sp/tgbot-cpp. Essa biblioteca é responsável pelos comandos do bot do telegram na linguagem C++

4. Instalar, se necessário, a biblioteca wiringPi para controle dos pinos GPIO da Raspberry Pi pelo link http://wiringpi.com/download-and-install/ ou simplesmente digitando "sudo apt-get install wiringpi" no terminal da Raspberry

5. Compilar o código "estacionamento.c" no seguinte padrão: gcc estacionamento.c -o nome_do_executavel -lwiringPi

6. Compilar o código "cadastro.cpp" no seguinte padrão: g++ cadastro.cpp -o nome_do_executavel --std=c++11 -I/usr/local/include -lTgBot -lboost_system -lssl -lcrypto -lpthread

Os códigos se comunicam com um banco de dados presentes em um servidor por meio da linguagem SQL. No caso, foi utilizado o MariaDB Server: https://mariadb.org/


