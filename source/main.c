/*	Author: dpere048
 *  Partner(s) Name: 
 *	Lab Section: 021
 *	Assignment: Lab #2  Exercise #1
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
	DDRB = 0xFF; PORTB = 0x00; //CONFIGURE PORT B 8 pins as outputs, initialize to 0s
	unsigned char tmpB = 0x00; //temp var to hold value of B
	unsigned char tmpA = 0x00; //tmp var to hold value of A
    /* Insert your solution below */
    while (1) {
	tmpA = PINA&0x01;
	if (tmpA == 0x01){
		tmpB = (tmpB & 0xFC) | 0x01; //tmpB = bbbbbb01
					//clears rightmost 2 bits, sets to 01
	}else{
		tmpB = (tmpB &0xFC) | 0x02; //bbbbbb10
					//clear right 2 bits, set to 10
	}
 
	PORTB = tmpB;
    }
    return 1;
}


