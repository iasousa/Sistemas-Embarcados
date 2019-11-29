#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>

#define LED 7

int main()
{
	wiringPiSetup();
	pinMode(LED, OUTPUT);

	while(1)
	{
		digitalWrite(LED, HIGH);
		usleep(500000);
		digitalWrite(LED, LOW);
		usleep(500000);
	}

	return 0;
}
