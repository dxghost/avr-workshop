#define F_CPU	8000000UL	//--- CPU Clock Frequency

#include<avr/io.h>
#include<util/delay.h>
#include<stdio.h>

int main(void)
{
 
	unsigned int counter = 0;
	int value = 0b00000001;
	int direction = 1;
	int coefficient = 0;
	DDRB=0xFF;
    while (1) 
    {
		coefficient=PINA;
		PORTB=value;
		counter+=direction;
		if(direction==1){
			value = value<<1;
		}else{
			value=value>>1;
		}
		while(coefficient--){
			_delay_ms(30);
		}
		if(counter == 7){
			direction = -1;
		}else if(counter==0){
			direction = 1;
		}
		
    }
}

