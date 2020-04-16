/*	Author: dpere048
 *  Partner(s) Name: 
 *	Lab Section: 021
 *	Assignment: Lab #2  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; //CONFIGURE PORT A 8PINS AS INPUTS
	DDRC = 0xFF; PORTC = 0x00; //CONFIGURE PORT c 8 pins as outputs, initialize to 0s
	unsigned char available = 0x00; //temp var to hold spaces available
	unsigned char tmpA = 0x00; //tmp var to hold value of A
    /* Insert your solution below */
    while (1) {
	tmpA = PINA;
	unsigned char available = 0x04;
	if (tmpA&0x01){
	available--;
	}
	if (tmpA&0x02){
	available--;
	}
	if (tmpA&0x04){
	available--;
	}
	if (tmpA&0x08){
	available--;
	}
	PORTC = available;
	if(available == 0x00){
	PORTC = 0x80; //sets PC7 to 1 indicating lot is full
	}
    }
    return 1;
}


