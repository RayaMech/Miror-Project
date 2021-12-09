#include <avr/io.h>			// for the input/output register
#include <avr/interrupt.h> 	
#include <util/delay.h>  	// for the _delay_ms
#include "RGB_setup.h"

#define PRESCALER	1024
#define TIME_SLOT
#define NB_TICK		1562
#define BAUDRATE	103 // UBRR value for 9600

#define SAVE_CONTEXT()  \
	asm volatile ( \
		"push	r0				\n\t" \
		"in	r0, __SREG__			\n\t" \
		"cli 					\n\t" \
		"push	r0				\n\t" \
		"push	r1				\n\t" \
		"clr 	r1				\n\t" \
		"push	r2				\n\t" \
		"push	r3				\n\t" \
		"push	r4				\n\t" \
		"push	r5				\n\t" \
		"push	r6				\n\t" \
		"push	r7				\n\t" \
		"push	r8				\n\t" \
		"push	r9				\n\t" \
		"push	r10				\n\t" \
		"push	r11				\n\t" \
		"push	r12				\n\t" \
		"push	r13				\n\t" \
		"push	r14				\n\t" \
		"push	r15				\n\t" \
		"push	r16				\n\t" \
		"push	r17				\n\t" \
		"push	r18				\n\t" \
		"push	r19				\n\t" \
		"push	r20				\n\t" \
		"push	r21				\n\t" \
		"push	r22				\n\t" \
		"push	r23				\n\t" \
		"push	r24				\n\t" \
		"push	r25				\n\t" \
		"push	r26				\n\t" \
		"push	r27				\n\t" \
		"push	r28				\n\t" \
		"push	r29				\n\t" \
		"push	r30				\n\t" \
		"push 	r31 				\n\t" \
	);

#define RESTORE_CONTEXT() \
	asm volatile ( \
		"pop 	r31				\n\t" \
		"pop 	r30				\n\t" \
		"pop 	r29				\n\t" \
		"pop 	r28				\n\t" \
		"pop 	r27				\n\t" \
		"pop 	r26				\n\t" \
		"pop 	r25				\n\t" \
		"pop 	r24				\n\t" \
		"pop 	r23				\n\t" \
		"pop 	r22				\n\t" \
		"pop 	r21				\n\t" \
		"pop 	r20				\n\t" \
		"pop 	r19				\n\t" \
		"pop 	r18				\n\t" \
		"pop 	r17				\n\t" \
		"pop 	r16				\n\t" \
		"pop 	r15				\n\t" \
		"pop 	r14				\n\t" \
		"pop 	r13				\n\t" \
		"pop 	r12				\n\t" \
		"pop 	r11				\n\t" \
		"pop 	r10				\n\t" \
		"pop 	r9				\n\t" \
		"pop 	r8				\n\t" \
		"pop 	r7				\n\t" \
		"pop 	r6				\n\t" \
		"pop 	r5				\n\t" \
		"pop 	r4				\n\t" \
		"pop 	r3				\n\t" \
		"pop 	r2				\n\t" \
		"pop 	r1				\n\t" \
		"pop 	r0				\n\t" \
	);

typedef struct
{
	uint16_t pile;
	void (*function)(void);
	int (*function2)(void);
} processus ;

int CURRENT=0;

void init_serial(void)
{
	/* ACHTUNG : we suppose UBRR value < 0xff */
	/* Not true in all case */
	uint8_t baudrate = BAUDRATE;
	/* Set baud rate */
	UBRR0H = 0;
	UBRR0L = baudrate;

	/* Enable transmitter */
	UCSR0B = (1<<TXEN0);

	/* Set frame format */
	UCSR0C = 0x06;
}


void send_serial(unsigned char c)
{
	loop_until_bit_is_set(UCSR0A, UDRE0);
	UDR0 = c;
}


void init_task_led_red(void)
{
	DDRB|=0x01;
}


void init_timer()
{
	TCCR1B |= _BV(WGM12); // CTC mode with value in OCR1A 
	TCCR1B |= _BV(CS12);  // CS12 = 1; CS11 = 0; CS10 =1 => CLK/1024 prescaler
	TCCR1B |= _BV(CS10);
	OCR1A   = NB_TICK;
	TIMSK1 |= _BV(OCIE1A);
}


void task_led_red(void)
{
	PORTB ^= 0x01;
	_delay_ms(300);
}

void task_send_serial(void)
{
	send_serial('x');
	_delay_ms(100);
}

/* Fonction qui détermine la prochaine tâche a exécuter */
void scheduler()
{
	if (CURRENT <2)
		CURRENT++;
	else
		CURRENT=0;	
}

ISR(TIMER1_COMPA_vect)
{
	SAVE_CONTEXT();
	
	RESTORE_CONTEXT();
}

void init_tableau(processus Tproc[])
{
	Tproc[0].pile=0x0500;
	Tproc[1].pile=0x0600;
	Tproc[2].pile=0x0700;
	Tproc[0].function=&task_led_red;
	Tproc[1].function=&task_send_serial;
	Tproc[2].function2=&rgb_main;
}



int main(void)
{
	processus Tproc[2];
	init_tableau(Tproc);
	
	init_serial();
	init_task_led_red();
	init_timer();
	init_rgb();
	while(1)
	{
		task_led_red();
		task_send_serial();
		rgb_main();
	}

	return 0;
}
