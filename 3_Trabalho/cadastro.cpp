#include <stdio.h>
#include <stdlib.h>
#include <tgbot/tgbot.h>

    FILE *fp;
    char nome[100], placa[8], modelo[50], ano[5], apartamento[4];
    int cnt = 0;
    bool cadastro = 0, morador = 0, senha = 0;
    
int main() {
    TgBot::Bot bot("1012220853:AAEjb31ZqEdUaAvUVVIDy68LAlgx287BMc0");
    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Digite a senha no formato /SENHA para iniciar o cadastro.");
    });

    bot.getEvents().onCommand("123456789", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Senha Correta! Agora, digite /morador para cadastrar um novo morador ou /veiculo para registrar um veículo de um morador já cadastrado.");
	senha = 1;
    });
    
    bot.getEvents().onCommand("morador", [&bot](TgBot::Message::Ptr message) {
	if(senha)
	{
		bot.getApi().sendMessage(message->chat->id, "Digite os dados para o cadastro, um por vez, na seguinte ordem: NOME COMPLETO, APARTAMENTO, PLACA DO CARRO, MODELO, ANO.");
		cadastro = 1;
		cnt = 0;
		morador = 1;
	} else{
		bot.getApi().sendMessage(message->chat->id, "Digite a senha no formato /SENHA para habilitar o cadastro.");
	}
    });
    
    bot.getEvents().onCommand("veiculo", [&bot](TgBot::Message::Ptr message) {
	if(senha)
	{
		bot.getApi().sendMessage(message->chat->id, "Digite os dados para o cadastro, um por vez, na seguinte ordem: APARTAMENTO, PLACA DO CARRO, MODELO, ANO.");
		cadastro = 1;
		cnt = 1;
		morador = 0;
	} else{
		bot.getApi().sendMessage(message->chat->id, "Digite a senha no formato /SENHA para habilitar o cadastro.");
	}
    });

    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
		printf("User wrote %s\n", message->text.c_str());
		if(cadastro){
			if(cnt == 0){
				sprintf(nome, "%s", message->text.c_str());
				printf("Nome = %s\n", nome);
			} else if(cnt == 1){
				sprintf(apartamento, "%s", message->text.c_str());
				printf("Apartamento = %s\n", apartamento);
			} else if(cnt == 2){
				sprintf(placa, "%s", message->text.c_str());
				printf("Placa = %s\n", placa);
			} else if(cnt == 3){
				sprintf(modelo, "%s", message->text.c_str());
				printf("Modelo = %s\n", modelo);
			} else{
				sprintf(ano, "%s", message->text.c_str());
				printf("Ano = %s\n", ano);
				fp = fopen("cadastro.sql", "w");
				if(morador)
				{
					fprintf(fp, "INSERT INTO moradores(nome, apartamento) VALUES('%s', '%s');\n", nome, apartamento);
				}
				fprintf(fp, "INSERT INTO veiculos(placa, modelo, ano, proprietario) VALUES('%s', '%s', '%s', '%s');\n", placa, modelo, ano, apartamento);
				fclose(fp);
				system("mysql estacionamento < cadastro.sql");
				cadastro = 0;
				senha = 0;
			}
			cnt++;
		}
        if (StringTools::startsWith(message->text, "/start")) {
            return;
        }
    });
	
    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }
    return 0;
}
