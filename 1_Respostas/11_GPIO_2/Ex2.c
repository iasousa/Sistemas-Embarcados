#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>

#define LED 7

int main()
{
	float freq = 1, tempo = 0;

	wiringPiSetup();
	pinMode(LED, OUTPUT);

	printf("Digite a frequencia desejada em Hz:\n");
	scanf("%f", &freq);
	
	tempo = 1000000/(2*freq);

	while(1)
	{
		digitalWrite(LED, HIGH);
		usleep(tempo);
		digitalWrite(LED, LOW);
		usleep(tempo);
	}

	return 0;
}

