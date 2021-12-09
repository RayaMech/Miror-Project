#include <avr/io.h>			// for the input/output register
#include <util/delay.h>  	// for the _delay_ms


void init_led(void)
{
	DDRB=0x03;
	PORTB=0x00;
}


int main(void)
{
	init_led();
	while(1)
	{
		PORTB=0x01;
		_delay_ms(200);
		PORTB=0x02;
		_delay_ms(300);
	}

	return 0;
}
