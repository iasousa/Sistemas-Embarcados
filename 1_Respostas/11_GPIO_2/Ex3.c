#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>
#include <signal.h>

#define LED 7
#define BOTAO 2

int main()
{
	int freq = 1;
	float tempo;
	pid_t child_pid;
	
	wiringPiSetup();
	pinMode(BOTAO, INPUT);
	pinMode(LED, OUTPUT);
	
	while(1)
	{
		tempo = 1000000/(2*freq);
		child_pid = fork();
		if(child_pid == 0)
		{
			while(1)
			{
				digitalWrite(LED, HIGH);
				usleep(tempo);
				digitalWrite(LED, LOW);
				usleep(tempo);
			}
		} else {
			while(digitalRead(BOTAO) > 0);
			freq = freq * 2;
			if(freq > 64)
			{
				freq = 1;
			}
			kill(child_pid, SIGKILL);
			while(digitalRead(BOTAO) == 0);
			usleep(300000);
		}
	}
	
	return 0;
}
